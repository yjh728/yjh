#include "Play.h"
#include "../Common/List.h"
#include "../Persistence/Play_Persist.h"
#include <string.h>


int Play_Srv_Add(play_t *data) {
	return Play_Perst_Insert(data);
}

int Play_Srv_Modify(play_t *data) {
	return Play_Perst_Update(data);
}

int Play_Srv_DeleteByID(int ID) {
	return Play_Perst_RemByID(ID);
}

int Play_Srv_FetchByID(int ID, play_t *buf) {
	return Play_Perst_SelectByID(ID, buf);
}

int Play_Srv_FetchAll(play_list_t list) {
	return Play_Perst_SelectAll(list);
}

int Play_Srv_FetchByName(play_list_t list, char condt[]){
	return Play_Perst_SelectByName(list, condt);
}
