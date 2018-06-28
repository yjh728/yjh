/*
 *  Seat_Persist.c
 *
 *  Created on: 2015��5��23��
 *  Author: lc
 */

#include "Seat_Persist.h"
#include "../Service/Seat.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>

static const char SEAT_DATA_FILE[] = "Seat.dat";
static const char SEAT_DATA_TEMP_FILE[] = "SeatTmp.dat";
//��Ӷ���������ʶ����
static const char SEAT_KEY_NAME[] = "Seat";

int Seat_Perst_Insert(seat_t *data) {
	assert(NULL!=data);
	FILE *fp = fopen(SEAT_DATA_FILE, "ab");
	int rtn = 0;
	if (NULL == fp) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_FILE);
		return 0;
	}
    long key = EntKey_Perst_GetNewKeys(SEAT_KEY_NAME, 1);
	if(key<=0)			//��������ʧ�ܣ�ֱ�ӷ���
		return 0;
	data->id = key;
	rtn = fwrite(data, sizeof(seat_t), 1, fp);
	fclose(fp);
	return rtn;
}

int Seat_Perst_InsertBatch(seat_list_t list) {
	seat_node_t *p;
	assert(NULL!=list);
	int len = 0;
	List_ForEach(list, p) {
		len++;
	}
	long key = EntKey_Perst_GetNewKeys(SEAT_KEY_NAME, len);
	if (key<=0)
		return 0;
	FILE *fp = fopen(SEAT_DATA_FILE, "ab");
	int rtn = 0;
	if (NULL == fp) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_FILE);
		return 0;
	}
	List_ForEach(list,p) {
		p->data.id = key++;
		fwrite(&(p->data), sizeof(seat_t), 1, fp);
		rtn++;
	}
	fclose(fp);
	return rtn;
}

int Seat_Perst_Update(const seat_t *seatdata) {
	assert(NULL!=seatdata);
	FILE *fp = fopen(SEAT_DATA_FILE, "rb+");
	if (NULL == fp) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_FILE);
		return 0;
	}
	seat_t buf;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&buf, sizeof(seat_t), 1, fp)) {
			if (buf.id == seatdata->id) {
				fseek(fp, -sizeof(seat_t), SEEK_CUR);
				fwrite(seatdata, sizeof(seat_t), 1, fp);
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	return found;
}

int Seat_Perst_DeleteByID(int ID) {
	//��ԭʼ�ļ���������Ȼ���ȡ��������д�뵽�����ļ��У�����Ҫɾ����ʵ����˵���
	FILE *fpSour, *fpTarg;
	//��ԭʼ�����ļ�������
	if (rename(SEAT_DATA_FILE, SEAT_DATA_TEMP_FILE) < 0) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_FILE);
		return 0;
	}
	fpSour = fopen(SEAT_DATA_TEMP_FILE, "rb");
	fpTarg = fopen(SEAT_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_TEMP_FILE);
		return 0;
	}
	seat_t buf;
	int found = 0;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(seat_t), 1, fpSour)) {
			if (ID == buf.id) {
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(seat_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	//ɾ����ʱ�ļ�
	remove(SEAT_DATA_TEMP_FILE);
	return found;
}

int Seat_Perst_DeleteAllByRoomID(int roomID) {
	//��ԭʼ�ļ���������Ȼ���ȡ��������д�뵽�����ļ��У�����Ҫɾ����ʵ����˵���
	FILE *fpSour, *fpTarg;
	//��ԭʼ�����ļ�������
	if (rename(SEAT_DATA_FILE, SEAT_DATA_TEMP_FILE) < 0) {
		printf("�����������ļ�%s!\n", SEAT_DATA_FILE);
		return 0;
	}
	fpSour = fopen(SEAT_DATA_TEMP_FILE, "rb");
	fpTarg = fopen(SEAT_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("���ܴ��ļ�%s!\n", SEAT_DATA_TEMP_FILE);
		return 0;
	}
	seat_t buf;
	int found = 0;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(seat_t), 1, fpSour)) {
			if (roomID == buf.roomID) {
				found += 1;
				continue;
			}
			fwrite(&buf, sizeof(seat_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	//ɾ����ʱ�ļ�
	remove(SEAT_DATA_TEMP_FILE);
	return found;
}

int Seat_Perst_SelectByID(int ID, seat_t *buf) {
	assert(NULL!=buf);
	FILE *fp = fopen(SEAT_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}
	seat_t data;
	int found = 0;

	while (!feof(fp)) {
		if (fread(&data, sizeof(seat_t), 1, fp)) {
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

int Seat_Perst_SelectAll(seat_list_t list) {
	seat_node_t *newNode;
	seat_t data;
	int recCount = 0;
	assert(NULL!=list);
	//�ļ�������
	if (access(SEAT_DATA_FILE, 0))
		return 0;
	List_Free(list, seat_node_t);
	FILE *fp = fopen(SEAT_DATA_FILE, "rb");
	if (NULL == fp) //�ļ�������
		return 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(seat_t), 1, fp)) {
			newNode = (seat_node_t*) malloc(sizeof(seat_node_t));
			if (!newNode) {
				printf("����,�ڴ����! ! !\n�޷����������������ڴ�!!\n");
				break;
			}
			newNode->data = data;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	getchar();
	fclose(fp);
	return recCount;
}

int Seat_Perst_SelectByRoomID(seat_list_t list, int roomID) {
	seat_node_t *newNode;
	seat_t data;
	int recCount = 0;
	assert(NULL!=list);
	//�ļ�������
	if (access(SEAT_DATA_FILE, 0)) {
		return 0;
	}
	List_Free(list, seat_node_t);
	FILE *fp = fopen(SEAT_DATA_FILE, "rb");
	if (NULL == fp) { //�ļ�������
		return 0;
	}
	while (!feof(fp)) {
		if (fread(&data, sizeof(seat_t), 1, fp))
			if (data.roomID == roomID)  //����λ�Ǳ���ӳ������λ�������
			{
				newNode = (seat_node_t*) malloc(sizeof(seat_node_t));
				if (!newNode) {
					printf(
							"����,�ڴ����! ! !\n�޷����������������ڴ�!!!\n");
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
