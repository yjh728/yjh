/*
 * Account_Persist.c
 *
 *  Created on: 2015��5��8��
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
//�ж��˺��ļ��Ƿ���ڣ�����1���ڣ�����0������
int Account_Perst_CheckAccFile() {
    FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb");
    if (fp == NULL)
        return 0;
    fclose(fp);
	return 1;
}

//�����û��������˺�,����ɹ� return 1������ return 0
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

//���˺�д���˺��ļ��У�����ʵ��д������ݿ���Ŀ
int Account_Perst_Insert(account_t *data) {
	FILE *fp = fopen(ACCOUNT_DATA_FILE, "ab");
	int rtn = 0;
	if (NULL == fp) {
		printf("���ܴ��ļ�%s!\n", ACCOUNT_DATA_FILE);
		return rtn;
	} else {
	    data->id = EntKey_Perst_GetNewKeys(ACCOUNT_KEY_NAME, 1);
		rtn = fwrite(data, sizeof(account_t), 1, fp);
	}
	fclose(fp);
	return rtn;
}

//���˺��ļ��в���������˺�ƥ����˺ţ��ҵ� return 1������ return 0�������и�����д
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

//���˺��ļ���ɾ�������idƥ����˺ţ�ɾ���ɹ� return 1������ return 0��
int Account_Perst_DeleteByID(int id) {
	int found = 0;
    if (rename(ACCOUNT_DATA_FILE, ACCOUNT_DATA_TEMP_FILE) < 0) {
        printf("�����������ļ�%s!\n", ACCOUNT_DATA_FILE);
		return 0;
    }
    FILE *fpSour, *fpTarg;
    fpSour = fopen(ACCOUNT_DATA_TEMP_FILE, "rb");
	fpTarg = fopen(ACCOUNT_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("���ܴ��ļ�%s!\n", ACCOUNT_DATA_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("���ܴ��ļ�%s!\n", ACCOUNT_DATA_TEMP_FILE);
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

//���˺��ļ��в��������idƥ����˺ţ���ͨ��ָ��buf������ƥ��ɹ� return 1������ return 0��
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

//������ACCOUNT_DATA_FILE�ļ�����̬�����û��˺�list����,list Ϊ����ͷָ�룬����list����
int Account_Perst_SelectAll(account_list_t list) {
	account_node_t *newNode;
	account_t data;
	int recCount = 0;
	assert(NULL!=list);
	//�ļ�������
	if (access(ACCOUNT_DATA_FILE, 0))
		return 0;
	List_Free(list, account_node_t);
	FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb");
	if (NULL == fp) //�ļ�������
		return 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(account_t), 1, fp)) {
			newNode = (account_node_t*) malloc(sizeof(account_node_t));
			if (!newNode) {
				printf("����,�ڴ����! ! !\n�޷����������������ڴ�!!\n");
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

