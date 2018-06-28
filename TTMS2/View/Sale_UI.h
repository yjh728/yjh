#ifndef 	SALETICKET_UI_H_
#define 	SALETICKET_UI_H_

#include "../Service/Play.h"
#include "../Service/Schedule.h"
#include "../Service/Seat.h"
#include "../Service/Account.h"
#include "../Service/Ticket.h"


//根据剧目ID显示演出计划
void Sale_UI_ShowScheduler(int playID);


//售票界面
int Sale_UI_SellTicket(int schedule_id);

//管理售票的主界面
void Sale_UI_MgtEntry(void);

//退票
int Sale_UI_ReturnTicket(int schedule_id);

#endif
