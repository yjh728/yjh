#ifndef SCHEDULE_UI_H_
#define SCHEDULE_UI_H_
#include "../Common/list.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"

static const int SCHEDULE_PAGE_SIZE=5;

int Schedule_UI_Add(int play_id);

int Schedule_UI_Modify(int id);

int Schedule_UI_Delete(int id);

int Schedule_UI_Query(int id);

int Schedule_UI_query(char *play_name);

void Schedule_UI_Show(void);

void Schedule_UI_MgtEntry(int play_id);

/*以列表模式显示给定剧目的演出计划信息*/
void Schedule_UI_ListByPlay(play_t *play, schedule_list_t list, Pagination_t paging);

void Schedule_UI_ListAll(void);

#endif // SCHEDULES_UI_H_

