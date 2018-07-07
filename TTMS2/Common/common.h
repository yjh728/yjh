#ifndef COMMON_H_
#define COMMON_H_

typedef struct {
	int year;
	int month;
	int day;
}ttms_date_t;

typedef struct {
	int hour;
	int minute;
	int second;
}ttms_time_t;

int ScanKeyboard();

char *Str2Upper(char *str);

char *Str2Lower(char *str);

int DateCmp(ttms_date_t dt1, ttms_date_t dt2);

void password_input (char * p);

ttms_date_t DateNow();

ttms_time_t TimeNow();

#endif
