#include "Play_UI.h"
#include "Schedule_UI.h"

#include "../Common/List.h"
#include "../Service/Play.h"

#include <stdio.h>
#include <stdlib.h>

void Play_UI_MgtEntry() {
    play_list_t head;
	play_list_t pos;
	Pagination_t paging;
	int i, id;
	char choice;
	List_Init(head,play_node_t);
	paging.offset = 0;
	paging.pageSize = PLAY_PAGE_SIZE;

	paging.totalRecords = Play_Srv_FetchAll(head);

	Paging_Locate_FirstPage(head,paging);

	do{
		system("cls");
		printf("\n============================================================\n");
		printf("*********************** ��Ŀ�б� **************************\n");
		printf("%2s  %-10s  %-4s  %-6s  %-4s  %-4s  %-6s  %-6s     %-8s\n","���","����","����","����","����","ʱ��",
					"��ӳ����","��������","Ʊ��");
		printf("--------------------------------------------------------\n");
		for(i = 0, pos = (play_node_t*)(paging.curPos); pos != head && i < paging.pageSize; i++) {
			printf("%-2d    %-10s  %-4d  %-6s  %-4d  %-3d  %4d/%02d/%02d  %4d/%02d/%02d  %-2d\n",pos->data.id
					,pos->data.name,pos->data.type,pos->data.area,pos->data.rating
					,pos->data.duration,pos->data.start_date.year,pos->data.start_date.month,pos->data.start_date.day
					,pos->data.end_date.year,pos->data.end_date.month,pos->data.end_date.day,pos->data.price);
			pos = pos->next;
		}
		printf("------- ȫ����¼:%2d ----------------------- ҳ�� %d/%d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf("*************************************************************\n");
		printf("[P]��һҳ|[N]��һҳ|[A]���|[D]ɾ��|[U]�޸�|[Q]��ѯ|[Y]�����ݳ�|[R]����");
		printf("\n===========================================================\n");
		printf("����ѡ��:");//Your Choice
        scanf(" %c", &choice);
        fflush(stdin);
		switch (choice) {
            case 'a':
            case 'A':
                if (Play_UI_Add()) //����ӳɹ����������һҳ��ʾ
                {
                    paging.totalRecords = Play_Srv_FetchAll(head);
                    Paging_Locate_LastPage(head, paging, play_node_t);
                }
                break;
            case 'd':
            case 'D':
                printf("����ID:");
                scanf("%d", &id);
                fflush(stdin);
                if (Play_UI_Delete(id)) {	//������������
                    paging.totalRecords = Play_Srv_FetchAll(head);
                    List_Paging(head, paging, play_node_t);
                }
                break;
            case 'u':
            case 'U':
                printf("�����ĿID:");
                scanf("%d", &id);
                fflush(stdin);
                if (Play_UI_Modify(id)) {	//������������
                    paging.totalRecords = Play_Srv_FetchAll(head);
                    List_Paging(head, paging, play_node_t);
                }
                break;
            case 'q':
            case 'Q':
                printf("�����ĿID:");
                scanf("%d", &id);
                fflush(stdin);
                if (Play_UI_Query(id)) {
                    paging.totalRecords = Play_Srv_FetchAll(head);
                    List_Paging(head, paging, play_node_t);
                }
                break;
            case 'p':
            case 'P':
                if (1 < Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
                }
                break;
            case 'n':
            case 'N':
                if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
                }
                break;
            case 'y':
            case 'Y':
                printf("��������Ҫ������ݳ��ƻ��ľ�Ŀid:");
                scanf("%d", &id);
                fflush(stdin);
                Schedule_UI_MgtEntry(id);
                break;
        }
	} while (choice != 'r' && choice != 'R');
	List_Destroy(head,play_node_t);
}

int Play_UI_Add(void) {
	play_t rec;
	int newRecCount = 0;
	char choice;
	do {
		system("cls");
		printf("\n=======================================================\n");
		printf("\t****************  ����¾�Ŀ ***************\n");
		printf("-------------------------------------------------------\n");
		printf("��Ŀ����:");
		gets(rec.name);
		fflush(stdin);
		printf("��Ŀ����(1��ʾ��Ӱ,2���,3���ֻ�):");
		scanf("%d", &(rec.type));
		fflush(stdin);
		printf("��Դ����:");
		gets(rec.area);
		fflush(stdin);
		printf("��Ŀ����(1��ʾ��ͯ,2������,3����):");
		scanf("%d", &(rec.rating));
		fflush(stdin);
		printf("�ݳ�ʱ��(����):");
		scanf("%d", &(rec.duration));
		fflush(stdin);
		printf("��ӳ����:(yyyy/mm/dd):");
		scanf("%d/%d/%d",&rec.start_date.year,&rec.start_date.month,&rec.start_date.day);
		fflush(stdin);
		printf("��������:(yyyy/mm/dd):");
		scanf("%d/%d/%d",&rec.end_date.year,&rec.end_date.month,&rec.end_date.day);
		fflush(stdin);
		printf("Ʊ��:");
		scanf("%d",&rec.price);
		fflush(stdin);
		printf("=======================================================\n");
		if (Play_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("�¾�Ŀ��ӳɹ�!\n");
		} else
			printf("�¾�Ŀ���ʧ��!\n");
		printf("-------------------------------------------------------\n");
		fflush(stdin);
		printf("[A]��Ӹ���, [R]����:");
		scanf("%c", &choice);
		fflush(stdin);
	} while ('r' != choice && 'R' != choice);
	return newRecCount;
}

