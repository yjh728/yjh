#include "Schedule_UI.h"
#include "../Common/List.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"
#include "../Service/Seat.h"
#include <stdio.h>
#include <stdlib.h>

void Schedule_UI_ListAll(void) {
    schedule_list_t sch, pos;
	Pagination_t paging;
	play_t pla;
	studio_t stu;
	int i;
	char choice;
	List_Init(sch,schedule_node_t);
	paging.offset = 0;
	paging.pageSize = SCHEDULE_PAGE_SIZE;
	paging.totalRecords = Schedule_Srv_FetchAll(sch);
	Paging_Locate_FirstPage(sch,paging);
	do {
		system("cls");
		printf("\n============================================================\n");
		printf("*********************** 演出计划查询 **************************\n");
		printf("%2s  %10s  %10s  %11s  %3s\n","编号","剧名","演出厅名","演出时间","票价");
		printf("--------------------------------------------------------------\n");
		for(i=0,pos=(schedule_node_t*)(paging.curPos);pos!=sch && i<paging.pageSize;i++){
		    Play_Srv_FetchByID(pos->data.play_id,&pla);
		    Studio_Srv_FetchByID(pos->data.studio_id,&stu);
		    printf("%2d  %10s  %10s  %02d/%02d %02d:%02d   %3d\n",pos->data.id,pla.name,stu.name,
		    		pos->data.date.month,pos->data.date.day,pos->data.time.hour,pos->data.time.minute,pla.price);
		    pos=pos->next;
		}
		printf("------- 全部记录:%2d ----------------------- 页数 %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf(
				"******************************************************************\n");
		printf(
				"[P]上一页|[N]下一页|[R]返回");
		printf(
				"\n==================================================================\n");
		printf("功能选择:");//Your Choice
		scanf("%c", &choice);
        fflush(stdin);
		switch (choice) {
		case 'p':
		case 'P':
			if (1 < Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(sch, paging, -1, schedule_node_t);
			}
			break;
		case 'n':
		case 'N':
			if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(sch, paging, 1, schedule_node_t);
			}
			break;
		}
	}while('r'!=choice && 'R'!=choice);
	List_Destroy(sch, schedule_node_t);
}

int Schedule_UI_Add(int play_id) {
	schedule_t rec;
	seat_list_t seatList;
	List_Init(seatList,seat_node_t);
	int newRecCount=0;
	char choice;
	do{
		system("cls");
		printf("\n=======================================================\n");
		printf("****************  添加演出计划  *****************\n");
		printf("-------------------------------------------------------\n");
		rec.play_id = play_id;
		printf("放映厅编号:");
		scanf("%d",&rec.studio_id);
        fflush(stdin);
		printf("演出日期(yyyy/mm/dd):");
		scanf("%d/%d/%d",&rec.date.year,&rec.date.month,&rec.date.day);
        fflush(stdin);
		printf("演出时间(hh:mm:ss):");
		scanf("%d/%d/%d",&rec.time.hour,&rec.time.minute,&rec.time.second);
        fflush(stdin);
		rec.seat_count = Seat_Srv_FetchValidByRoomID(seatList,rec.studio_id);
		//获取主键
		rec.id = EntKey_Perst_GetNewKeys("Schedule", 1);
		if(Schedule_Srv_Add(&rec)){
			printf("添加演出计划成功!\n");
			Ticket_UI_MgtEntry(rec.id);
			newRecCount++;
		}
		else {
			printf("添加演出计划失败!\n");
		}
		printf("-------------------------------------------------------\n");
		printf("[A]添加更多, [R]返回:");
		scanf("%c", &choice);
        fflush(stdin);
    }while('a'==choice || 'A'==choice);
	return newRecCount;
}

int Schedule_UI_Modify(int id) {
	schedule_t rec;
	seat_list_t seatList;
	List_Init(seatList,seat_node_t);
	int rtn=0;
	if(!Schedule_Srv_FetchByID(id,&rec)){
		printf("该演出计划不存在!回车返回!\n");
		getchar();
		return 0;
	}
	system("cls");
	printf("\n=======================================================\n");
	printf("\t\t**************** 修改演出计划 ****************\n");
	printf("-------------------------------------------------------\n");
	printf("演出计划编号: %d\n",rec.id);
	printf("演出的剧目编号:[%d]",rec.play_id);
	scanf("%d",&rec.play_id);
	fflush(stdin);
	printf("演出的播放厅编号:[%d]",rec.studio_id);
	scanf("%d",&rec.studio_id);
	printf("演出日期:[%04d/%02d/%02d]",rec.date.year,rec.date.month,rec.date.day);
	scanf("%d/%d/%d",&rec.date.year,&rec.date.month,&rec.date.day);
	fflush(stdin);
	printf("演出时间:[%02d:%02d:%02d]",rec.time.hour,rec.time.minute,rec.time.second);
	scanf("%d/%d/%d",&rec.time.hour,&rec.time.minute,&rec.time.second);
	fflush(stdin);
	rec.seat_count=Seat_Srv_FetchValidByRoomID(seatList,rec.studio_id);
	if(Schedule_Srv_Modify(&rec)){
		printf("修改演出计划成功!回车返回\n");
		Ticket_UI_MgtEntry(rec.id);
		rtn=1;
	}
	else{
		printf("修改演出计划失败!回车返回!\n");
	}
	getchar();
	return rtn;
}

int Schedule_UI_Delete(int id) {
	int rtn=0;
	if(Schedule_Srv_DeleteByID(id)){
		printf("演出计划删除成功!\n");
		rtn = 1;
	}else{
		printf("演出计划删除失败!\n");
	}
	getchar();
	return rtn;;
}
int Schedule_UI_Query(int id) {
    play_t *buf;
	if (Play_Srv_FetchByID(id, buf)) {
        printf("抱歉,该剧目不存在!\n");
        return 0;
	}
	Schedule_UI_MgtEntry(id);
	return 1;
}

