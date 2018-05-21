#include "head.h"

Linklist_student head = NULL ;      //学生信息链表
Linklist_aap aap_s = NULL ;         //学生账号信息链表
Linklist_aap aap_t = NULL ;         //教师账号信息链表
int changdu  = 0 ;

int main()
{
    head = export1() ;              //学生信息从文件导入链表
    aap_s = export2(1) ;            //学生账号导入链表
    aap_t = export2(2) ;            //教师账号导入链表
    show() ;                        //学生管理系统界面
    return 0 ;
}
