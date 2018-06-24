#include "SalesAnalysis_UI.h"

#include "../Common/list.h"
#include "../Service/Account.h"
#include "../Service/Ticket.h"
#include "../Service/Play.h"
#include "../Service/Schedule.h"
#include "../Service/Sale.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Service/SalesAnalysis.h"
static const int SALESANALYSIS_PAGE_SIZE = 5;

//统计票房界面
void SalesAnalysis_UI_MgtEntry (){
    salesanalysis_list_t head, pos;
	Pagination_t paging;
    List_Init(head, salesanalysis_node_t);
	paging.pageSize = SALESANALYSIS_PAGE_SIZE;
	paging.totalRecords = SalesAnalysis_Srv_StaticSale(head);
	Paging_Locate_FirstPage(head, paging);
	SalesAnalysis_Srv_SortBySale(head);
	char choice;
	int i;
	do{
		system("cls");
		printf("\n==================================================================\n");
		printf("********************** 票房排行榜 **********************\n");
		printf("--------------------------------------------------------\n");
		printf("%2s %10s %4s %4s %4s %4s\n","编号","名称","区域","销量","票价","票房");
		for(i = 0, pos = (salesanalysis_node_t *)paging.curPos; (pos != head) && (i < paging.pageSize); i++){
			printf("%2s %10s %4s %4ld %4d %4ld\n", pos->data.play_id, pos->data.name,pos->data.area,
                    pos->data.totaltickets, pos->data.price, pos->data.sales);
			pos = pos->next;
		}
		printf("------- 全部记录:%2d ----------------------- 页数 %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf("******************************************************************\n");
		printf("[P]上一页|[N]下一页|[R]返回");
		printf("\n==================================================================\n");
		printf("功能选择:");//Your Choice
		fflush(stdin);
		scanf("%c", &choice);
		switch(choice){
		case 'P':
		case 'p':
			if (1 < Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, salesanalysis_node_t);
			}
			break;
		case 'n':
		case 'N':
			if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, salesanalysis_node_t);
			}
			break;
		}
	} while(choice != 'r' && choice != 'R');
	List_Destroy(head, salesanalysis_node_t);
}
