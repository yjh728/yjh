#include "Play_UI.h"
#include "Schedule_UI.h"
#include "Sale_UI.h"
#include "Ticket_UI.h"
#include "../Service/Ticket.h"
#include "../Service/Seat.h"
#include "../Service/Studio.h"
#include "../Service/Sale.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern account_t gl_CurUser;
static const int SALESANALYSIS_PAGE_SIZE = 6;

//���ݾ�ĿID��ʾ�ݳ��ƻ�
void Sale_UI_ShowScheduler(int playID){
    play_t buf;
	schedule_list_t head, pos;
	Pagination_t paging;
	int i, schedule_id;
	char choice;
	studio_t stu;
	Play_Srv_FetchByID(playID,&buf);
	List_Init(head, schedule_node_t);
	paging.offset=0;
	paging.totalRecords=Schedule_Srv_FetchByPlay(head,playID);
	paging.pageSize=SCHEDULE_PAGE_SIZE;
	Paging_Locate_FirstPage(head,paging);
	do{
		system("cls");
		printf("\n========================================================\n");
	    printf("**********************��Ŀ�ݳ��ƻ��б�**********************\n");
	    printf("%4s  %10s  %10s  %5s %5s\n","���","����","�ݳ���","����","ʱ��");
	    printf("--------------------------------------------------------\n");
	    for(i=0,pos=(schedule_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
	    	Studio_Srv_FetchByID(pos->data.studio_id,&stu);
		    printf("%4d  %10s  %10s  %2d/%2d %2d:%2d\n",pos->data.id,buf.name,stu.name,pos->data.date.month
		    		,pos->data.date.day,pos->data.time.hour,pos->data.time.minute);
		    pos = pos->next;
	    }
	    printf("------- ȫ����¼:%2d ----------------------- ҳ�� %2d/%2d ----\n",
	    				paging.totalRecords, Pageing_CurPage(paging),
	    				Pageing_TotalPages(paging));
	    printf("--------------------------------------------------------\n");
	    printf("[T]��ʾƱ|[P]��һҳ|[N]��һҳ|[R]����\n");
	    printf("�����빦��ѡ��:");
	    fflush(stdin);
	    scanf("%c",&choice);
	    switch(choice){
		  	case 'T':
		 	case 't':
		       	printf("������Ҫ��ʾƱ���ݳ��ƻ�ID:");
		      	fflush(stdin);
		      	scanf("%d",&schedule_id);
		       	//Sale_UI_ShowTicket(schedule_id);
		        break;
		   	case 'P':
		 	case 'p':
		 		if (1 < Pageing_CurPage(paging)) {
		               Paging_Locate_OffsetPage(head,paging,-1,schedule_node_t);
		           }
		          break;
		 	case 'N':
		 	case 'n':
		 		if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
		 			Paging_Locate_OffsetPage(head,paging,1,schedule_node_t);
		        }
		        break;
	    }
	}while(choice!='R' &&  choice!='r');
	List_Destroy(head,schedule_node_t);
}

//��Ʊ����
int Sale_UI_SellTicket(ticket_list_t tickList, seat_list_t seatList){
    if(gl_CurUser.type != USR_CLERK){
		printf("��������ƱԱ!��Ȩʹ�ô˹���!");
		getchar();
		return 0;
	}
	int row,col;
	seat_node_t * pSeat=NULL;
	ticket_node_t *tic;
	sale_t sal;
	system("cls");
	printf("\n===============================================================\n");
	printf("**************************  ��Ʊ  ********************************\n");
	printf("------------------------------------------------------------------\n");
	printf("��������λ�к�:");
	fflush(stdin);
	scanf("%d", &row);
	printf("��������λ�к�:");
	fflush(stdin);
	scanf("%d", &col);
	pSeat=Seat_Srv_FindByRowCol(seatList,row,col);
	if(!pSeat){
		printf("�������λ������!\n");
		getchar();
		return 0;
	}
	//tic = Ticket_Srv_FindBySeatID(tickList,pSeat->data.id);
	if(!tic){
		printf("δ�ҵ���Ӧ��Ʊ!\n");
		getchar();
		return 0;
	}
	if(tic->data.status!=0){
		printf("��Ʊ���۳���Ԥ��!\n");
		getchar();
	}
	sal.ticket_id = tic->data.id;
	sal.id = EntKey_Perst_GetNewKeys("Sale", 1);
	sal.user_id = gl_CurUser.id;
	sal.ticket_id = tic->data.id;
	sal.date = DateNow();
	sal.time = TimeNow();
	sal.value = tic->data.price;
	sal.type = SALE_SELL;
	if(Sale_Srv_Add(&sal)){
		printf("��Ʊ�ɹ�!Ӧ��ȡ %d Ԫ!",tic->data.price);
		tic->data.status = 1;
		Ticket_Srv_Modify(&tic->data);
		getchar();
	}
	return 1;
}

