#include "Schedule_Persist.h"
#include "../Service/Schedule.h"
#include "../Common/List.h"
#include "EntityKey_Persist.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>

static const char SCHEDULE_DATA_FILE[] = "Schedule.dat";
static const char SCHEDULE_DATA_TEMP_FILE[] = "ScheduleTmp.dat";
static const char SCHEDULE_KEY_NAME[]="Schedule";

int Schedule_Perst_Insert(schedule_t *data){
	assert(NULL != data);
	FILE *fp = fopen(SCHEDULE_DATA_FILE, "ab");
	if (fp == NULL) {
		printf("不能打开文件%s!\n", SCHEDULE_DATA_FILE);
		return 0;
	}
	data->id = EntKey_Perst_GetNewKeys(SCHEDULE_KEY_NAME, 1);
	int rtn = fwrite(data, sizeof(schedule_t), 1, fp);
	fclose(fp);
	return rtn;
}

int Schedule_Perst_Update(schedule_t *data){
	assert(NULL != data);
	FILE *fp = fopen(SCHEDULE_DATA_FILE, "rb+");
	if (NULL == fp) {
		printf("不能打开文件%s!\n", SCHEDULE_DATA_FILE);
		return 0;
	}
	schedule_t buf;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&buf, sizeof(schedule_t), 1, fp)) {
			if (buf.id == data->id) {
				fseek(fp, -sizeof(schedule_t), SEEK_CUR);
				fwrite(data, sizeof(schedule_t), 1, fp);
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	return found;
}

int Schedule_Perst_RemByID(int ID){
	int found = 0;
	if (rename(SCHEDULE_DATA_FILE, SCHEDULE_DATA_TEMP_FILE) < 0) {
		printf("不能重命名文件%s!\n", SCHEDULE_DATA_FILE);
		return 0;
	}
	FILE *fpSour, *fpTarg;
	fpSour = fopen(SCHEDULE_DATA_TEMP_FILE, "rb");
	fpTarg = fopen(SCHEDULE_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("不能打开文件%s!\n", SCHEDULE_DATA_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("不能打开文件%s!\n", SCHEDULE_DATA_TEMP_FILE);
		return 0;
	}
	schedule_t buf;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(schedule_t), 1, fpSour)) {
			if (ID == buf.id) {
				found++;
				continue;
			}
			fwrite(&buf, sizeof(schedule_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	if (remove(SCHEDULE_DATA_TEMP_FILE) == -1) {
        printf("删除文件失败!\n");
        return 0;
	}
	return found;
}

int Schedule_Perst_SelectByID(int ID, schedule_t *buf){
	assert(NULL!=buf);
	FILE *fp = fopen(SCHEDULE_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}
	schedule_t data;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(schedule_t), 1, fp)) {
			if (ID == data.id) {
				*buf = data;
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	return found;
}

int Schedule_Perst_SelectAll(schedule_list_t list){
	schedule_node_t *newNode;
	schedule_t data;
	int recCount = 0;
	assert(NULL!=list);
	//文件不存在
	if (access(SCHEDULE_DATA_FILE, 0))
		return 0;
	List_Free(list, schedule_node_t);
	FILE *fp = fopen(SCHEDULE_DATA_FILE, "rb");
	if (NULL == fp) //文件不存在
        return 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(schedule_t), 1, fp)) {
			newNode = (schedule_node_t*) malloc(sizeof(schedule_node_t));
			if (!newNode) {
				printf("警告,内存溢出! ! !\n无法将更多数据载入内存!!\n");
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

int Schedule_Perst_SelectByPlay(schedule_list_t list, int play_id){
	int recCount = 0;
	FILE *fp = fopen(SCHEDULE_DATA_FILE, "rb");
	if (fp == NULL) {
		fp = fopen(SCHEDULE_DATA_FILE, "wb");
		return 0;
	}
	schedule_t data;
	List_Free(list, schedule_node_t);
	while (!feof(fp)) {
		if (fread(&data, sizeof(schedule_t), 1, fp))
			if (play_id == data.play_id) {
				schedule_node_t *newNode = (schedule_node_t *) malloc(sizeof(schedule_node_t));
				if (!newNode) {
					printf("警告,内存溢出! ! !\n无法将更多数据载入内存!!!\n");
					printf("请键入任意键返回!\n");
					fflush(stdin);
					getchar();
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
