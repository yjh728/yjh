/*/*
 * Account_UI.c
 *
 *  Created on: 2015��4��24��
 *      Author: Administrator
 */
#include "../View/Account_UI.h"

#include "../Common/List.h"
#include "../Service/Account.h"
#include <stdio.h>
#include "../Common/common.h"
static const char ACCOUNT_KEY_NAME[] = "Account";
extern account_t gl_CurUser;
//ϵͳ��¼
int SysLogin(){
	Account_Srv_InitSys();
	for(int i = 0; i < 3; i++) {
		char name[30];
		char pwd[30];
		printf("\n�˺ţ�");
		gets(name);
		fflush(stdin);
		printf("���룺");
		password_input(pwd);
		fflush(stdin);
		if (Account_Srv_Verify(name, pwd))
			return 1;
        printf("\n�˺Ż�������������㻹��%d�λ���!\n", 2-i);
	}
	return 0;
}

//ϵͳ�û��������
void Account_UI_MgtEntry(int flag){
    account_list_t head;
    account_list_t pos;
    Pagination_t paging;
    int i;
    char choice, name[30];
    List_Init(head,account_node_t);
    paging.offset=0;
    paging.pageSize=ACCOUNT_PAGE_SIZE;
    paging.totalRecords = Account_Srv_FetchAll(head);
    Paging_Locate_FirstPage(head,paging);
	if (flag == 1) {
		system("cls");
		printf("\n========================================================\n");
		printf("************************ �ҵ���Ϣ ************************\n");
		printf("%5s  %10s  %10s  %10s\n", "���", "�û���", "����", "ְλ");
		printf("--------------------------------------------------------\n");
		printf("%5d  %10s  %10s  %10d\n", gl_CurUser.id, gl_CurUser.username,
				gl_CurUser.password, gl_CurUser.type);
		printf("--------------------------------------------------------\n");
		printf("\n[M]�޸�����|[R]����\n");
		printf("�����빦��ѡ��:");
		scanf("%c", &choice);
		fflush(stdin);
		if(choice=='M' || choice=='m'){
			Account_UI_Modify(head,gl_CurUser.username);
			return;
		}
		return;
	}
    else
    do {
    	system("cls");
        printf("\n========================================================\n");
        printf("************************�û��б�************************\n");
        printf("%5s  %10s  %10s  %10s\n","���","�û���","����","ְλ");
        printf("--------------------------------------------------------\n");
        for(i=0,pos=(account_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
            printf("%5d  %10s  %10s  %10d\n",pos->data.id,pos->data.username,pos->data.password,pos->data.type);
			pos = pos->next;

        }
		//printf("--------------------------------------------------------\n");
		printf("\n------- ȫ����¼:%d ----------------------- ҳ�� %d/%d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
        printf("*********************************************************\n");
        printf("\n[A]����|[M]�޸�|[D]ɾ��|[Q]��ѯ|[P]��һҳ|[N]��һҳ|[R]����\n");
        printf("�����빦��ѡ��:");
        scanf("%c",&choice);
        fflush(stdin);
        switch(choice){
            case 'A':
            case 'a':
            	if(Account_UI_Add(head)){
            		paging.totalRecords = Account_Srv_FetchAll(head);
            		Paging_Locate_LastPage(head, paging, account_node_t);
            	}
        		break;
            case 'M':
            case 'm':
                printf("������Ҫ�޸�������û���:");
                gets(name);
                fflush(stdin);
                if(Account_UI_Modify(head,name)){
                    paging.totalRecords = Account_Srv_FetchAll(head);
                    List_Paging(head, paging, account_node_t);
                }
                break;
            case 'D':
            case 'd':
                printf("������Ҫɾ�����û���:");
                gets(name);
                fflush(stdin);
                if(Account_UI_Delete(head,name)){
    				paging.totalRecords = Account_Srv_FetchAll(head);
    				List_Paging(head, paging, account_node_t);
                }
                break;
            case 'Q':
            case 'q':
                printf("������Ҫ��ѯ���û���:");
                gets(name);
                fflush(stdin);
                Account_UI_Query(head,name);
                break;
            case 'P':
            case 'p':
    			if (1 < Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(head,paging,-1,account_node_t);
                }
                break;
            case 'N':
            case 'n':
    			if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
                    Paging_Locate_OffsetPage(head,paging,1,account_node_t);
                }
                break;
        }


    }while(choice!='R' && choice!='r');
    List_Destroy(head,account_node_t);
}

//�����ϵͳ�û�����
int  Account_UI_Add(account_list_t list){
    system("cls");
	account_node_t *p;
	char name[30];
	printf("��������Ҫ��ӵ��˻�����");
	scanf("%s", name);
	fflush(stdin);
	p = Account_Srv_FindByUsrName(list, name);
	if (p != NULL) {
        printf("���û��Ѵ���!");
        return 0;
	}
	p = (account_node_t *) malloc(sizeof(account_node_t));
	strcpy(p->data.username, name);
	printf("��������ӵ��û�����:");
	printf("0.�����û�\n");
	printf("1.��ƱԱ\n");
	printf("2.����\n");
	printf("9.ϵͳ����Ա\n");
	scanf("%d", &p->data.type);
	fflush(stdin);
	printf("�������û�������:");
	password_input(p->data.password);
	fflush(stdin);
	Account_Srv_Add(&p->data);
	Account_Perst_SelectAll(list);
	return 0;
}

//�޸�ϵͳ�û�����
int Account_UI_Modify(account_list_t list,char usrName[]){
	account_node_t *p;
	p = Account_Srv_FindByUsrName(list, usrName);
	if (p == NULL) {
        printf("���û�������!");
        return 0;
	}
	printf("������������:");
	password_input(p->data.password);
	fflush(stdin);
	if (Account_Srv_Modify(&p->data)) {
        printf("�޸ĳɹ�!���������ֵ������һ��!");
        Account_Perst_SelectAll(list);
        getchar();
	} else {
        printf("�޸�ʧ��!�������һ�㷵����һ��!");
        getchar();
	}
	return 0;
}

//ɾ��ϵͳ�û�����
int Account_UI_Delete(account_list_t list,char usrName[]){
	account_node_t *p = Account_Srv_FindByUsrName(list, usrName);
	if (p == NULL) {
        printf("���û�������!");
        return 0;
	}
    if (Account_Srv_DeleteByID(p->data.id)) {
        printf("��ɾ��!����������������һ��!");
        getchar();
    } else {
        printf("ɾ��ʧ��!���������㷵����һ��!");
        getchar();
    }
    List_DelNode(p);
    List_FreeNode(p);
	return 0;
}

//��ѯϵͳ�û�����
int Account_UI_Query(account_list_t list,char usrName[]){
	account_node_t *p = Account_Srv_FindByUsrName(list, usrName);
	if (p == NULL) {
        printf("���û�������!");
        return 0;
	}
	printf("ID    ְλ    �û���           ����\n");
	printf("%d\t%d\t%s\t%s\n", p->data.id, p->data.type, p->data.username ,p->data.password);
	printf("����������������һ��!");
	getchar();
	return 0;
}


