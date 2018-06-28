/*/*
 * Account_UI.c
 *
 *  Created on: 2015年4月24日
 *      Author: Administrator
 */
#include "../View/Account_UI.h"

#include "../Common/List.h"
#include "../Service/Account.h"
#include <stdio.h>
#include "../Common/common.h"
static const char ACCOUNT_KEY_NAME[] = "Account";
extern account_t gl_CurUser;
//系统登录
int SysLogin(){
	Account_Srv_InitSys();
	for(int i = 0; i < 3; i++) {
		char name[30];
		char pwd[30];
		printf("\n账号：");
		gets(name);
		fflush(stdin);
		printf("密码：");
		password_input(pwd);
		fflush(stdin);
		if (Account_Srv_Verify(name, pwd))
			return 1;
        printf("\n账号或密码输入错误，你还有%d次机会!\n", 2-i);
	}
	return 0;
}

//系统用户管理界面
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
		printf("************************ 我的信息 ************************\n");
		printf("%5s  %10s  %10s  %10s\n", "编号", "用户名", "密码", "职位");
		printf("--------------------------------------------------------\n");
		printf("%5d  %10s  %10s  %10d\n", gl_CurUser.id, gl_CurUser.username,
				gl_CurUser.password, gl_CurUser.type);
		printf("--------------------------------------------------------\n");
		printf("\n[M]修改密码|[R]返回\n");
		printf("请输入功能选项:");
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
        printf("************************用户列表************************\n");
        printf("%5s  %10s  %10s  %10s\n","编号","用户名","密码","职位");
        printf("--------------------------------------------------------\n");
        for(i=0,pos=(account_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
            printf("%5d  %10s  %10s  %10d\n",pos->data.id,pos->data.username,pos->data.password,pos->data.type);
			pos = pos->next;

        }
		//printf("--------------------------------------------------------\n");
		printf("\n------- 全部记录:%d ----------------------- 页数 %d/%d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
        printf("*********************************************************\n");
        printf("\n[A]新增|[M]修改|[D]删除|[Q]查询|[P]上一页|[N]下一页|[R]返回\n");
        printf("请输入功能选项:");
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
                printf("请输入要修改密码的用户名:");
                gets(name);
                fflush(stdin);
                if(Account_UI_Modify(head,name)){
                    paging.totalRecords = Account_Srv_FetchAll(head);
                    List_Paging(head, paging, account_node_t);
                }
                break;
            case 'D':
            case 'd':
                printf("请输入要删除的用户名:");
                gets(name);
                fflush(stdin);
                if(Account_UI_Delete(head,name)){
    				paging.totalRecords = Account_Srv_FetchAll(head);
    				List_Paging(head, paging, account_node_t);
                }
                break;
            case 'Q':
            case 'q':
                printf("请输入要查询的用户名:");
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

//添加新系统用户界面
int  Account_UI_Add(account_list_t list){
    system("cls");
	account_node_t *p;
	char name[30];
	printf("请输入你要添加的账户名：");
	scanf("%s", name);
	fflush(stdin);
	p = Account_Srv_FindByUsrName(list, name);
	if (p != NULL) {
        printf("该用户已存在!");
        return 0;
	}
	p = (account_node_t *) malloc(sizeof(account_node_t));
	strcpy(p->data.username, name);
	printf("请输入添加的用户类型:");
	printf("0.匿名用户\n");
	printf("1.售票员\n");
	printf("2.经理\n");
	printf("9.系统管理员\n");
	scanf("%d", &p->data.type);
	fflush(stdin);
	printf("请输入用户名密码:");
	password_input(p->data.password);
	fflush(stdin);
	Account_Srv_Add(&p->data);
	Account_Perst_SelectAll(list);
	return 0;
}

//修改系统用户界面
int Account_UI_Modify(account_list_t list,char usrName[]){
	account_node_t *p;
	p = Account_Srv_FindByUsrName(list, usrName);
	if (p == NULL) {
        printf("该用户不存在!");
        return 0;
	}
	printf("请输入新密码:");
	password_input(p->data.password);
	fflush(stdin);
	if (Account_Srv_Modify(&p->data)) {
        printf("修改成功!请键入任意值返回上一层!");
        Account_Perst_SelectAll(list);
        getchar();
	} else {
        printf("修改失败!请键入上一层返回上一层!");
        getchar();
	}
	return 0;
}

//删除系统用户界面
int Account_UI_Delete(account_list_t list,char usrName[]){
	account_node_t *p = Account_Srv_FindByUsrName(list, usrName);
	if (p == NULL) {
        printf("该用户不存在!");
        return 0;
	}
    if (Account_Srv_DeleteByID(p->data.id)) {
        printf("已删除!请键入任意键返回上一层!");
        getchar();
    } else {
        printf("删除失败!请键入任意层返回上一层!");
        getchar();
    }
    List_DelNode(p);
    List_FreeNode(p);
	return 0;
}

//查询系统用户界面
int Account_UI_Query(account_list_t list,char usrName[]){
	account_node_t *p = Account_Srv_FindByUsrName(list, usrName);
	if (p == NULL) {
        printf("该用户不存在!");
        return 0;
	}
	printf("ID    职位    用户名           密码\n");
	printf("%d\t%d\t%s\t%s\n", p->data.id, p->data.type, p->data.username ,p->data.password);
	printf("请键入任意键返回上一层!");
	getchar();
	return 0;
}


