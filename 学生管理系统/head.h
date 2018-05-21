#define MAX 20
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <errno.h>
typedef struct student {
    char xuehao[9] ;
    char name[MAX] ;
    int total ;
    char Advanced[4] ;
    char C_language_programming[4] ;
    char English[4] ;
    float average ;
}Item ;
typedef struct node1 {
    Item student ;
    struct node1 * next ;
}Node_student;
typedef Node_student * Linklist_student ;
typedef struct account_password {
    char account [9] ;
    char password [MAX] ;
} AAP ;
typedef struct node2 {
    AAP account_password ;
    struct node2 * next ;
} Node_aap ;
typedef Node_aap * Linklist_aap ;
Linklist_student chuangjian () ;                //ѧ������Ĵ���
void entering1 (Linklist_student) ;             //ѧ����Ϣ����
Linklist_student export1 () ;                   //ѧ����Ϣ����
void entering2(Linklist_aap, int) ;             //�˺���Ϣ����
Linklist_aap export2(int) ;                     //�˺���Ϣ����
void add1(Linklist_student) ;                   //����ѧ����Ϣ
void del1(Linklist_student) ;                   //ɾ��ѧ����Ϣ
void change1(Linklist_student) ;                //�޸�ѧ����Ϣ
void add2(Linklist_aap) ;                       //�����˺���Ϣ
void del2(Linklist_aap) ;                       //ɾ���˺���Ϣ
int change2(Linklist_aap, const char *) ;       //�����޸�
void find2(Linklist_aap) ;                      //�����˺���Ϣ
void password_change() ;                        //����Ա�����޸�
void find1(Linklist_student) ;                  //����ѧ����Ϣ
void Performance_analysis(Linklist_student) ;   //�ɼ�����
int Print2(Linklist_aap) ;                      //��ӡ�˺���Ϣ
void sort () ;                                  //��ѧ�������������
void Print1() ;                                 //��ӡѧ����Ϣ
void Print3() ;                                 //��ӡĳ���˺���Ϣ
void show() ;                                   //ϵͳ����
void manager_interface() ;                      //����Ա��¼����
void manager_login() ;                          //����Ա��¼(������֤)
void manager_power() ;                          //����ԱȨ��
void student_interface() ;                      //ѧ����¼����
void register1 () ;                          //�û�ע��
void login (int) ;                              //�û���¼(�˺�������֤)
void student_power (const char *) ;             //ѧ���û�Ȩ�޽���
void teacher_register () ;                      //��ʦ�û�ע��
void teacher_power() ;                          //��ʦ�û�Ȩ��
void password_input(char * p) ;                 //��������
void student_handle() ;                         //ѧ���˺���Ϣ����
void teacher_handle() ;                         //��ʦ�˺���Ϣ����
char * s_gets(char * p, int n) ;                //��ȡ�ַ���
#endif // HEAD_H_INCLUDED
