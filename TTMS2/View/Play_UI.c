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
		printf("*********************** 剧目列表 **************************\n");
		printf("%2s  %-10s  %-4s  %-6s  %-4s  %-4s  %-6s  %-6s     %-8s\n","编号","名称","类型","地区","级别","时长",
					"上映日期","结束日期","票价");
		printf("--------------------------------------------------------\n");
		for(i = 0, pos = (play_node_t*)(paging.curPos); pos != head && i < paging.pageSize; i++) {
			printf("%-2d    %-10s  %-4d  %-6s  %-4d  %-3d  %4d/%02d/%02d  %4d/%02d/%02d  %-2d\n",pos->data.id
					,pos->data.name,pos->data.type,pos->data.area,pos->data.rating
					,pos->data.duration,pos->data.start_date.year,pos->data.start_date.month,pos->data.start_date.day
					,pos->data.end_date.year,pos->data.end_date.month,pos->data.end_date.day,pos->data.price);
			pos = pos->next;
		}
		printf("------- 全部记录:%2d ----------------------- 页数 %d/%d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf("*************************************************************\n");
		printf("[P]上一页|[N]下一页|[A]添加|[D]删除|[U]修改|[Q]查询|[Y]安排演出|[R]返回");
		printf("\n===========================================================\n");
		printf("功能选择:");//Your Choice
        scanf(" %c", &choice);
        fflush(stdin);
		switch (choice) {
            case 'a':
            case 'A':
                if (Play_UI_Add()) //新添加成功，跳到最后一页显示
                {
                    paging.totalRecords = Play_Srv_FetchAll(head);
                    Paging_Locate_LastPage(head, paging, play_node_t);
                }
                break;
            case 'd':
            case 'D':
                printf("输入ID:");
                scanf("%d", &id);
                fflush(stdin);
                if (Play_UI_Delete(id)) {	//重新载入数据
                    paging.totalRecords = Play_Srv_FetchAll(head);
                    List_Paging(head, paging, play_node_t);
                }
                break;
            case 'u':
            case 'U':
                printf("输入剧目ID:");
                scanf("%d", &id);
                fflush(stdin);
                if (Play_UI_Modify(id)) {	//重新载入数据
                    paging.totalRecords = Play_Srv_FetchAll(head);
                    List_Paging(head, paging, play_node_t);
                }
                break;
            case 'q':
            case 'Q':
                printf("输入剧目ID:");
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
                printf("请输入你要管理的演出计划的剧目id:");
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
		printf("\t****************  添加新剧目 ***************\n");
		printf("-------------------------------------------------------\n");
		printf("剧目名称:");
		gets(rec.name);
		fflush(stdin);
		printf("剧目类型(1表示电影,2歌剧,3音乐会):");
		scanf("%d", &(rec.type));
		fflush(stdin);
		printf("来源地区:");
		gets(rec.area);
		fflush(stdin);
		printf("剧目级别(1表示儿童,2青少年,3成人):");
		scanf("%d", &(rec.rating));
		fflush(stdin);
		printf("演出时长(分钟):");
		scanf("%d", &(rec.duration));
		fflush(stdin);
		printf("上映日期:(yyyy/mm/dd):");
		scanf("%d/%d/%d",&rec.start_date.year,&rec.start_date.month,&rec.start_date.day);
		fflush(stdin);
		printf("结束日期:(yyyy/mm/dd):");
		scanf("%d/%d/%d",&rec.end_date.year,&rec.end_date.month,&rec.end_date.day);
		fflush(stdin);
		printf("票价:");
		scanf("%d",&rec.price);
		fflush(stdin);
		printf("=======================================================\n");
		if (Play_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("新剧目添加成功!\n");
		} else
			printf("新剧目添加失败!\n");
		printf("-------------------------------------------------------\n");
		fflush(stdin);
		printf("[A]添加更多, [R]返回:");
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
		printf("该剧目不存在!\n按[Enter]键返回!\n");
		getchar();
		return 0;
	}
	system("cls");
	printf("\n=======================================================\n");
	printf("\t****************  修改剧目  ****************\n");
	printf("-------------------------------------------------------\n");
	printf("剧目编号:%d\n", rec->id);
	printf("剧目名称:[%s]",rec->name);
	gets(rec->name);
	fflush(stdin);
	printf("剧目类型(1表示电影,2歌剧,3音乐会):[%d]",rec->type);
	scanf("%d", &(rec->type));
	fflush(stdin);
	printf("来源地区:[%s]",rec->area);
	gets(rec->area);
	fflush(stdin);
	printf("剧目级别(1表示儿童,2青少年,3音乐会)[%d]:",rec->rating);
	scanf("%d", &(rec->rating));
	fflush(stdin);
	printf("演出时长(分钟):[%d]",rec->duration);
	scanf("%d", &(rec->duration));
	fflush(stdin);
	printf("上映日期:(yyyy/mm/dd):[%04d/%02d/%02d]",rec->start_date.year,rec->start_date.month,rec->start_date.day);

	scanf("%d/%d/%d",&rec->start_date.year,&rec->start_date.month,&rec->start_date.day);
	fflush(stdin);
	printf("结束日期:(yyyy/mm/dd)::[%04d/%02d/%02d]",rec->end_date.year,rec->end_date.month,rec->end_date.day);

	scanf("%d/%d/%d",&rec->end_date.year,&rec->end_date.month,&rec->end_date.day);
	fflush(stdin);
	printf("-------------------------------------------------------\n");
	if (Play_Srv_Modify(rec)) {
		rtn = 1;
		printf("剧目数据修改成功!\n按[Enter]返回!\n");
	} else
		printf("剧目数据修改失败!\n按[Enter]返回\n");
	getchar();
	return rtn;
}

int Play_UI_Delete(int id) {
    int rtn = 0;
	if(Play_Srv_DeleteByID(id)){
		printf("剧目删除成功!\n");
		if(Schedule_Srv_DeleteByID(id)) {
			printf("演出计划删除成功!按回车返回!\n");
            rtn = 1;
		} else {
            printf("该演出计划不存在!按回车返回!\n");//The room does not exist!\nPress [Enter] key to return
        }
	} else{
		printf("剧目删除失败!\n");
		return 0;
	}
	getchar();
	return rtn;
}

/*
 * Function:    Play_UI_Query
 * Function ID:	TTMS_SCU_Play_UI_Qry
 * Description: 按照ID号查询剧目信息
 * Input:       待查找的剧目ID号
 * Output:      查找到的剧目信息
 * Return:      0表示未找到，1表示找到了
 */
int Play_UI_Query(int id){
    int rtn=0;
    play_t data;
    play_t *buf = &data;
    char choice;
    rtn = Play_Srv_FetchByID(id, &data);
    system("cls");
	printf("\n============================================================\n");
	printf("*********************** 剧目查询 **************************\n");
	printf("%6s  %10s  %4s  %6s  %4s  %4s  %6s  %6s      %4s\n","编号","名称","类型","地区","级别","时长",
				"上映日期","结束日期","票价");
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
