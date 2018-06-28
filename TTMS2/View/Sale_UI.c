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

//管理售票的主界面
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
        printf("*********************** 剧目列表 **************************\n");
        printf("%2s  %10s  %4s  %6s  %4s  %4s  %6s  %6s %4s\n","编号","名称","类型","地区","级别","时长",
                    "上映日期","结束日期","票价");
        printf("--------------------------------------------------------\n");
        for(i=0,pos=(play_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
            printf("%2d  %10s  %4d  %6s  %4d  %4d  %4d-%2d-%2d  %4d-%2d-%2d  %2d\n",pos->data.id
                    ,pos->data.name,pos->data.type,pos->data.area,pos->data.rating
                    ,pos->data.duration,pos->data.start_date.year,pos->data.start_date.month,pos->data.start_date.day
                    ,pos->data.end_date.year,pos->data.end_date.month,pos->data.end_date.day,pos->data.price);
            pos = pos->next;
        }
        printf("------- 全部记录:%2d ----------------------- 页数 %2d/%2d ----\n",
                paging.totalRecords, Pageing_CurPage(paging),
                Pageing_TotalPages(paging));
        printf("******************************************************************\n");
        printf("[S]管理票(售票/退票)|[P]上一页|[N]下一页|[R]返回");
        printf("\n==================================================================\n");
        printf("功能选择:");//Your Choice
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case 'S':
            case 's':
                printf("请输入要查询演出计划的剧目编号:");
                scanf("%d",&play_id);
                fflush(stdin);
                Sale_UI_ShowScheduler(play_id);
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
            //暂时砍掉F
        }
    } while(choice != 'R' && choice != 'r');
    List_Destroy(head,play_node_t);
}

//根据剧目ID显示演出计划
void Sale_UI_ShowScheduler(int playID){
    play_t buf;
	schedule_list_t head, pos;
	Pagination_t paging;
	int i, schedule_id;
	char choice;
	studio_t stu;
	Play_Srv_FetchByID(playID, &buf);
	List_Init(head, schedule_node_t);
	paging.offset=0;
	paging.totalRecords=Schedule_Srv_FetchByPlay(head, playID);
	paging.pageSize=SCHEDULE_PAGE_SIZE;
	Paging_Locate_FirstPage(head,paging);
	do{
		system("cls");
		printf("\n========================================================\n");
	    printf("**********************演出计划列表**********************\n");
	    printf("%4s  %10s  %10s  %5s %5s\n","编号","剧名","演出厅","日期","时间");
	    printf("--------------------------------------------------------\n");
	    for(i=0,pos=(schedule_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
	    	Studio_Srv_FetchByID(pos->data.studio_id,&stu);
		    printf("%4d  %10s  %10s  %4d/%2d/%2d %2d:%2d\n",pos->data.id,buf.name,stu.name,
                    pos->data.date.year,pos->data.date.month,pos->data.date.day,
                    pos->data.time.hour,pos->data.time.minute);
		    pos = pos->next;
	    }
	    printf("------- 全部记录:%2d ----------------------- 页数 %2d/%2d ----\n",
	    				paging.totalRecords, Pageing_CurPage(paging),
	    				Pageing_TotalPages(paging));
	    printf("--------------------------------------------------------\n");
	    printf("[S]售票|[T]退票|[P]上一页|[N]下一页|[R]返回\n");
	    printf("请输入功能选择:");
	    scanf("%c",&choice);
	    fflush(stdin);
	    switch(choice){
		  	case 's':
		 	case 'S':
		       	printf("请输入要售票的演出计划ID:");
		      	scanf("%d",&schedule_id);
		      	fflush(stdin);
		       	Sale_UI_SellTicket(schedule_id);
		        break;
            case 't':
            case 'T':
                printf("请输入要售票的演出计划ID:");
		      	scanf("%d",&schedule_id);
		      	fflush(stdin);
		       	Sale_UI_ReturnTicket(schedule_id);
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
	}while(choice != 'R' &&  choice != 'r');
	List_Destroy(head,schedule_node_t);
}

//售票界面
int Sale_UI_SellTicket(int schedule_id){
    system("cls");
    if(gl_CurUser.type != USR_CLERK){
		printf("您不是售票员!无权使用此功能!");
		getchar();
		return 0;
	}
	Ticket_UI_ShowTicket(schedule_id, 1);
	printf("\n===============================================================\n");
	printf("**************************  售票  ********************************\n");
	printf("------------------------------------------------------------------\n");
	printf("请输入你要售的票的ID:\n");
	int ticket_id;
	scanf("%d", &ticket_id);
	fflush(stdin);
	ticket_t buf;
	if(Ticket_Srv_FetchByID(ticket_id, &buf) == 0){
		printf("未找到对应的票!\n");
		getchar();
		return 0;
	}
	if(buf.status != 0){
		printf("此票已售出或被预留!\n");
		getchar();
		return 0;
	}
	sale_t sal;
	sal.id = EntKey_Perst_GetNewKeys("Sale", 1);
	sal.user_id = gl_CurUser.id;
	sal.ticket_id = buf.id;
	sal.date = DateNow();
	sal.time = TimeNow();
	sal.value = buf.price;
	sal.type = SALE_SELL;
	if(Sale_Srv_Add(&sal)){
		printf("出票成功!应收取 %d 元!",buf.price);
		buf.status = 1;
		Ticket_Srv_Modify(&buf);
		getchar();
		return 1;
	}
}

//退票
int Sale_UI_ReturnTicket(int schedule_id){
    int id;
	ticket_t tic;
	system("cls");
	Ticket_UI_ShowTicket(schedule_id, 2);
	printf("\n===============================================================\n");
	printf("**************************  退票  ********************************\n");
	printf("------------------------------------------------------------------\n");
	printf("请输入要退的票的ID:");
	scanf("%d", &id);
	fflush(stdin);
	if(!Ticket_Srv_FetchByID(id, &tic)){
		printf("要退的票不存在!\n");
		getchar();
		return 0;
	}
	if(tic.status != 1){
		printf("此票尚未售出!\n");
		getchar();
		return 0;
	}
	tic.status = 0;
	if(Ticket_Srv_Modify(&tic)){
	    sale_t refound;
	    refound.user_id =gl_CurUser.id;
        refound.date = DateNow();
        refound.ticket_id = id;
        refound.time = TimeNow();
        refound.type = SALE_RETURN;
        refound.value = tic.price;
        Sale_Srv_Add(&refound);
		printf("退票成功!应退款 %d 元!",tic.price);
	} else {
		printf("抱歉!退票失败!\n");
	}
	getchar();
	return 1;
}