int Play_UI_Modify(int id) {
	play_t data;
	play_t *rec = &data;
	int rtn = 0;
	if (!Play_Srv_FetchByID(id, &data)) {
		printf("�þ�Ŀ������!\n��[Enter]������!\n");
		getchar();
		return 0;
	}
	system("cls");
	printf("\n=======================================================\n");
	printf("\t****************  �޸ľ�Ŀ  ****************\n");
	printf("-------------------------------------------------------\n");
	printf("��Ŀ���:%d\n", rec->id);
	printf("��Ŀ����:[%s]",rec->name);
	gets(rec->name);
	fflush(stdin);
	printf("��Ŀ����(1��ʾ��Ӱ,2���,3���ֻ�):[%d]",rec->type);
	scanf("%d", &(rec->type));
	fflush(stdin);
	printf("��Դ����:[%s]",rec->area);
	gets(rec->area);
	fflush(stdin);
	printf("��Ŀ����(1��ʾ��ͯ,2������,3���ֻ�)[%d]:",rec->rating);
	scanf("%d", &(rec->rating));
	fflush(stdin);
	printf("�ݳ�ʱ��(����):[%d]",rec->duration);
	scanf("%d", &(rec->duration));
	fflush(stdin);
	printf("��ӳ����:(yyyy/mm/dd):[%04d/%02d/%02d]",rec->start_date.year,rec->start_date.month,rec->start_date.day);

	scanf("%d/%d/%d",&rec->start_date.year,&rec->start_date.month,&rec->start_date.day);
	fflush(stdin);
	printf("��������:(yyyy/mm/dd)::[%04d/%02d/%02d]",rec->end_date.year,rec->end_date.month,rec->end_date.day);

	scanf("%d/%d/%d",&rec->end_date.year,&rec->end_date.month,&rec->end_date.day);
	fflush(stdin);
	printf("-------------------------------------------------------\n");
	if (Play_Srv_Modify(rec)) {
		rtn = 1;
		printf("��Ŀ�����޸ĳɹ�!\n��[Enter]����!\n");
	} else
		printf("��Ŀ�����޸�ʧ��!\n��[Enter]����\n");
	getchar();
	return rtn;
}

int Play_UI_Delete(int id) {
    int rtn = 0;
	if(Play_Srv_DeleteByID(id)){
		printf("��Ŀɾ���ɹ�!\n");
		if(Schedule_Srv_DeleteByID(id)) {
			printf("�ݳ��ƻ�ɾ���ɹ�!���س�����!\n");
            rtn = 1;
		} else {
            printf("���ݳ��ƻ�������!���س�����!\n");//The room does not exist!\nPress [Enter] key to return
        }
	} else{
		printf("��Ŀɾ��ʧ��!\n");
		return 0;
	}
	getchar();
	return rtn;
}

/*
 * Function:    Play_UI_Query
 * Function ID:	TTMS_SCU_Play_UI_Qry
 * Description: ����ID�Ų�ѯ��Ŀ��Ϣ
 * Input:       �����ҵľ�ĿID��
 * Output:      ���ҵ��ľ�Ŀ��Ϣ
 * Return:      0��ʾδ�ҵ���1��ʾ�ҵ���
 */
int Play_UI_Query(int id){
    int rtn=0;
    play_t data;
    play_t *buf = &data;
    char choice;
    rtn = Play_Srv_FetchByID(id, &data);
    system("cls");
	printf("\n============================================================\n");
	printf("*********************** ��Ŀ��ѯ **************************\n");
	printf("%6s  %10s  %4s  %6s  %4s  %4s  %6s  %6s      %4s\n","���","����","����","����","����","ʱ��",
				"��ӳ����","��������","Ʊ��");
	printf("---------------------------------------------------------------\n");
	printf("%6d  %10s  %4d  %6s  %4d  %4d  %4d/%02d/%02d  %4d/%02d/%02d  %2d\n",buf->id
						,buf->name,buf->type,buf->area,buf->rating
						,buf->duration,buf->start_date.year,buf->start_date.month,buf->start_date.day
						,buf->end_date.year,buf->end_date.month,buf->end_date.day,buf->price);
	printf(
			"*********************************************************\n");
    getchar();
	return rtn;
}
