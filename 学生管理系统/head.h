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
Linklist_student chuangjian () ;                //学生链表的创建
void entering1 (Linklist_student) ;             //学生信息导出
Linklist_student export1 () ;                   //学生信息导入
void entering2(Linklist_aap, int) ;             //账号信息导出
Linklist_aap export2(int) ;                     //账号信息导入
void add1(Linklist_student) ;                   //增加学生信息
void del1(Linklist_student) ;                   //删除学生信息
void change1(Linklist_student) ;                //修改学生信息
void add2(Linklist_aap) ;                       //增加账号信息
void del2(Linklist_aap) ;                       //删除账号信息
int change2(Linklist_aap, const char *) ;       //密码修改
void find2(Linklist_aap) ;                      //查找账号信息
void password_change() ;                        //管理员密码修改
void find1(Linklist_student) ;                  //查找学生信息
void Performance_analysis(Linklist_student) ;   //成绩分析
int Print2(Linklist_aap) ;                      //打印账号信息
void sort () ;                                  //对学生链表进行排序
void Print1() ;                                 //打印学生信息
void Print3() ;                                 //打印某个账号信息
void show() ;                                   //系统界面
void manager_interface() ;                      //管理员登录界面
void manager_login() ;                          //管理员登录(密码验证)
void manager_power() ;                          //管理员权限
void student_interface() ;                      //学生登录界面
void register1 () ;                          //用户注册
void login (int) ;                              //用户登录(账号密码验证)
void student_power (const char *) ;             //学生用户权限界面
void teacher_register () ;                      //教师用户注册
void teacher_power() ;                          //教师用户权限
void password_input(char * p) ;                 //密码输入
void student_handle() ;                         //学生账号信息管理
void teacher_handle() ;                         //教师账号信息管理
char * s_gets(char * p, int n) ;                //获取字符串
#endif // HEAD_H_INCLUDED
