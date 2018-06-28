/*
 * salesanalysis.c
 *
 *  Created on: 2015年6月12日
 *      Author: Administrator
 */
#include <string.h>
#include <stdio.h>
#include "SalesAnalysis.h"
#include "Sale.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"
#include "../Common/List.h"

//获取剧目票房
int SalesAnalysis_Srv_StaticSale(salesanalysis_list_t list) {
	if (list == NULL) {
        printf("该链表为空!!!\n");
	}
	play_list_t playlist;
	play_node_t *pos;
	salesanalysis_node_t *newNode;
	int sold=0;
    int rtn=0;
	List_Free(list, salesanalysis_node_t);
	List_Init(playlist, play_node_t);
	Play_Srv_FetchAll(playlist);
	List_ForEach(playlist, pos) {
        if(!(newNode=(salesanalysis_list_t)malloc(sizeof(salesanalysis_node_t)))){
            printf("内存申请失败!\n");
            return rtn;
        }
        newNode->data.play_id = pos->data.id;
        strcpy(newNode->data.name,pos->data.name);
        strcpy(newNode->data.area,pos->data.area);
        newNode->data.duration = pos->data.duration;
        newNode->data.sales = Ticket_Srv_StatRevByPlay(newNode->data.play_id, &sold);
        newNode->data.totaltickets = sold;
        newNode->data.price = pos->data.price;
        newNode->data.start_date = pos->data.start_date;
        newNode->data.end_date = pos->data.end_date;
        List_AddTail(list,newNode);
        rtn++;
	}
	List_Destroy(playlist,play_node_t);
	return rtn;
}

//剧目票房排行
void SalesAnalysis_Srv_SortBySale(salesanalysis_list_t list){
    if (List_IsEmpty(list))
        return;
    salesanalysis_list_t p, q, listLeft;
    list->prev->next = NULL;
    listLeft = list;
    list->next = list->prev=list;
    List_ForEach(listLeft, p){
        if (List_IsEmpty(list)){
            List_AddTail(list, p);
        } else {
            List_ForEach(list, q){
                if(q->data.sales>p->data.sales){
                    List_InsertBefore(q, p);
                }
            }
        }
    }
}

//根据演出计划ID获取票房
int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount){
	int value = 0;
	ticket_list_t list;
	ticket_node_t *p;
	sale_t sale;
	List_Init(list, ticket_node_t);
	*soldCount = 0;
	*soldCount = Ticket_Srv_FetchBySchID(list, schedule_id);
	List_ForEach(list, p) {
        Sale_Srv_FetchByTicketID(p->data.id, &sale);
        if (sale.type == SALE_SELL && p->data.status == TICKET_SOLD) {
            (*soldCount)++;
            value += p->data.price;
        }
        if (sale.type == SALE_RETURN)
            (*soldCount)--;
	}
	List_Destroy(list, ticket_node_t);
	return value;
}

//根据剧目ID获取票房
int Ticket_Srv_StatRevByPlay(int play_id, int *soldCount) {
    int value = 0;
    int sold = 0;
    schedule_list_t list;
    schedule_node_t *p;
    *soldCount = 0;
    List_Init(list, schedule_node_t);
    Schedule_Perst_SelectByPlay(list, play_id);
    List_ForEach(list, p) {
        value += Ticket_Srv_StatRevBySchID(p->data.id, &sold);
        *soldCount = *soldCount + sold;
    }
    List_Destroy(list, schedule_node_t);
    return value;
}
//根据票ID获取销售记录
int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale){
	return Sale_Perst_SelByTicketID(ticket_id, sale);
}

//根据ID获取销售额统计
int SalesAnalysis_Srv_CompSaleVal(int usrID, ttms_date_t stData, ttms_date_t endData) {
    int amount = 0;
    sale_list_t saleList;
    sale_node_t *pSale;
    List_Init(saleList, sale_node_t);
    Sale_Perst_SelByID(saleList, usrID);
    List_ForEach(saleList, pSale) {
        if (pSale->data.date.year>=stData.year && pSale->data.date.year<=endData.year &&
            pSale->data.date.month>=stData.month && pSale->data.date.month<=endData.month &&
            pSale->data.date.day>=stData.day && pSale->data.date.day<=endData.day) {
            if (pSale->data.type == SALE_SELL)
                amount += pSale->data.value;
            if (pSale->data.type == SALE_RETURN)
                amount -= pSale->data.value;
        }
    }
    List_Destroy(saleList, sale_node_t);
    return amount;
}
