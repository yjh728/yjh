#include "Studio_Persist.h"
#include "../Service/Studio.h"
#include "EntityKey_Persist.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>

static const char STUDIO_DATA_FILE[] = "Studio.dat";
static const char STUDIO_DATA_TEMP_FILE[] = "StudioTmp.dat";
static const char STUDIO_KEY_NAME[] = "Studio";

int Studio_Perst_Insert(studio_t *data) {
	assert(NULL!=data);
	long key = EntKey_Perst_GetNewKeys(STUDIO_KEY_NAME, 1);
	if(key<=0)
		return 0;
	data->id = key;
	FILE *fp = fopen(STUDIO_DATA_FILE, "ab");
	int rtn = 0;
	if (NULL == fp) {
		printf("不能打开文件%s!\n", STUDIO_DATA_FILE);
		return 0;
	}
	rtn = fwrite(data, sizeof(studio_t), 1, fp);
	fclose(fp);
	return rtn;
}

int Studio_Perst_Update(const studio_t * data) {
	assert(NULL!=data);
	FILE *fp = fopen(STUDIO_DATA_FILE, "rb+");
	if (NULL == fp) {
		printf("不能打开文件%s!\n", STUDIO_DATA_FILE);
		return 0;
	}
	studio_t buf;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&buf, sizeof(studio_t), 1, fp)) {
			if (buf.id == data->id) {
				fseek(fp, -((int)sizeof(studio_t)), SEEK_CUR);
				fwrite(data, sizeof(studio_t), 1, fp);
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	return found;
}

int Studio_Perst_DeleteByID(int ID) {
	if(rename(STUDIO_DATA_FILE, STUDIO_DATA_TEMP_FILE)<0){
		printf("不能重命名文件%s!\n", STUDIO_DATA_FILE);
		return 0;
	}
	FILE *fpSour, *fpTarg;
	fpSour = fopen(STUDIO_DATA_TEMP_FILE, "rb");
	if (NULL == fpSour ){
		printf("不能打开文件%s!\n", STUDIO_DATA_FILE);
		return 0;
	}
	fpTarg = fopen(STUDIO_DATA_FILE, "wb");
	if ( NULL == fpTarg ) {
		printf("不能打开文件%s!\n", STUDIO_DATA_TEMP_FILE);
		return 0;
	}
	studio_t buf;
	int found = 0;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(studio_t), 1, fpSour)) {
			if (ID == buf.id) {
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(studio_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	remove(STUDIO_DATA_TEMP_FILE);
	return found;
}

int Studio_Perst_SelectByID(int ID, studio_t *buf) {
	assert(NULL!=buf);
	FILE *fp = fopen(STUDIO_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}
	studio_t data;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(studio_t), 1, fp)) {
			if (ID == data.id) {
				*buf = data;
				found = 1;
				break;
			};
		}
	}
	fclose(fp);
	return found;
}

int Studio_Perst_SelectAll(studio_list_t list) {
	studio_node_t *newNode;
	studio_t data;
	int recCount = 0;
	assert(NULL!=list);
	List_Free(list, studio_node_t);
	FILE *fp = fopen(STUDIO_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}
	while (!feof(fp)) {
		if (fread(&data, sizeof(studio_t), 1, fp)) {
			newNode = (studio_node_t*) malloc(sizeof(studio_node_t));
			if (!newNode) {
				printf("警告,内存溢出! ! !\n无法将更多数据载入内存!!!\n");
				break;
			}
			newNode->data = data;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	fclose(fp);
	return recCount;
}
