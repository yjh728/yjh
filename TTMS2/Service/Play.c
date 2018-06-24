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

//根据剧目名称载入剧目，返回载入的剧目数量
int Play_Srv_FetchByName(play_list_t list, char condt[]){
	return Play_Perst_SelectByName(list, condt);
}

//根据剧目名称过滤词filter对list进行过滤，返回过滤后剩余的剧目数量
int Play_Srv_FilterByName(play_list_t list, char filter[]){
	return 0;
}


