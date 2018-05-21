#include "head.h"
// 学生端口

extern Linklist_student head ;
extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;
void student_interface () {
    system ("cls") ;
    printf ("\n\n\n\n\n\n\t\t\t\t\t    欢迎进入学生系统\n") ;
    printf ("\t\t\t\t\t   *******************\n") ;
    printf ("\t\t\t\t\t        1.注册   \n\t\t\t\t\t        2.登录\n") ;
    printf ("\t\t\t\t\t        3.返回上一层\n\t\t\t\t\t        0.退出\n") ;
    printf ("\t\t\t\t\t   *******************\n") ;
    printf ("\t\t\t\t\t  请选择你要进行的操作:\n\t\t\t\t\t  ") ;
    int x ;
    fflush (stdin) ;
    do {
        scanf ("%d", &x) ;
        fflush (stdin) ;
        switch (x) {
            case 1 :
                register1 (1) ;
                break ;
            case 2 :
                login (1) ;
                break ;
            case 3 :
                show () ;
                break ;
            case 0 :
                entering1(head) ;
                entering2(aap_s, 1) ;
                entering2(aap_t, 2) ;
                printf ("\n\t\t\t\t\t  您选择了退出!") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t  正在退出...") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t  已退出\n") ;
                exit(0) ;
            default :
                printf ("\t输入有误, 请重新输入:\n\t") ;
                printf("请键入任意键重新进行选择!") ;
                getch() ;
        }
        student_interface() ;
    }
    while (x != 0) ;
}
void student_power(const char * p) {
    system("cls") ;
    puts("\n\n\n\n\n\n\t\t\t\t\t     请选择你要进行的功能:") ;
    puts("\t\t\t\t\t     ****************************") ;
    puts("\t\t\t\t\t           1.查询个人成绩") ;
    puts("\t\t\t\t\t           2.查询全班成绩") ;
    puts("\t\t\t\t\t           3.成绩分析") ;
    puts("\t\t\t\t\t           4.修改密码") ;
    puts("\t\t\t\t\t           5.返回上一层") ;
    puts("\t\t\t\t\t           0.退出") ;
    puts("\t\t\t\t\t     ****************************") ;
    printf("\t\t\t\t\t     ") ;
    int x ;
    do {
        Linklist_student q = head->next ;
        scanf("%d", &x) ;
        fflush(stdin) ;
        if (x == 1 || x == 2) {
            system("cls") ;
            sort() ;
        }
        int count = 1 ;
        switch (x) {
            case 1 :
                while (q && strcmp(p, q->student.xuehao) != 0) {
                    count ++ ;
                    q = q->next ;
                }
                if (q) {
                    printf("\n\n\n\t排名\t\t\t学号\t\t\t姓名\t\t高数\t\tc语言\t\t大英\t\t总分\t\t平均分\n") ;
                    printf("\t%d\t\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n", count, q->student.xuehao, q->student.name,
                        atoi(q->student.Advanced), atoi(q->student.C_language_programming), atoi(q->student.English), q->student.total,
                        q->student.average) ;
                }
                else {
                    puts("\t\t\t\t\t\t    抱歉, 找不到该学生!") ;
                    puts("\t\t\t\t\t\t    请键入任意键返回上一层!") ;
                    getch() ;
                    student_power(p) ;
                }
                printf("\t请键入任意键返回上一层\n") ;
                getch() ;
                break ;
            case 2 :
                Print1() ;
                break ;
            case 3 :
                Performance_analysis(head) ;
                break ;
            case 4 :
                if (change2(aap_s, p)) {
                    entering2(aap_s, 1) ;
                    student_interface() ;
                }
                break ;
            case 5 :
                student_interface() ;
                break ;
            case 0 :
                entering1(head) ;
                puts("\t\t\t\t\t     您选择了退出!") ;
                sleep(1) ;
                puts("\t\t\t\t\t     正在退出...") ;
                sleep(1) ;
                puts("\t\t\t\t\t     已退出\n") ;
                exit (0) ;
            default :
                puts("\t\t\t\t\t     输入错误, 请重新选择:") ;
                printf("\t\t\t\t\t     请键入任意键重新进行选择:") ;
                getch() ;
        }
        student_power(p) ;
    }
    while (x != 0) ;
}
