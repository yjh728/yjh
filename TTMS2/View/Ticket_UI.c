#include "Ticket_UI.h"
#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"
#include <stdio.h>
#include <stdlib.h>

void Ticket_UI_MgtEntry(int schedule_id) {
    schedule_t buf;
	if (Schedule_Srv_FetchByID(schedule_id, &buf)) {
        play_t buff;
        if (Play_Srv_FetchByID(buf.play_id, &buff)) {
            printf("��Ŀ����  �ݳ������    �ݳ�����  �ݳ�ʱ��\n");
            printf("%8s  %-10d  %d/%02d/%02d  %02d:%02d\n", buff.name, buf.studio_id, buf.date.year, buf.date.month,
                    buf.date.day, buf.time.hour, buf.time.minute);
            printf("[N]��������Ʊ\t[S]�����ݳ�Ʊ\n");
            char choice = getchar();
            fflush(stdin);
            switch (choice) {
            case 's':
            case 'S':
                if (Ticket_Srv_GenBatch(schedule_id, buf.studio_id))
                    printf("�����ݳ�Ʊ�ɹ�!\n");
                break;
            case 'n':
            case 'N':
                if (Ticket_Srv_DeleteBatch(schedule_id))
                    if (Ticket_Srv_GenBatch(schedule_id, buf.studio_id))
                        printf("��������Ʊ�ɹ�!\n");
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

void Ticket_UI_Query(int schedule_id) {
    int i, id;
	schedule_t schedule_rec;
	play_t play_rec;
	char choice;
	ticket_list_t head;
	ticket_node_t *pos;
	Pagination_t paging;
	List_Init(head, ticket_node_t);
	paging.offset = 0;
	paging.pageSize = TICKET_PAGE_SIZE;
	paging.totalRecords = Ticket_Srv_FetchBySchID(head, schedule_id);
	Paging_Locate_FirstPage(head, paging);
	Schedule_Srv_FetchByID(schedule_id,&schedule_rec);
	Play_Srv_FetchByID(schedule_rec.play_id,&play_rec);
	do {
		system("cls");
		printf("\n=======================================================\n");
		printf("****************  Ʊ�б�  ****************\n");
		printf("���\t����\t\t��λ��\t��λ��\t ����\t\tʱ��\t�۸�\t״̬\n");
		printf("-------------------------------------------------------\n");
		for (i = 0, pos = (ticket_node_t *) (paging.curPos);
				pos != head && i < paging.pageSize; i++) {
            seat_t seat;
            Seat_Srv_FetchByID(pos->data.seat_id, &seat);
			printf("%d\t%s\t%d\t%d\t%04d-%02d-%02d\t%02d:%02d\t%d\t%s\n", pos->data.id, play_rec.name,
					seat.row, seat.column,
					schedule_rec.date.year,schedule_rec.date.month,
					schedule_rec.date.day,schedule_rec.time.hour,
					schedule_rec.time.minute,pos->data.price,
					pos->data.status == 1?"����":"����");
			pos = pos->next;
		}
		printf(
				"== �ܼƼ�¼:%d�� =========================== ҳ %d/%d ==\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf("[P]��һҳ|[N]��һҳ|[R]����\n");
		scanf("%c", &choice);
		fflush(stdin);
		switch (choice) {
		case 'p':
		case 'P':
			if (1 < Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, ticket_node_t);
			}
			break;
		case 'n':
		case 'N':
			if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, ticket_node_t);
			}
			break;
		}
	} while (choice != 'r' && choice != 'R');
	List_Destroy(head, ticket_node_t);
}

void Ticket_UI_ShowTicket(int schedule_id, int flag) {
    int i, id;
    schedule_t schedule_rec;
    play_t play_rec;
	char choice;
	ticket_list_t head;
	ticket_node_t *pos;
    seat_t seat;
	Pagination_t paging;
	List_Init(head, ticket_node_t);
	paging.offset = 0;
	paging.pageSize = TICKET_PAGE_SIZE;
	paging.totalRecords = Ticket_Srv_FetchBySchID(head, schedule_id);
	Paging_Locate_FirstPage(head, paging);
	Schedule_Srv_FetchByID(schedule_id, &schedule_rec);
	Play_Srv_FetchByID(schedule_rec.play_id, &play_rec);
    do {
        system("cls");
        printf("\n=======================================================\n");
        printf("****************  Ʊ�б�  ****************\n");
        printf("���\t����\t\t��λ��\t��λ��\t ����\t\tʱ��\t�۸�\t״̬\n");
        printf("-------------------------------------------------------\n");
        for (i = 0, pos = (ticket_node_t *) (paging.curPos);
                pos != head && i < paging.pageSize; i++) {
            Seat_Srv_FetchByID(pos->data.seat_id, &seat);
            printf("%d\t%s\t%d\t%d\t%04d-%02d-%02d\t%02d:%02d\t%d\t%s\n", pos->data.id, play_rec.name,
                    seat.row, seat.column,
                    schedule_rec.date.year,schedule_rec.date.month,
                    schedule_rec.date.day,schedule_rec.time.hour,
                    schedule_rec.time.minute,pos->data.price,
                    pos->data.status == 1 ? "����" : "����");
            pos = pos->next;
        }
        printf("== �ܼƼ�¼:%d�� =========================== ҳ %d/%d ==\n",
                paging.totalRecords, Pageing_CurPage(paging),
                Pageing_TotalPages(paging));
        if (flag == 1)
            printf("[P]��һҳ|[N]��һҳ|[S]��Ʊ\n");
        else if (flag == 2)
            printf("[P]��һҳ|[N]��һҳ|[S]��Ʊ\n");
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
        case 'p':
        case 'P':
            if (1 < Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, -1, ticket_node_t);
            }
            break;
        case 'n':
        case 'N':
            if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                Paging_Locate_OffsetPage(head, paging, 1, ticket_node_t);
            }
            break;
        }
    } while(choice != 's' && choice != 'S');
	List_Destroy(head, ticket_node_t);
}
