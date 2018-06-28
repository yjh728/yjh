#include "Play_Persist.h"
#include "../Service/Play.h"
#include "../Common/List.h"
#include "../Persistence/EntityKey_Persist.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>
#include <string.h>

static const char PLAY_DATA_FILE[] = "Play.dat";
static const char PLAY_DATA_TEMP_FILE[] = "PlayTmp.dat";
static const char PLAY_KEY_NAME[]="Play";

int Play_Perst_Insert(play_t *data) {
	FILE *fp = fopen(PLAY_DATA_FILE, "ab");
	int flag = 0;
	if (fp == NULL) {
        printf("打开文件%s失败!\n", PLAY_DATA_FILE);
        return flag;
	} else {
	    data->id = EntKey_Perst_GetNewKeys(PLAY_KEY_NAME, 1);
        flag = fwrite(data, sizeof(play_t), 1, fp);
        fclose(fp);
        return flag;
	}
}

int Play_Perst_Update(play_t *data) {
	int rtn = 0;
	FILE *fp = fopen(PLAY_DATA_FILE, "rb+");
	if (!fp) {
		printf("不能打开文件%s!\n", PLAY_DATA_FILE);
		return 0;
	}
    play_t buf;
    while (!feof(fp)) {
        if (fread(&buf, sizeof(play_t), 1, fp)) {
            if (buf.id == data->id) {
                fseek(fp, -sizeof(play_t), SEEK_CUR);
				fwrite(data, sizeof(play_t), 1, fp);
                rtn = 1;
                break;
            }
        }
	}
	fclose(fp);
	return rtn;
}

int Play_Perst_RemByID(int ID) {
	//将原始文件重命名，然后读取数据重新写入到数据文件中，并将要删除的实体过滤掉。
	//借助辅助文件，实现记录删除
    int found = 0;
    if (rename(PLAY_DATA_FILE, PLAY_DATA_TEMP_FILE) < 0) {
        printf("不能重命名%s!\n", PLAY_DATA_FILE);
		return 0;
    }
    FILE *fpSour, *fpTarg;
    fpSour = fopen(PLAY_DATA_TEMP_FILE, "rb");
	fpTarg = fopen(PLAY_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("不能打开文件%s!\n", PLAY_DATA_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("不能打开文件%s!\n", PLAY_DATA_TEMP_FILE);
		return 0;
	}
	play_t buf;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(play_t), 1, fpSour)) {
			if (ID == buf.id) {
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(play_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	remove(PLAY_DATA_TEMP_FILE);
    return found;
}

int Play_Perst_SelectByID(int ID, play_t *buf) {
	assert(NULL!=buf);
	FILE *fp = fopen(PLAY_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}
	play_t data;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(play_t), 1, fp)) {
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

int Play_Perst_SelectAll(play_list_t list) {
    play_node_t *newNode;
	play_t data;
	int recCount = 0;
	assert(NULL!=list);
	//文件不存在
	if (access(PLAY_DATA_FILE, 0))
		return 0;
	List_Free(list, play_node_t);
	FILE *fp = fopen(PLAY_DATA_FILE, "rb+");
	if (NULL == fp) //文件不存在
		return 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(play_t), 1, fp)) {
			newNode = (play_node_t*) malloc(sizeof(play_node_t));
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

int Play_Perst_SelectByName(play_list_t list, char condt[]) {
    int recCount = 0;
    assert(NULL!=list);
    if (access(PLAY_DATA_FILE, 0))
		return 0;
    List_Free(list, play_node_t);
    FILE *fp = fopen(PLAY_DATA_FILE, "rb");
    if (fp == NULL)
        return 0;
    play_t data;
    play_node_t *newNode;
    while (!feof(fp)) {
        if (fread(&data, sizeof(play_t), 1, fp))  {
            if (strstr(data.name, condt)) {
                newNode = (play_node_t *) malloc(sizeof(play_node_t));
                if (!newNode) {
                    printf("警告,内存溢出! ! !\n无法将更多数据载入内存!!!\n");
                    break;
                }
                newNode->data = data;
                List_AddTail(list, newNode);
                recCount++;
            }
        }
    }
    return recCount;
}

