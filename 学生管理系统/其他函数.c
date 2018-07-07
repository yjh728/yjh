#include "head.h"

extern Linklist_student head ;
extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;

void show () {				//系统界面
    system("cls") ;
    printf("\n\n\n\n\n\n\t\t\t\t\t   欢迎进入yjh728的学生管理系统\n") ;
    printf("\t\t\t\t\t   ****************************\n") ;
    printf("\t\t\t\t\t           1.学生登录   \n\t\t\t\t\t           2.教师登录\n") ;
    printf("\t\t\t\t\t           3.管理员登录 \n\t\t\t\t\t           0.退出\n") ;
    printf("\t\t\t\t\t   ****************************\n") ;
    printf("\t\t\t\t\t   请选择身份进行登录\n\t\t\t\t\t   ") ;
    int x ;
    fflush(stdin) ;
    do {
        scanf("%d", &x) ;
        fflush(stdin) ;
        switch (x) {
            case 1 :
                student_interface () ;
                break ;
            case 2 :
                login(2) ;
                break ;
            case 3 :
                manager_interface () ;
                break ;
            case 0 :
                entering1(head) ;
                entering2(aap_s, 1) ;
                entering2(aap_t, 2) ;
                printf("\n\t\t\t\t\t   您选择了退出!") ;
                sleep(1) ;
                printf("\n\t\t\t\t\t   正在退出...") ;
                sleep(1) ;
                printf("\n\t\t\t\t\t   已退出\n") ;
                exit (0) ;
            default :
                printf("\t\t\t\t\t   输入错误, 请重新选择!\n") ;
                printf("\t\t\t\t\t   请键入任意键重新进行选择!") ;
                getch() ;
        }
        show() ;
    }
    while (x != 0) ;
}

char * s_gets (char * p, int n) {			//字符串输入及处理
    char * q, * find ;
    q = fgets(p, n, stdin) ;
    if (q) {
        find = strchr(p, '\n') ;
        if (find)
            * find = '\0' ;
        else
            while (getchar() != '\n')
                continue ;
    }
    return q ;
}
