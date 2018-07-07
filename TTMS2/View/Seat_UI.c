/*
 *  Seat_UI.c
 *
 *  Created on: 2015��5��23��
 *  Author: lc
 */
#include "Seat_UI.h"

#include "../Service/Seat.h"
#include "../Service/Studio.h"
#include "../Common/List.h"
#include <stdio.h>

char Seat_UI_Status2Char(seat_status_t status) {
	char statusChar;
	switch (status) {
	case SEAT_GOOD:
		statusChar = '#';
		break;
	case SEAT_BROKEN:
		statusChar = '~';
		break;
	case SEAT_NONE:
	default:
		statusChar = ' ';
		break;
	}
	return statusChar;
}

seat_status_t Seat_UI_Char2Status(char statusChar) {
	seat_status_t status;
	switch (statusChar) {
	case '#':
		status = SEAT_GOOD;
		break;
	case '~':
		status = SEAT_BROKEN;
		break;
	default:
		status = SEAT_NONE;
		break;
	}
	return status;
}

void Seat_UI_MgtEntry(int roomID) {
    int i, j;
	char choice;
	int seatCount;
	int changedCount = 0;
	studio_t studioRec;

	if (!Studio_Srv_FetchByID(roomID, &studioRec)) {
		printf("�÷�ӳ��������!\n��[Enter]������!\n");
		getchar();
		return;
	}

	seat_list_t list;
	seat_node_t *p;

	List_Init(list, seat_node_t);
	seatCount = Seat_Srv_FetchByRoomID(list, roomID);

	if (!seatCount) {
		seatCount = Seat_Srv_RoomInit(list, roomID, studioRec.rowsCount,
				studioRec.colsCount);
		studioRec.seatsCount = seatCount;
		Studio_Srv_Modify(&studioRec);
	}
	do {

		system("cls");
		printf("\n==================================================================\n");
		printf("********************  ��ӳ�� %d ��λ�б�  **************************\n",
				roomID);
		printf("%5c", ' ');
		for (i = 1; i <= studioRec.colsCount; i++) {
			printf("%3d", i);
		}
		printf("\n------------------------------------------------------------------\n");
		for (i = 1; i <= studioRec.rowsCount; i++) {
			j = 1;
			printf("%d��:%c", i, ' ');

			List_ForEach(list,p)
			{
				if (p->data.row == i) {
					while (p->data.column != j) {
						printf("%3c", ' ');
						j++;
					}
					printf("%3c", Seat_UI_Status2Char(p->data.status));
					j++;
				}
			}
			printf("\n");
		}

		printf("[A]���|[D]ɾ��|[U]�޸�|[R]����:");
		scanf("%c", &choice);
        fflush(stdin);
		switch (choice) {
		case 'a':
		case 'A':
			changedCount = Seat_UI_Add(list, roomID, studioRec.rowsCount,
					studioRec.colsCount);
			if (changedCount > 0) {
				seatCount += changedCount;
				studioRec.seatsCount = seatCount;
				Studio_Srv_Modify(&studioRec);
			}
			break;
		case 'd':
		case 'D':
			changedCount = Seat_UI_Delete(list, studioRec.rowsCount,
					studioRec.colsCount);
			if (changedCount > 0) {
				seatCount -= changedCount;
				studioRec.seatsCount = seatCount;
				Studio_Srv_Modify(&studioRec);
			}
			break;
		case 'u':
		case 'U':
			Seat_UI_Modify(list, studioRec.rowsCount, studioRec.colsCount);
			break;
		}
	} while (choice != 'r' && choice != 'R');
	List_Destroy(list, seat_node_t);
}

int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {
	seat_t rec;
	seat_node_t *p;
	int newRecCount = 0;
	char choice;
	do {
		system("cls");
		printf("\n==================================================================\n");
		printf("***********************  �������λ  ***************************\n");//Add New Seat
		printf("------------------------------------------------------------------\n");
		do {
			printf("������Ӧ���� %d ������Ӧ���� %d!\n",row, column);
			printf("��λ����:");
			scanf("%d", &(rec.row));
            fflush(stdin);
            printf("��λ����:");
			scanf("%d", &(rec.column));
            fflush(stdin);
		} while (rec.row > row || rec.column > column);

		p = Seat_Srv_FindByRowCol(list, rec.row, rec.column);
		if (p) {
			printf("����λ�Ѵ��� \n");
			continue;
		}
		rec.roomID = roomID;
		rec.status = SEAT_GOOD;
		printf("==================================================================\n");
		if (Seat_Srv_Add(&rec)) {
			newRecCount++;
			printf("����λ��ӳɹ�\n");
			p = (seat_node_t*) malloc(sizeof(seat_node_t));
			p->data = rec;
			Seat_Srv_AddToSoftedList(list, p);
		} else
			printf("����λ���ʧ��!\n");
		printf(
				"------------------------------------------------------------------\n");
		printf("[A]��Ӹ���, [R]����:");
		scanf("%c", &choice);
        fflush(stdin);
	} while ('a' == choice || 'A' == choice);
	return newRecCount;
}

int Seat_UI_Modify(seat_list_t list, int row, int column) {
	int rtn = 0;
	int newrow, newcolumn;
	char choice;
	seat_node_t *p;
	system("cls");

	printf(
			"\n==================================================================\n");
	printf(
			"***************************  �޸���λ ************************\n");
	printf(
			"------------------------------------------------------------------\n");

	do {
		do {
			printf(
					"������Ӧ���� %d ������Ӧ���� %d!\n",
					row, column);
			printf("��λ���� :");
			scanf("%d", &newrow);
            fflush(stdin);
			printf("��λ���� :");
			scanf("%d", &newcolumn);
            fflush(stdin);
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {
			printf("��λ��� [%d,%d]: [%c]:", newrow, newcolumn,Seat_UI_Status2Char(p->data.status));
			p->data.status = Seat_UI_Char2Status(getchar());
			printf("-------------------------------------------------------------------\n");
			if (Seat_Srv_Modify(&(p->data))) {
				rtn = 1;
				printf("����λ���³ɹ�!\n");
			} else
				printf("����λ����ʧ��!\n");
		} else
			printf("The seat is not exist!\n");
		printf(
				"-------------------------------------------------------------------\n");
		printf("[U]�޸ĸ���, [R]����:");
		scanf("%c", &choice);
        fflush(stdin);
	} while ('u' == choice || 'U' == choice);
	return rtn;
}

int Seat_UI_Delete(seat_list_t list, int row, int column) {
	int delSeatCount = 0;
	int newrow, newcolumn;
	seat_node_t *p;
	char choice;
	do {
		system("cls");
		printf("\n==================================================================\n");
		printf("**************************  ɾ����λ  ************************\n");//Delete  Seat
		printf("------------------------------------------------------------------\n");
		do {
			printf("������Ӧ���� %d ������Ӧ���� %d!\n",row, column);
			printf("��λ����:");
			scanf("%d", &(newrow));
            fflush(stdin);
			printf("��λ����:");
			scanf("%d", &(newcolumn));
            fflush(stdin);
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {
			printf("==================================================================\n");
			if (Seat_Srv_DeleteByID(p->data.id)) {
				printf("����λɾ���ɹ�!\n");
				delSeatCount++;
				List_FreeNode(p);
			}
		} else {
			printf("����λ������!\n");

		}
		printf("------------------------------------------------------------------\n");
		printf("[D]ɾ������, [R]����:");
		scanf("%c", &choice);
        fflush(stdin);
	} while ('d' == choice || 'D' == choice);
	return delSeatCount;
}

