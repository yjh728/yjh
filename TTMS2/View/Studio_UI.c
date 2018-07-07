#include "../View/Studio_UI.h"

#include "../Common/List.h"
#include "../Service/Studio.h"
#include "../Service/Seat.h"
#include "../Service/Account.h"
#include <stdio.h>
static const int STUDIO_PAGE_SIZE = 5;
extern account_t gl_CurUser;
void Studio_UI_MgtEntry(void) {
	int i, id;
	char choice;
	studio_list_t head;
	studio_node_t *pos;
	Pagination_t paging;
	List_Init(head, studio_node_t);
	paging.offset = 0;
	paging.pageSize = STUDIO_PAGE_SIZE;
	paging.totalRecords = Studio_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);
	do {
		system("cls");
		printf("\n==================================================================\n");
		printf("********************** 演出厅列表 **********************\n");
		printf("%5s  %-18s  %-10s  %-5s  %-5s\n", "编号", "演出厅名", "行数",
				"列数", "座位数");
		printf("------------------------------------------------------------------\n");
		for (i = 0, pos = (studio_node_t *) (paging.curPos);
				pos != head && i < paging.pageSize; i++) {
			printf("%5d  %-18s  %-5d  %-5d  %-10d\n", pos->data.id,
					pos->data.name, pos->data.rowsCount, pos->data.colsCount,
					pos->data.seatsCount);
			pos = pos->next;
		}
		printf("\n------- 全部记录:%2d ----------------------- 页数 %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf(
				"******************************************************************\n");
		if(gl_CurUser.type!=9){
				printf("[P]上一页|[N]下一页|[R]返回");
		}else{
			printf(
							"[P]上一页|[N]下一页 | [A]添加|[D]删除|[U]修改 | [S]座位 | [R]返回");
		}

		printf(
				"\n==================================================================\n");
		printf("功能选择:");
		scanf("%c", &choice);
		fflush(stdin);
		switch (choice) {
		if(gl_CurUser.type==9){
			case 'a':
			case 'A':
			if (Studio_UI_Add())
			{
				paging.totalRecords = Studio_Srv_FetchAll(head);
				Paging_Locate_LastPage(head, paging, studio_node_t);
			}
			break;
			case 'd':
			case 'D':
			printf("输入ID:");
			scanf("%d", &id);
			fflush(stdin);
			if (Studio_UI_Delete(id)) {
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t);
			}
			break;
			case 'u':
			case 'U':
			printf("输入ID:");
			scanf("%d", &id);
			fflush(stdin);
			if (Studio_UI_Modify(id)) {
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t);
			}
			break;
			case 's':
			case 'S':
			printf("输入ID:");
			scanf("%d", &id);
			fflush(stdin);
			Seat_UI_MgtEntry(id);
			paging.totalRecords = Studio_Srv_FetchAll(head);
			List_Paging(head, paging, studio_node_t);
			break;
		}
		case 'p':
		case 'P':
			if (1 < Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, studio_node_t);
			}
			break;
		case 'n':
		case 'N':
			if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, studio_node_t);
			}
			break;
		}
	} while (choice != 'r' && choice != 'R');
	List_Destroy(head, studio_node_t);
}

int Studio_UI_Add(void) {
	studio_t rec;
	int newRecCount = 0;
	char choice;
	do {
        system("cls");
		printf("\n=======================================================\n");
		printf("********************  添加演出厅  *********************\n");
		printf("-------------------------------------------------------\n");
		printf("演出厅名字:");
		gets(rec.name);
		fflush(stdin);
		printf("座位行数:");
		scanf("%d", &(rec.rowsCount));
		fflush(stdin);
		printf("座位列数:");
		scanf("%d", &(rec.colsCount));
		fflush(stdin);
		rec.seatsCount = 0;
		printf("=======================================================\n");
		if (Studio_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("添加演出厅成功!\n");
		} else
			printf("添加演出厅失败!\n");
		printf("-------------------------------------------------------\n");
		printf("[A]添加更多, [R]返回:");
		scanf("%c", &choice);
		fflush(stdin);
	} while ('a' == choice || 'A' == choice);
	return newRecCount;
}

int Studio_UI_Modify(int id) {
	studio_t rec;
	int rtn = 0;
	int newrow, newcolumn;
	seat_list_t list;
	int seatcount;
	if (!Studio_Srv_FetchByID(id, &rec)) {
		printf("这个房间不存在!\n键入[Enter]键返回!\n");
		getchar();
		return 0;
	}
	printf("\n=======================================================\n");
	printf("*********************  更新演出厅  *********************\n");
	printf("-------------------------------------------------------\n");
	printf("演出厅ID:%d\n", rec.id);
	printf("演出厅名字[%s]:", rec.name);
	gets(rec.name);
	fflush(stdin);
	List_Init(list, seat_node_t);
	seatcount = Seat_Srv_FetchByRoomID(list, rec.id);
	if (seatcount) {
		do {
			printf("座位行数应该 >= [%d]:", rec.rowsCount);
			scanf("%d", &(newrow));
			fflush(stdin);
			printf("座位列数应该 >= [%d]:", rec.colsCount);
			scanf("%d", &(newcolumn));
			fflush(stdin);
		} while (newrow < rec.rowsCount || newcolumn < rec.colsCount);
		rec.rowsCount = newrow;
		rec.colsCount = newcolumn;
		rec.seatsCount = seatcount;
	} else {
		printf("座位行数:");
		scanf("%d", &rec.rowsCount);
		fflush(stdin);
		printf("座位列数:");
		scanf("%d", &rec.colsCount);
		fflush(stdin);
		rec.seatsCount = 0;
	}
	printf("-------------------------------------------------------\n");
	if (Studio_Srv_Modify(&rec)) {
		rtn = 1;
		printf(
				"演出厅数据更新成功!\n键入[Enter]返回!\n");
	} else
		printf("演出厅数据更新失败!\n键入[Enter]返回!\n");
	getchar();
	return rtn;
}

int Studio_UI_Delete(int id) {
	int rtn = 0;
	if (Studio_Srv_DeleteByID(id)) {
		if (Seat_Srv_DeleteAllByRoomID(id))
			printf("演出厅座位删除成功!\n");
		printf(
				"演出厅删除成功!\n键入[Enter]返回!\n");
		rtn = 1;
	} else {
		printf("演出厅删除失败!\n键入[Enter]返回!\n");
	}
	getchar();
	return rtn;
}

