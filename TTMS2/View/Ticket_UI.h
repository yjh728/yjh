#ifndef TICKET_UI_H_
#define TICKET_UI_H_
#include "../Common/List.h"
#include "../Service/ticket.h"
#include "../Service/seat.h"
#include "../Service/Schedule.h"

static const int TICKET_PAGE_SIZE=8;

void Ticket_UI_MgtEntry(int schedule_id);

void Ticket_UI_Query(int schedule_id);

void Ticket_UI_ShowTicket(int schedule_id, int flag);



#endif /* TICKET_UI_H_ */
