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
		printf("********************** �ݳ����б� **********************\n");
		printf("%5s  %-18s  %-10s  %-5s  %-5s\n", "���", "�ݳ�����", "����",
				"����", "��λ��");
		printf("------------------------------------------------------------------\n");
		for (i = 0, pos = (studio_node_t *) (paging.curPos);
				pos != head && i < paging.pageSize; i++) {
			printf("%5d  %-18s  %-5d  %-5d  %-10d\n", pos->data.id,
					pos->data.name, pos->data.rowsCount, pos->data.colsCount,
					pos->data.seatsCount);
			pos = pos->next;
		}
		printf("\n------- ȫ����¼:%2d ----------------------- ҳ�� %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf(
				"******************************************************************\n");
		if(gl_CurUser.type!=9){
				printf("[P]��һҳ|[N]��һҳ|[R]����");
		}else{
			printf(
							"[P]��һҳ|[N]��һҳ | [A]���|[D]ɾ��|[U]�޸� | [S]��λ | [R]����");
		}

		printf(
				"\n==================================================================\n");
		printf("����ѡ��:");
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
			printf("����ID:");
			scanf("%d", &id);
			fflush(stdin);
			if (Studio_UI_Delete(id)) {
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t);
			}
			break;
			case 'u':
			case 'U':
			printf("����ID:");
			scanf("%d", &id);
			fflush(stdin);
			if (Studio_UI_Modify(id)) {
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t);
			}
			break;
			case 's':
			case 'S':
			printf("����ID:");
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
		printf("********************  ����ݳ���  *********************\n");
		printf("-------------------------------------------------------\n");
		printf("�ݳ�������:");
		gets(rec.name);
		fflush(stdin);
		printf("��λ����:");
		scanf("%d", &(rec.rowsCount));
		fflush(stdin);
		printf("��λ����:");
		scanf("%d", &(rec.colsCount));
		fflush(stdin);
		rec.seatsCount = 0;
		printf("=======================================================\n");
		if (Studio_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("����ݳ����ɹ�!\n");
		} else
			printf("����ݳ���ʧ��!\n");
		printf("-------------------------------------------------------\n");
		printf("[A]��Ӹ���, [R]����:");
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
		printf("������䲻����!\n����[Enter]������!\n");
		getchar();
		return 0;
	}
	printf("\n=======================================================\n");
	printf("*********************  �����ݳ���  *********************\n");
	printf("-------------------------------------------------------\n");
	printf("�ݳ���ID:%d\n", rec.id);
	printf("�ݳ�������[%s]:", rec.name);
	gets(rec.name);
	fflush(stdin);
	List_Init(list, seat_node_t);
	seatcount = Seat_Srv_FetchByRoomID(list, rec.id);
	if (seatcount) {
		do {
			printf("��λ����Ӧ�� >= [%d]:", rec.rowsCount);
			scanf("%d", &(newrow));
			fflush(stdin);
			printf("��λ����Ӧ�� >= [%d]:", rec.colsCount);
			scanf("%d", &(newcolumn));
			fflush(stdin);
		} while (newrow < rec.rowsCount || newcolumn < rec.colsCount);
		rec.rowsCount = newrow;
		rec.colsCount = newcolumn;
		rec.seatsCount = seatcount;
	} else {
		printf("��λ����:");
		scanf("%d", &rec.rowsCount);
		fflush(stdin);
		printf("��λ����:");
		scanf("%d", &rec.colsCount);
		fflush(stdin);
		rec.seatsCount = 0;
	}
	printf("-------------------------------------------------------\n");
	if (Studio_Srv_Modify(&rec)) {
		rtn = 1;
		printf(
				"�ݳ������ݸ��³ɹ�!\n����[Enter]����!\n");
	} else
		printf("�ݳ������ݸ���ʧ��!\n����[Enter]����!\n");
	getchar();
	return rtn;
}

int Studio_UI_Delete(int id) {
	int rtn = 0;
	if (Studio_Srv_DeleteByID(id)) {
		if (Seat_Srv_DeleteAllByRoomID(id))
			printf("�ݳ�����λɾ���ɹ�!\n");
		printf(
				"�ݳ���ɾ���ɹ�!\n����[Enter]����!\n");
		rtn = 1;
	} else {
		printf("�ݳ���ɾ��ʧ��!\n����[Enter]����!\n");
	}
	getchar();
	return rtn;
}

