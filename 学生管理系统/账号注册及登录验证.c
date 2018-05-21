#include "head.h"

extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;
void password_input (char * p) {
    int i = 0 ;
    while (i<19) {
        char ch ;
        ch = getch() ;
        if (ch == '\n' || ch == '\r') {
            p[i] = '\0' ;
            break ;
        }
        else if (ch == '\b'){
            if (i>0) {
                printf("\b \b") ;
                p[--i] = '\0' ;
            }
        }
        else {
            p[i++] = ch ;
            putchar('*') ;
        }
    }
    fflush(stdin) ;
    p[19] = '\0' ;
}
void register1 () {
    system("cls") ;
    AAP * aap1 = (AAP *) malloc (sizeof(AAP)) ;
    AAP * aap2 = (AAP *) malloc (sizeof(AAP)) ;
    FILE * fp = fopen("student_cAp.txt", "at+") ;
    if (fp==NULL) {
        //printf("\n\t打开文件失败, 失败原因:%s\n", stderror(errno)) ;
        puts("\n\t请键入任意键退出!") ;
        getch() ;
        exit(1) ;
    }
    printf("\n\n\n\t请输入用户名(8位学号):") ;
    scanf("%s", aap1->account) ;
    fflush(stdin) ;
    while (!feof(fp)) {
        fscanf(fp, "%s %s\n", aap2->account, aap2->password) ;
        if (strcmp(aap1->account, aap2->account) == 0) {
            puts("\t该用户已存在!请重新注册或登录!") ;
            printf("\t请键入任意键返回注册界面!") ;
            getch() ;
            fclose(fp) ;
            free(aap1) ;
            free(aap2) ;
            student_interface() ;
        }
    }
    printf("\n\t密码:\n\t") ;
    password_input (aap1->password) ;
    printf("\n\t请在输入一遍进行确认:\n\t") ;
    password_input(aap2->password) ;
    if (strcmp(aap1->password, aap2->password)) {
        puts("\n\t两次输入不一致!请重新进行注册!") ;
        student_interface() ;
    }
    fprintf(fp, "%s %s\n", aap1->account, aap1->password) ;
    fclose(fp) ;
    free(aap1) ;
    free(aap2) ;
    student_interface() ;
}
void login (int n) {
    system("cls") ;
    AAP * aap1 = (AAP *) malloc(sizeof(AAP)) ;
    AAP * aap2 = (AAP *) malloc(sizeof(AAP)) ;
    FILE * fp ;
    if (n==2) {
        fp = fopen("teacher_cAp.txt", "rt") ;
        if (fp==NULL) {
            //printf("\n\t打开文件失败, 失败原因:%s\n", stderror(errno)) ;
            puts("\n\n\n\t请键入任意键退出!") ;
            getch() ;
            exit(1) ;
        }
        printf("\n\t账号:") ;
    }
    else {
        fp = fopen("student_cAp.txt", "rt") ;
        if (fp==NULL) {
            //printf("\n\t打开文件失败, 失败原因:%s\n", stderror(errno)) ;
            puts("\n\n\n\t请键入任意键退出!") ;
            getch() ;
            exit(1) ;
        }
        printf("\n\n\n\t账号(8位学号):") ;
    }
    scanf("%s", aap1->account) ;
    fflush(stdin) ;
    while (!feof(fp)) {
        fscanf(fp, "%s %s\n", aap2->account, aap2->password) ;
        if (strcmp(aap1->account, aap2->account)==0) {
            printf("\n\t密码:") ;
            for (int i=0; i<3; i++) {
                password_input (aap1->password) ;
                if (strcmp(aap1->password, aap2->password)==0) {
                    puts ("登录成功!") ;
                    if (n==1)
                        student_power(aap1->account) ;
                    else
                        teacher_power(aap1->account) ;
                }
                else
                    printf("\n\t密码错误!请重新输入(您还有%d次机会):\n\t", 2-i) ;
            }
            printf("\t您已经输错三次,系统将强制退出!\n");
            exit(1) ;
        }
    }
    fclose (fp) ;
    printf ("\t该用户不存在!请键入任意字符退出\n") ;
    getch () ;
    exit (1) ;
}
