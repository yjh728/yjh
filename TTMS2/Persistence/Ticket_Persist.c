#include "Ticket_Persist.h"
#include "Schedule_Persist.h"
#include "EntityKey_Persist.h"
#include "Play_Persist.h"
#include "../Service/Ticket.h"
#include "../Service/Seat.h"
#include "../Service/Play.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>

static const char TICKET_DATA_FILE[]="Ticket.dat";
static const char TICKET_DATA_TEMP_FILE[]="TicketTemp.dat";
static const char TICKET_KEY_NAME[]="Ticket";

int Ticket_Perst_Insert(int schedule_id, seat_list_t list){
	FILE *fp = fopen(TICKET_DATA_FILE, "ab");
	if (NULL == fp) {
		printf("不能打开文件%s!\n", TICKET_DATA_FILE);
		return 0;
	}
	schedule_t sch;
	Schedule_Perst_SelectByID(schedule_id, &sch);
	play_t buf;
	Play_Perst_SelectByID(sch.play_id, &buf);
	int count = 0;
	seat_node_t *pos = list->next;
	while (pos != list) {
        count++;
        pos = pos->next;
	}
	long key = EntKey_Perst_GetNewKeys(TICKET_KEY_NAME, count);
	ticket_t p;
	int rtn = 0;
	pos = list->next;
	while (pos != list) {
        p.id = key++;
        p.price = buf.price;
        p.schedule_id = schedule_id;
        p.seat_id = pos->data.id;
        p.status = 0;
        rtn += fwrite(&p, sizeof(ticket_t), 1, fp);
        pos = pos->next;
	}
	fclose(fp);
	return rtn;
}

int Ticket_Perst_Rem(int schedule_id){
	FILE *fpSour, *fpTarg;
	fpSour = fopen(TICKET_DATA_FILE, "rb");
	fpTarg = fopen(TICKET_DATA_TEMP_FILE, "wb");
	if (NULL == fpTarg) {
		printf("不能打开文件%s!\n", TICKET_DATA_TEMP_FILE);
		return 0;
	}
	if (NULL == fpSour) {
		printf("不能打开文件%s!\n", TICKET_DATA_FILE);
		return 0;
	}
	ticket_t buf;
	int found = 0;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(ticket_t), 1, fpSour)) {
			if (schedule_id == buf.schedule_id) {
				found ++;
				continue;
			}
			fwrite(&buf, sizeof(ticket_t), 1, fpTarg);
		}
	}
	fclose(fpTarg);
	fclose(fpSour);
	remove(TICKET_DATA_FILE);
	if (rename(TICKET_DATA_TEMP_FILE, TICKET_DATA_FILE)) {
		printf("不能重命名%s\n", TICKET_DATA_TEMP_FILE);
		return 0;
	}
	return found;
}

int Ticket_Perst_SelByID(int id, ticket_t *buf){
	assert(NULL!=buf);
	int found = 0;
	FILE *fp = fopen(TICKET_DATA_FILE, "rb");
	if (NULL == fp) {
		printf("不能打开文件%s!\n", TICKET_DATA_FILE);
		return found;
	}
	ticket_t data;
	while (!feof(fp)) {
		if (fread(&data, sizeof(ticket_t), 1, fp)) {
			if (id == data.id) {
				*buf = data;
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	return found;
}
