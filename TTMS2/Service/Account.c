#include "Account.h"
#include "../Common/List.h"
#include "../Persistence/Account_Persist.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern account_t gl_CurUser;

void Account_Srv_InitSys(){
	if (Account_Perst_CheckAccFile())
		return ;
	account_t data_admin;
	data_admin.type = 9;
	strcpy(data_admin.username, "admin");
	strcpy(data_admin.password, "admin");
	Account_Srv_Add(&data_admin);
}

int Account_Srv_Verify(char usrName[], char pwd[]){
	account_t usr;
	if (Account_Perst_SelByName(usrName, &usr) == 0)
		return 0;
    if (strcmp(usr.password, pwd))
        return 0;
    gl_CurUser = usr;
    return 1;
}

account_node_t * Account_Srv_FindByUsrName(account_list_t list, char usrName[]) {
	account_node_t *pos;
	List_ForEach(list, pos) {
		if (!strcmp(pos->data.username, usrName))
			return pos;
	}
	return NULL;
}

int Account_Srv_Add(const account_t *data){
	return Account_Perst_Insert(data);
}

int Account_Srv_Modify(const account_t *data){
	return Account_Perst_Update(data);
}

int Account_Srv_DeleteByID(int usrID){
	return Account_Perst_DeleteByID(usrID);
}

int Account_Srv_FetchByID(int usrID, account_t *buf){
	return Account_Perst_SelectByID(usrID, buf);
}

int Account_Srv_FetchByName(char usrName[], account_t *buf){
	return Account_Perst_SelByName(usrName, buf);
}

int Account_Srv_FetchAll(account_list_t list){
	return Account_Perst_SelectAll(list);
}


