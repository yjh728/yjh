#include "Ticket.h"
#include "../Common/List.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Persistence/Ticket_Persist.h"
#include "../Persistence/Play_Persist.h"
#include "../Persistence/Schedule_Persist.h"
#include "../Service/Seat.h"

#include <stdio.h>
#include <stdlib.h>

int Ticket_Srv_GenBatch(int schedule_id, int studio_id){
	seat_list_t seat_head;
	int count=0;
	int recCount = 0;
	List_Init(seat_head, seat_node_t);
	count = Seat_Srv_FetchValidByRoomID(seat_head, studio_id);
	if(count == 0){
		printf("没有座位信息,不能创建门票。\n");
		printf("请键入任意键返回!\n");
		getchar();
		return 0;
	}
	return Ticket_Perst_Insert(schedule_id, seat_head);
}

int Ticket_Srv_DeleteBatch(int schedule_id) {
	return Ticket_Perst_Rem(schedule_id);
}

int Ticket_Srv_FetchByID (int id, ticket_t *buf){
	return Ticket_Perst_SelByID(id, buf);
}

