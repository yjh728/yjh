/*
 * common.h
 *
 *  Created on: 2015��4��25��
 *      Author: Administrator
 */

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

//ֱ�Ӷ�ȡ��������ֵ
int ScanKeyboard();

//���ַ���str�͵�ת��Ϊ��д�ַ������������ַ���ͷָ��
char *Str2Upper(char *str);

//���ַ���str�͵�ת��ΪСд�ַ������������ַ���ͷָ��
char *Str2Lower(char *str);

//�Ƚ�����dt1, dt2�Ĵ�С����ȷ���0��dt1<dt2����-1������1
int DateCmp(ttms_date_t dt1, ttms_date_t dt2);

//��������
void password_input (char * p);
//��ȡϵͳ��ǰ����
ttms_date_t DateNow();

//��ȡϵͳ��ǰʱ��
ttms_time_t TimeNow();

#endif /* COMMON_H_ */
