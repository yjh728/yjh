/*
 * Account_Persist.c
 *
 *  Created on: 2015年5月8日
 *      Author: Administrator
 */

#include "Account_Persist.h"
#include "../Service/account.h"
#include "../Common/List.h"
#include "EntityKey_Persist.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>
#include <string.h>

static const char ACCOUNT_DATA_FILE[] = "Account.dat";
static const char ACCOUNT_DATA_TEMP_FILE[] = "AccountTmp.dat";
static const char ACCOUNT_KEY_NAME[] = "Account";
//判断账号文件是否存在，返回1存在，返回0不存在
int Account_Perst_CheckAccFile() {
    FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb");
    if (fp == NULL)
        return 0;
    fclose(fp);
	return 1;
}

//根据用户名载入账号,载入成功 return 1；否则 return 0
int Account_Perst_SelByName(char usrName[], account_t *buf) {
	FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb");
	if (fp == NULL)
		return 0;
	account_t data;
	int found = 0;
	while (!feof(fp)) {
        if (fread(&data, sizeof(account_t), 1, fp))
            if (!strcmp(usrName, data.username)) {
                *buf = data;
                found = 1;
                break;
            }
	}
	fclose(fp);
	return found;
}

//新账号写入账号文件中，返回实际写入的数据块数目
int Account_Perst_Insert(account_t *data) {
	FILE *fp = fopen(ACCOUNT_DATA_FILE, "ab");
	int rtn = 0;
	if (NULL == fp) {
		printf("不能打开文件%s!\n", ACCOUNT_DATA_FILE);
		return rtn;
	} else {
	    data->id = EntKey_Perst_GetNewKeys(ACCOUNT_KEY_NAME, 1);
		rtn = fwrite(data, sizeof(account_t), 1, fp);
	}
	fclose(fp);
	return rtn;
}

//在账号文件中查找与参数账号匹配的账号，找到 return 1；否则 return 0；并进行覆盖重写
int Account_Perst_Update(const account_t * data) {
    int found = 0;
    FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb+");
    if (NULL == fp) {
		printf("Cannot open file %s!\n", ACCOUNT_DATA_FILE);
		return 0;
	}
	account_t buf;
	while (!feof(fp)) {
        if (fread(&buf, sizeof(account_t), 1, fp))
            if (buf.id == data->id) {
                fseek(fp, -sizeof(account_t), 1);
                fwrite(data, sizeof(account_t), 1, fp);
                found = 1;
                break;
            }
	}
	fclose(fp);
    return found;
}

//在账号文件中删除与参数id匹配的账号，删除成功 return 1；否则 return 0；
int Account_Perst_DeleteByID(int id) {
	int found = 0;
    if (rename(ACCOUNT_DATA_FILE, ACCOUNT_DATA_TEMP_FILE) < 0) {
        printf("不能重命名文件%s!\n", ACCOUNT_DATA_FILE);
		return 0;
    }
    FILE *fpSour, *fpTarg;
    fpSour = fopen(ACCOUNT_DATA_TEMP_FILE, "rb");
	fpTarg = fopen(ACCOUNT_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("不能打开文件%s!\n", ACCOUNT_DATA_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("不能打开文件%s!\n", ACCOUNT_DATA_TEMP_FILE);
		return 0;
	}
	account_t buf;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(account_t), 1, fpSour)) {
			if (id == buf.id) {
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(account_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	remove(ACCOUNT_DATA_TEMP_FILE);
    return found;
}

//在账号文件中查找与参数id匹配的账号，并通过指针buf传出；匹配成功 return 1；否则 return 0；
int Account_Perst_SelectByID(int id, account_t *buf) {
	int found = 0;
	if (rename(ACCOUNT_DATA_FILE, ACCOUNT_DATA_TEMP_FILE) < 0) {
		printf("Cannot rename file %s!\n", ACCOUNT_DATA_FILE);
		return 0;
	}
	FILE *fpSour, *fpTarg;
	fpSour = fopen(ACCOUNT_DATA_TEMP_FILE, "rb");
	fpTarg = fopen(ACCOUNT_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("Cannot open file %s!\n", ACCOUNT_DATA_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("Cannot open file %s!\n", ACCOUNT_DATA_TEMP_FILE);
		return 0;
	}
	account_t data;
	while (!feof(fpSour)) {
		if (fread(&data, sizeof(account_t), 1, fpSour)) {
			if (id == data.id) {
				found = 1;
				continue;
			}
			fwrite(buf, sizeof(account_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	remove(ACCOUNT_DATA_TEMP_FILE);
	return found;
}

//遍历读ACCOUNT_DATA_FILE文件，动态构建用户账号list链表,list 为链表头指针，返回list长度
int Account_Perst_SelectAll(account_list_t list) {
	account_node_t *newNode;
	account_t data;
	int recCount = 0;
	assert(NULL!=list);
	//文件不存在
	if (access(ACCOUNT_DATA_FILE, 0))
		return 0;
	List_Free(list, account_node_t);
	FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb");
	if (NULL == fp) //文件不存在
		return 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(account_t), 1, fp)) {
			newNode = (account_node_t*) malloc(sizeof(account_node_t));
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

