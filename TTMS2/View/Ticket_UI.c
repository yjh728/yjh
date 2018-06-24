#include "Ticket_UI.h"

#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"

#include <stdio.h>
#include <stdlib.h>

void Ticket_UI_MgtEntry(int schedule_id) {
    schedule_t *buf;
	if (Schedule_Srv_FetchByID(schedule_id, buf)) {
        play_t *buff;
        if (Play_Srv_FetchByID(buf->play_id, buff)) {
            printf("��Ŀ����  �ݳ������    �ݳ�����  �ݳ�ʱ��\n");
            printf("%8d  %10d  %d/%02d/%02d  %d:%d:%d\n", buff->name, buf->studio_id, buf->date.year, buf->date.month,
                    buf->date.day, buf->time.hour, buf->time.minute, buf->time.second);
            printf("[N]��������Ʊ\t[S]�����ݳ�Ʊ\n");
            fflush(stdin);
            char choice = getchar();
            switch (choice) {
            case 's':
            case 'S':
                Ticket_Srv_GenBatch(schedule_id, buf->studio_id);
                break;
            case 'n':
            case 'N':
                Ticket_Srv_DeleteBatch(schedule_id);
                Ticket_Srv_GenBatch(schedule_id, buf->studio_id);
                break;
            }
        } else {
            printf("��Ǹ,�þ�Ŀ������!");
            getchar();
        }
	} else {
            printf("��Ǹ,���ݳ��ƻ�������!");
            getchar();
    }
}

void Ticket_UI_Query(void) {
    ticket_list_t head;
    List_Init(head, ticket_node_t);
    //Ticket_Srv_FetchAll();
}

int Ticket_UI_ShowTicket(int ticket_id) {
    ticket_t *buf;
    int rtn =  Ticket_Srv_FetchByID(ticket_id, buf);
    if (rtn)
        printf("���ҳɹ�!\n");
    else
        printf("����ʧ��,��Ʊ������!\n");
    return rtn;
}
