#include "Sale_Persist.h"
#include "../Common/list.h"
#include "../Service/Sale.h"
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include "EntityKey_Persist.h"

static const char SALE_DATA_FILE[] = "Sale.dat";
static const char SALE_DATA_TEMP_FILE[] = "SaleTmp.dat";
static const char SALE_KEY_NAME[] = "Sale";
static const char TICKET_DATA_FILE[] = "Ticket.dat";
//存储新订单
int Sale_Perst_Insert (sale_t *data){
	FILE *fp = fopen(SALE_DATA_FILE, "ab");
	if (!fp) {
		printf("打开文件%s失败!", SALE_DATA_FILE);
		getchar();
		return 0;
	}
	data->id = EntKey_Perst_GetNewKeys(SALE_KEY_NAME, 1);
	int rtn = fwrite(data, sizeof(sale_t), 1, fp);
	fclose(fp);
	return rtn;
}

//更新票状态
int Ticket_Perst_Update (const ticket_t *data){
	assert(NULL!=data);
	FILE *fp = fopen(TICKET_DATA_FILE, "rb+");
	if (NULL == fp)
		return 0;
	ticket_t rec;
	int rtn = 0;
	while (!feof(fp)) {
		if (fread(&rec, sizeof(ticket_t), 1, fp)) {
			if (rec.id == data->id) {
				fseek(fp, -sizeof(ticket_t), SEEK_CUR);
				fwrite(data, sizeof(ticket_t), 1, fp);
				rtn = 1;
				break;
			}
		}
	}
	fclose(fp);
	return rtn;
}

//根据演出计划ID载入票的数据
int Ticket_Srv_SelBySchID(int id, ticket_list_t list){
	ticket_node_t *newNode;
	ticket_t data;
	int recCount = 0;
	List_Free(list, ticket_node_t);
	FILE *fp = fopen(TICKET_DATA_FILE, "rb");
	if (NULL == fp) { //文件不存在
		printf("不能打开文件%s!\n", TICKET_DATA_FILE);
		return 0;
	}
	while (!feof(fp)) {
		if (fread(&data, sizeof(ticket_t), 1, fp) && data.schedule_id == id){
			newNode = (ticket_node_t*) malloc(sizeof(ticket_node_t));
			if (!newNode) {
				printf("Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
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
//根据票ID载入销售记录
int Sale_Perst_SelByTicketID (int ticket_id, sale_t *sale){
	assert(NULL!=sale);
	FILE *fp = fopen(SALE_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}
	sale_t buf;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&buf, sizeof(sale_t), 1, fp)) {
			if (ticket_id == buf.ticket_id) {
				*sale = buf;
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	return found;
}

//根据ID载入销售记录
int Sale_Perst_SelByID (sale_list_t list, int usrID){
	int recCount = 0;
	if (access(SALE_DATA_FILE, 0))
        return 0;
    List_Free(list, sale_node_t);
    FILE *fp = fopen(SALE_DATA_FILE, "rb");
    if (fp == NULL)
        return 0;
    sale_t data;
    sale_node_t *newNode;
    while (!feof(fp)) {
        if (fread(&data, sizeof(sale_t), 1, fp)) {
            if (data.user_id == usrID) {
                newNode = (sale_node_t *) malloc(sizeof(sale_node_t));
                if (!newNode) {
                    printf("警告,内存溢出!!!不能添加更多信息!!!\n");
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
