#ifndef 	SALETICKET_UI_H_
#define 	SALETICKET_UI_H_

#include "../Service/Play.h"
#include "../Service/Schedule.h"
#include "../Service/Seat.h"
#include "../Service/Account.h"
#include "../Service/Ticket.h"


//���ݾ�ĿID��ʾ�ݳ��ƻ�
void Sale_UI_ShowScheduler(int playID);


//��Ʊ����
int Sale_UI_SellTicket(int schedule_id);

//������Ʊ��������
void Sale_UI_MgtEntry(void);

//��Ʊ
int Sale_UI_ReturnTicket(int schedule_id);

#endif
