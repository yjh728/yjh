#include "../Persistence/Sale_Persist.h"
#include "../Common/List.h"
#include "Schedule.h"
#include "Seat.h"
//����¶�����Ϣ
int Sale_Srv_Add(sale_t *data){
	return Sale_Perst_Insert(data);
}

//�޸�Ʊ״̬
int Ticket_Srv_Modify (const ticket_t *data){
	return Ticket_Perst_Update(data);
}

//�����ݳ��ƻ�ID��ȡƱ������
int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id){
	return Ticket_Srv_SelBySchID(list, schedule_id);
}


//����ID��ȡƱ
ticket_node_t * Ticket_Srv_FetchBySeatID (ticket_list_t list, int seat_id){
	ticket_node_t *p;
	List_ForEach(list, p){
		if(p->data.seat_id == seat_id)
			return p;
	}
	return NULL;
}

