/*
 *  Seat.c
 *
 *  Created on: 2015年6月12日
 *  Author: lc
 */
#include <stdlib.h>
#include "../Common/List.h"
#include "Seat.h"
#include "../Persistence/Seat_Persist.h"
#include <stdio.h>

int Seat_Srv_Add(seat_t *data) {	////新方案将data前面的const去掉
    return Seat_Perst_Insert(data);
}

int Seat_Srv_AddBatch(seat_list_t list) {
	return 0;
}

int Seat_Srv_Modify(const seat_t *data) {
    return Seat_Perst_Update(data);
}

int Seat_Srv_DeleteByID(int ID) {
    return Seat_Perst_DeleteByID(ID);
}

int Seat_Srv_FetchByID(int ID, seat_t *buf) {
    return Seat_Perst_SelectByID(ID, buf);
}

int Seat_Srv_DeleteAllByRoomID(int roomID) {
    return Seat_Perst_DeleteAllByRoomID(roomID);
}

//根据演出厅ID载入座位
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID) {
	int SeatCount = Seat_Perst_SelectByRoomID(list, roomID);
	Seat_Srv_SortSeatList(list);
	return SeatCount;
}

/*根据放映厅ID提取有效的座位*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID) {
	int SeatCount = Seat_Perst_SelectByRoomID(list, roomID);
	seat_node_t *p;
	List_ForEach(list, p) {
		if (p->data.status != SEAT_GOOD) {
			List_Free(list, seat_node_t);
			SeatCount--;
		}
	}
	Seat_Srv_SortSeatList(list);
	return 0;
}

//根据行、列数初始化演出厅的座位
int Seat_Srv_RoomInit(seat_list_t list, int roomID, int rowsCount,
		int colsCount) {
	int i, j;
	seat_node_t *p;
	//批量获取主键
//	long seatID=EntKey_Srv_CompNewKeys("Seat", rowsCount*colsCount);
	//先按行列数生成默认座位，形成链表
	for (i = 1; i <= rowsCount; i++){
		for (j = 1; j <= colsCount; j++) {
			p = (seat_node_t *) malloc(sizeof(seat_node_t));
//			p->data.id = seatID;
			p->data.roomID = roomID;
			p->data.row = i;
			p->data.column = j;
			p->data.status = SEAT_GOOD;
//			seatID++;
			List_AddTail(list, p);
		}
	}
	return Seat_Perst_InsertBatch(list);
}

//对座位链表list进行按座位行号和列号排序
void Seat_Srv_SortSeatList(seat_list_t list) {
	assert(list != NULL);
	if (List_IsEmpty(list))
		return ;
	seat_node_t *p, *listLeft;
	list->prev->next = NULL;
	listLeft = list->next;
	list->next = list->prev = list;
	while (listLeft != NULL) {
		p = listLeft;
		listLeft = listLeft->next;
		Seat_Srv_AddToSoftedList(list, p);
	}
}

//将结点node加入到已排序链表list中
void Seat_Srv_AddToSoftedList(seat_list_t list, seat_node_t *node) {
	seat_node_t *p;
	if (List_IsEmpty(list) != NULL) {
		List_AddTail(list, node);
	} else {
		p = list->next;
		while(p!=list && (p->data.row<node->data.row ||
				(p->data.row==node->data.row && p->data.column<node->data.column))){
			p=p->next;
		}
		List_InsertBefore(p, node);
	}
}

seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row,
		int column) {
	seat_node_t *p;
	List_ForEach(list, p) {
		if (p->data.row == row && p->data.column == column)
			return p;
	}
	return NULL;
}

seat_node_t * Seat_Srv_FindByID(seat_list_t list, int rowID) {

	return NULL;
}
