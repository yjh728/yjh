/*
 *  Seat_UI.c
 *
 *  Created on: 2015年5月23日
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
		printf("该放映厅不存在!\n按[Enter]键返回!\n");
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
		printf("********************  放映厅 %d 座位列表  **************************\n",
				roomID);
		printf("%5c", ' ');
		for (i = 1; i <= studioRec.colsCount; i++) {
			printf("%3d", i);
		}
		printf("\n------------------------------------------------------------------\n");
		for (i = 1; i <= studioRec.rowsCount; i++) {
			j = 1;
			printf("%d行:%c", i, ' ');

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

		printf("[A]添加|[D]删除|[U]修改|[R]返回:");
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
		printf("***********************  添加新座位  ***************************\n");//Add New Seat
		printf("------------------------------------------------------------------\n");
		do {
			printf("排数不应超出 %d 列数不应超出 %d!\n",row, column);
			printf("座位排数:");
			scanf("%d", &(rec.row));
            fflush(stdin);
            printf("座位列数:");
			scanf("%d", &(rec.column));
            fflush(stdin);
		} while (rec.row > row || rec.column > column);

		p = Seat_Srv_FindByRowCol(list, rec.row, rec.column);
		if (p) {
			printf("该座位已存在 \n");
			continue;
		}
		rec.roomID = roomID;
		rec.status = SEAT_GOOD;
		printf("==================================================================\n");
		if (Seat_Srv_Add(&rec)) {
			newRecCount++;
			printf("新座位添加成功\n");
			p = (seat_node_t*) malloc(sizeof(seat_node_t));
			p->data = rec;
			Seat_Srv_AddToSoftedList(list, p);
		} else
			printf("新座位添加失败!\n");
		printf(
				"------------------------------------------------------------------\n");
		printf("[A]添加更多, [R]返回:");
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
			"***************************  修改座位 ************************\n");
	printf(
			"------------------------------------------------------------------\n");

	do {
		do {
			printf(
					"排数不应超出 %d 列数不应超出 %d!\n",
					row, column);
			printf("座位排数 :");
			scanf("%d", &newrow);
            fflush(stdin);
			printf("座位列数 :");
			scanf("%d", &newcolumn);
            fflush(stdin);
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {
			printf("座位情况 [%d,%d]: [%c]:", newrow, newcolumn,Seat_UI_Status2Char(p->data.status));
			p->data.status = Seat_UI_Char2Status(getchar());
			printf("-------------------------------------------------------------------\n");
			if (Seat_Srv_Modify(&(p->data))) {
				rtn = 1;
				printf("该座位更新成功!\n");
			} else
				printf("该座位更新失败!\n");
		} else
			printf("The seat is not exist!\n");
		printf(
				"-------------------------------------------------------------------\n");
		printf("[U]修改更多, [R]返回:");
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
		printf("**************************  删除座位  ************************\n");//Delete  Seat
		printf("------------------------------------------------------------------\n");
		do {
			printf("排数不应超出 %d 列数不应超出 %d!\n",row, column);
			printf("座位排数:");
			scanf("%d", &(newrow));
            fflush(stdin);
			printf("座位列数:");
			scanf("%d", &(newcolumn));
            fflush(stdin);
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {
			printf("==================================================================\n");
			if (Seat_Srv_DeleteByID(p->data.id)) {
				printf("该座位删除成功!\n");
				delSeatCount++;
				List_FreeNode(p);
			}
		} else {
			printf("该座位不存在!\n");

		}
		printf("------------------------------------------------------------------\n");
		printf("[D]删除更多, [R]返回:");
		scanf("%c", &choice);
        fflush(stdin);
	} while ('d' == choice || 'D' == choice);
	return delSeatCount;
}

