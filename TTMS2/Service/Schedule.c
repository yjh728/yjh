#include "Schedule.h"
#include "../Common/List.h"
#include "../Persistence/Schedule_Persist.h"
#include "Ticket.h"
#include <stdio.h>

 int Schedule_Srv_Add( schedule_t *data) {
	return Schedule_Perst_Insert(data);
}

int Schedule_Srv_Modify( schedule_t *data) {
	return Schedule_Perst_Update(data);
}

 int Schedule_Srv_DeleteByID(int ID) {
	return Schedule_Perst_RemByID(ID);
}

 int Schedule_Srv_FetchByID(int ID, schedule_t *buf) {
	return Schedule_Perst_SelectByID(ID, buf);
}

 int Schedule_Srv_FetchAll(schedule_list_t list) {
	return Schedule_Perst_SelectAll(list);
}

 int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id) {
	return Schedule_Perst_SelectByPlay(list, play_id);
}

/*
//���ݾ�ĿID��ȡƱ��
int Schedule_Srv_StatRevByPlay(int play_id, int *soldCount){

}
*/
//�����ݳ�ID��ͳ�������ʼ�Ʊ��������Ʊ��������
//int Schedule_Srv_StatRevByPlay(int play_id, int *soldCount, int *totalCount) {
//	return 0;
//}
