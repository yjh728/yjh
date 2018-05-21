#include "head.h"

extern Linklist_student head ;
extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;
void manager_interface() {
    manager_login() ;
    manager_power() ;
}
void manager_login () {
    system("cls") ;
    char a[MAX], b[MAX] ;
    FILE * fp = fopen("manager_cAp.txt", "rt") ;
    fscanf(fp, "%s\n", b) ;
    int j ;
    for(j=0; j<3; j++) {
        putchar('\n') ;
        int i = 0 ;
        printf("\t   请输入密码:") ;
        while (i<19) {
            char ch ;
            ch = getch() ;
            if (ch == '\n' || ch == '\r') {
                a[i] = '\0' ;
                break ;
            }
            else if (ch == '\b') {
                printf("\b \b") ;
                if (i>0)
                    a[--i] = '\0' ;
            }
            else {
                a[i++] = ch ;
                putchar('*') ;
            }
        }
        a[19] = '\0' ;
        if (strcmp(b, a) == 0) {
            manager_power() ;
            break ;
        }
    }
    if (j==3)
    puts("\n您已经输错三次!系统将强制退出!") ;
    exit(1) ;
}
void manager_power () {
    system("cls") ;
    puts("\n\n\n\n\n\n\t\t\t\t\t欢迎进入管理员界面") ;
    puts("\t\t\t\t    ****************************") ;
    puts("\t\t\t\t\t1.管理学生账号信息") ;
    puts("\t\t\t\t\t2.管理教师账号信息") ;
    puts("\t\t\t\t\t3.修改密码") ;
    puts("\t\t\t\t\t4.返回上一层") ;
    puts("\t\t\t\t\t0.退出") ;
    puts("\t\t\t\t    ****************************") ;
    int x ;
    printf("\t\t\t\t\t请输入你要进行的操作:\n\t\t\t\t\t") ;
    do {
        scanf("%d", &x) ;
        fflush(stdin) ;
        switch (x) {
            case 1 :
                student_handle() ;
                break ;
            case 2 :
                teacher_handle() ;
                break ;
            case 3 :
                password_change() ;
                manager_interface() ;
                break ;
            case 4 :
                show() ;
            case 0 :
                printf ("\n\t\t\t\t\t您选择了退出!") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t正在退出...") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t已退出\n") ;
                exit(0) ;
            default :
                printf("\n\t\t\t\t\t输入错误, 请重新输入:\n\t\t\t\t\t") ;
                printf("请键入任意键重新进行选择!") ;
                getch() ;
        }
        manager_power() ;
    }
    while (x != 0) ;
}
void password_change() {
    char a[MAX], b[MAX] ;
    printf("\n\n\n\n\n\n\t\t\t\t\t请输入修改后的密码:\n\t\t\t\t\t") ;
    password_input(a) ;
    printf("\n\n\t\t\t\t\t请再输入一遍已确认:\n\t\t\t\t\t") ;
    password_input(b) ;
    FILE * fp = fopen("manager_cAp.txt", "wt") ;
    if (strcmp(a, b) != 0)
        puts("\n\t\t\t\t\t两次输入不一致!") ;
    else {
        puts("修改成功!") ;
        fprintf(fp, "%s\n", a) ;
    }
    fclose(fp) ;
}
void student_handle() {
    system ("cls") ;
    puts ("\n\n\n\n\n\n\t\t\t\t\t     **************************") ;
    puts("\t\t\t\t\t           1.修改学生账号") ;
    puts("\t\t\t\t\t           2.删除学生账号") ;
    puts("\t\t\t\t\t           3.查找学生账号") ;
    puts("\t\t\t\t\t           4.添加学生账号") ;
    puts("\t\t\t\t\t           5.返回上一层") ;
    puts("\t\t\t\t\t           0.退出") ;
    puts ("\t\t\t\t\t     **************************") ;
    printf ("\t\t\t\t\t     请选择你要进行的操作:\n\t\t\t\t\t     ") ;
    int x ;
    do {
        scanf("%d", &x) ;
        int y ;
        fflush(stdin) ;
        if (x!=0 && x!=4 && x!=5)
            y = Print2(aap_s) ;
        if (y) {
            switch (x) {
                case 1 :
                    printf("\t\t\t\t\t     请输入你要修改的账号:") ;
                    printf("\n\t\t\t\t\t   ") ;
                    char a[9] ;
                    s_gets(a, 9) ;
                    change2(aap_s, a) ;
                    entering2(aap_s, 1) ;
                    break ;
                case 2 :
                    del2(aap_s) ;
                    break ;
                case 3 :
                    Print3(aap_s) ;
                    break ;
                case 4 :
                    add2(aap_s) ;
                    entering2(aap_s, 1) ;
                    break ;
                case 5 :
                    manager_power() ;
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
                    printf ("\t\t\t\t\t     输入有误, 请重新输入:\n");
                    printf("\t\t\t\t\t     请键入任意键重新进行选择!") ;
                    getch() ;
            }
        }
        else {
            printf("\t\t\t\t\t     请键入任意键返回上一层!") ;
            getch() ;
        }
        student_handle() ;
    }
    while (x != 0) ;
}
void teacher_handle() {
    system ("cls") ;
    puts ("\n\n\n\n\n\n\t\t\t\t\t     **************************") ;
    puts("\t\t\t\t\t\t  1.修改教师账号") ;
    puts("\t\t\t\t\t\t  2.删除教师账号") ;
    puts("\t\t\t\t\t\t  3.查找教师账号") ;
    puts("\t\t\t\t\t\t  4.添加教师账号") ;
    puts("\t\t\t\t\t\t  5.返回上一层") ;
    puts("\t\t\t\t\t\t  0.退出") ;
    puts ("\t\t\t\t\t     **************************") ;
    printf ("\t\t\t\t\t     请选择你要进行的操作:\n\t\t\t\t\t     ") ;
    int x ;
    do {
        scanf("%d", &x) ;
        fflush(stdin) ;
        int y ;
        if (x!=0 && x!=4 && x!=5)
            y = Print2(aap_t) ;
        if (y) {
            switch (x) {
                case 1 :
                    printf("\t\t\t\t\t     请输入你要修改的账号:") ;
                    char a[9] ;
                    s_gets(a, 9) ;
                    change2(aap_t, a) ;
                    entering2(aap_t, 2) ;
                    break ;
                case 2 :
                    del2(aap_t) ;
                    break ;
                case 3 :
                    Print3(aap_t) ;
                    break ;
                case 4 :
                    add2(aap_t) ;
                    entering2(aap_t, 2) ;
                    break ;
                case 5 :
                    manager_power() ;
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
                    printf ("\t\t\t\t\t     输入有误, 请重新输入:\n");
                    printf("\t\t\t\t\t     请键入任意键重新进行选择!") ;
                    getch() ;
            }
        }
        else {
            printf("\t\t\t\t\t     请键入任意键返回上一层!") ;
            getch() ;
        }
        teacher_handle() ;
    }
    while (x != 0) ;
}