/*以列表模式显示给定剧目的演出计划信息*/
void Schedule_UI_ListByPlay(play_t *play, schedule_list_t list,
		Pagination_t paging) {
    schedule_list_t pos;
	play_t pla;
	studio_t stu;
	int i;
	char choice;
	paging.totalRecords=Schedule_Srv_FetchByPlay(list,play->id);
	paging.offset=0;
	paging.pageSize=SCHEDULE_PAGE_SIZE;
	Paging_Locate_FirstPage(list,paging);
	do {
		system("cls");
		printf("\n============================================================\n");
		printf("*********************** 演出计划查询 **************************\n");
		printf("%2s  %10s  %10s  %11s  %3s\n","编号","剧名","演出厅名","演出时间","票价");
		printf("--------------------------------------------------------------");
		for(i=0,pos=(schedule_node_t*)(paging.curPos);pos!=list && i<paging.pageSize;i++){
		    Play_Srv_FetchByID(pos->data.play_id,&pla);
		    Studio_Srv_FetchByID(pos->data.studio_id,&stu);
		    printf("%02d  %10s  %10s  %02d/%02d %02d:%02d   %3d\n", pos->data.id, pla.name,stu.name,
		    		pos->data.date.month, pos->data.date.day, pos->data.time.hour, pos->data.time.minute, pla.price);
		    pos = pos->next;
		}
		printf("------- 全部记录:%2d ----------------------- 页数 %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf(
				"******************************************************************\n");
		printf(
				"[P]上一页|[N]下一页|[R]返回");
		printf(
				"\n==================================================================\n");
		printf("功能选择:");//Your Choice
		scanf("%c", &choice);
        fflush(stdin);
		switch (choice) {
		case 'p':
		case 'P':
			if (1 < Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(list, paging, -1, schedule_node_t);
			}
			break;
		case 'n':
		case 'N':
			if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(list, paging, 1, schedule_node_t);
			}
			break;
		}
	}while('r'!=choice && 'R'!=choice);
}

void Schedule_UI_MgtEntry(int play_id) {
    schedule_list_t sch, pos;
	Pagination_t paging;
	play_t pla;
	studio_t stu;
	int i, id;
	char choice;
	List_Init(sch,schedule_node_t);

	paging.offset = 0;
	paging.pageSize = SCHEDULE_PAGE_SIZE;
	paging.totalRecords = Schedule_Srv_FetchByPlay(sch, play_id);
	Paging_Locate_FirstPage(sch, paging);
	do {
        system("cls");
		printf("\n============================================================\n");
		printf("*********************** 演出计划列表 **************************\n");
		printf("%2s  %10s  %10s  %11s  %3s\n","编号","剧名","演出厅名","演出时间","票价");
		printf("--------------------------------------------------------------\n");
		for(i=0, pos=(schedule_node_t*)(paging.curPos); pos != sch && i<paging.pageSize; i++){
		    Play_Srv_FetchByID(pos->data.play_id,&pla);
		    Studio_Srv_FetchByID(pos->data.studio_id,&stu);
		    printf("%2d  %10s  %10s  %02d/%02d %02d:%02d   %3d\n",pos->data.id,pla.name,stu.name,
		    		pos->data.date.month,pos->data.date.day,pos->data.time.hour,pos->data.time.minute,pla.price);
		    pos = pos->next;
		}
		printf("------- 全部记录:%2d ----------------------- 页数 %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf(
				"******************************************************************\n");
		printf(
				"[P]上一页|[N]下一页|[A]添加|[D]删除|[U]修改|[T]查询|[R]返回");
		printf(
				"\n==================================================================\n");
		printf("功能选择:");//Your Choice
		scanf("%c", &choice);
        fflush(stdin);
        switch (choice) {
            case 'a':
            case 'A':
                if (Schedule_UI_Add(play_id)) //新添加成功，跳到最后一页显示
                {
                    paging.totalRecords = Schedule_Srv_FetchByPlay(sch, play_id);
                    Paging_Locate_LastPage(sch, paging, schedule_node_t);
                }
                break;
            case 'd':
            case 'D':
                printf("输入ID:");
                scanf("%d", &id);
                fflush(stdin);
                if (Schedule_UI_Delete(id)) {	//重新载入数据
                    paging.totalRecords = Schedule_Srv_FetchByPlay(sch, play_id);
                    List_Paging(sch, paging, schedule_node_t);
                }
                break;
            case 'u':
            case 'U':
                printf("输入剧目ID:");
                scanf("%d", &id);
                fflush(stdin);
                if (Schedule_UI_Modify(id)) {	//重新载入数据
                    paging.totalRecords = Schedule_Srv_FetchByPlay(sch, play_id);
                    List_Paging(sch, paging, schedule_node_t);
                }
                break;
            case 't':
            case 'T':
                printf("输入剧目ID:");
                scanf("%d", &id);
                fflush(stdin);
                schedule_t *buf;
                if (Schedule_Srv_FetchByID(id, buf)) {
                    Ticket_UI_MgtEntry(id);
                } else {
                    printf("该演出计划不存在!");
                }
                break;
            case 'p':
            case 'P':
                if (1 < Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(sch, paging, -1, schedule_node_t);
                }
                break;
            case 'n':
            case 'N':
                if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(sch, paging, 1, schedule_node_t);
                }
                break;
        }
	} while (choice != 'r' && choice != 'R');
	List_Destroy(sch, schedule_node_t);
}