//������Ʊ��������
void Sale_UI_MgtEntry(void){
    play_list_t head, pos;
	Pagination_t paging;
	int i,play_id;
	char choice, name[30];
    List_Init(head,play_node_t);
    paging.offset = 0;
    paging.pageSize = SALESANALYSIS_PAGE_SIZE;
    paging.totalRecords = Play_Srv_FetchAll(head);
    Paging_Locate_FirstPage(head,paging);
    do{
        system("cls");
        printf("\n============================================================\n");
        printf("*********************** ��Ŀ�б� **************************\n");
        printf("%2s  %10s  %4s  %6s  %4s  %4s  %6s  %6s %4s\n","���","����","����","����","����","ʱ��",
                    "��ӳ����","��������","Ʊ��");
        printf("--------------------------------------------------------\n");
        for(i=0,pos=(play_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
            printf("%2d  %10s  %4d  %6s  %4d  %4d  %2d-%2d  %2d-%2d  %2d\n",pos->data.id
                    ,pos->data.name,/*pos->data.type*/ 1,pos->data.area,pos->data.rating
                    ,pos->data.duration,pos->data.start_date.month,pos->data.start_date.day
                    ,pos->data.end_date.month,pos->data.end_date.day,pos->data.price);
            pos = pos->next;
        }
        printf("------- ȫ����¼:%2d ----------------------- ҳ�� %2d/%2d ----\n",
                paging.totalRecords, Pageing_CurPage(paging),
                Pageing_TotalPages(paging));
        printf("******************************************************************\n");
        printf("[C]�ݳ��ƻ�|[S]���Ҿ�Ŀ��|[F]ɸѡ��Ŀ��|[P]��һҳ|[N]��һҳ|[R]����");
        printf("\n==================================================================\n");
        printf("����ѡ��:");//Your Choice
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice) {
            case 'C':
            case 'c':
                printf("������Ҫ��ѯ�ݳ��ƻ��ľ�Ŀ���:");
                fflush(stdin);
                scanf("%d",&play_id);
                Sale_UI_ShowScheduler(play_id);
                break;
            case 'S':
            case 's':
                printf("������Ҫ��ѯ�Ĺؼ���:");
                fflush(stdin);
                gets(name);
                Play_Srv_FetchByName(head, name);
                break;
            case 'f':
            case 'F':
                printf("������Ҫɸѡ�ľ�Ŀ��:");
                fflush(stdin);
                gets(name);
                Play_Srv_FilterByName(head, name);
                break;
            case 'P':
            case 'p':
                if (1 < Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(head,paging,-1,play_node_t);
                }
                break;
            case 'N':
            case 'n':
                if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(head,paging,1,play_node_t);
                }
                break;
            //��ʱ����F
        }
    } while(choice != 'R' && choice != 'r');
    List_Destroy(head,play_node_t);
}

//��Ʊ
void Sale_UI_ReturnTicket(){
    int id;
	ticket_t tic;
	system("cls");
	printf("\n===============================================================\n");
	printf("**************************  ��Ʊ  ********************************\n");
	printf("------------------------------------------------------------------\n");
	printf("������Ҫ�˵�Ʊ��ID:");
	fflush(stdin);
	scanf("%d",&id);
	if(!Ticket_Srv_FetchByID(id, &tic)){
		printf("Ҫ�˵�Ʊ������!\n");
		getchar();
		return ;
	}
	if(tic.status!=1){
		printf("��Ʊ��δ�۳�!\n");
		getchar();
		return;
	}
	tic.status=0;
	if(Ticket_Srv_Modify(&tic)){
		printf("��Ʊ�ɹ�!Ӧ�˿� %d Ԫ!",tic.price);
	} else {
		printf("��Ǹ!��Ʊʧ��!\n");
	}
	getchar();
	return;
}
