#include "head.h"
//教师端口
extern Linklist_student head ;
extern Linklist_aap aap_t ;
extern Linklist_aap aap_s ;
void teacher_power (const char * p) {
    system ("cls") ;
    puts ("\n\n\n\n\n\n\t\t\t\t\t     **************************") ;
    puts ("\t\t\t\t\t           1.学生信息录入") ;
    puts ("\t\t\t\t\t           2.增添学生信息") ;
    puts ("\t\t\t\t\t           3.删除学生信息") ;
    puts ("\t\t\t\t\t           4.修改学生信息") ;
    puts ("\t\t\t\t\t           5.查找学生信息") ;
    puts ("\t\t\t\t\t           6.打印学生信息") ;
    puts ("\t\t\t\t\t           7.成绩分析") ;
    puts ("\t\t\t\t\t           8.修改密码") ;
    puts ("\t\t\t\t\t           9.返回上一层") ;
    puts ("\t\t\t\t\t           0.退出") ;
    puts ("\t\t\t\t\t     **************************") ;
    printf ("\n\t\t\t\t\t     请选择你要进行的操作:\n\t\t\t\t\t     ") ;
    int x ;
    do {
        scanf ("%d", &x) ;
        fflush (stdin) ;
        switch (x) {
            case 1 :
                head = chuangjian () ;
                break ;
            case 2 :
                add1 (head) ;
                break ;
            case 3 :
                del1 (head) ;
                break ;
            case 4 :
                change1 (head) ;
                break ;
            case 5 :
                find1 (head) ;
                break ;
            case 6 :
                sort() ;
                Print1 () ;
                break ;
            case 7 :
                Performance_analysis(head) ;
                break ;
            case 8 :
                if (change2(aap_t, p)) {
                    entering2(aap_t, 2) ;
                    show() ;
                }
                break ;
            case 9 :
                show() ;
                break ;
            case 0 :
                entering1(head) ;
                printf("\n\t\t\t\t\t     您选择了退出!") ;
                sleep(1) ;
                printf("\n\t\t\t\t\t     正在退出...") ;
                sleep(1) ;
                printf("\n\t\t\t\t\t     已退出\n") ;
                exit (0) ;
            default :
                printf ("\t\t\t\t\t输入有误, 请重新输入:\n");
                printf("请键入任意键重新进行选择!") ;
                getch() ;
        }
        teacher_power(p) ;
    }
    while (x != 0) ;
}
