#include "head.h"

extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;
int change2(Linklist_aap phead, const char * q) {
    Linklist_aap p = phead->next ;
    while (p && strcmp(p->account_password.account, q) != 0)
        p = p->next ;
    if (p == NULL) {
        puts("\t\t\t\t\t     输入错误, 未找到该账号!") ;
        puts("\t\t\t\t\t   请键入任意键返回上一层!") ;
        getch() ;
        return 0 ;
    }
    else {
        char a[20], b[20] ;
        printf("\t\t\t\t\t     请输入原密码:\n\t\t\t\t\t     ") ;
        password_input(a) ;
        if (strcmp(a, p->account_password.password)==0) {
            puts("\n\t\t\t\t\t     请输入修改后的密码:") ;
            printf("\t\t\t\t\t     ") ;
            password_input(a) ;
            puts("\n\t\t\t\t\t     请再输入一遍以确认:") ;
            printf("\t\t\t\t\t     ") ;
            password_input(b) ;
            if (strcmp(a, b) != 0) {
                puts("\n\t\t\t\t\t     两次输入不一致!\n\t\t\t\t\t     请键入任意键返回上一层!") ;
                return 0 ;
            }
            else {
                puts("\n\t\t\t\t\t     修改成功!") ;
                strcpy(p->account_password.password, a) ;
                puts("\t\t\t\t\t   请键入任意键返回上一层!") ;
                getch() ;
                return 1 ;
            }
        }
        else {
            puts("\n\t\t\t\t\t     原密码错误!\n\t\t\t\t\t     请键入任意键返回上一层!") ;
            getch() ;
            return 0 ;
        }
    }
}
void del2(Linklist_aap phead) {
    Linklist_aap q = phead->next, p = phead->next ;
    char account[9] ;
    printf("请输入要删除的账号:") ;
    s_gets(account, 10) ;
    while (q && strcmp(q->account_password.account, account) != 0) {
        p = q ;
        q = q->next ;
    }
    if (q == NULL)
        puts("输入错误, 未找到该账号!") ;
    else {
        if (q == phead->next)
            phead->next = q->next ;
        else
            p->next = q->next ;
        puts("已删除!") ;
        free(q) ;
    }
    printf("请键入任意字符退出\n") ;
    getch() ;
}
void add2(Linklist_aap phead) {
    Linklist_aap p = phead, q ;
    while (p->next)
        p = p->next ;
    printf("\t\t\t\t\t     请输入要添加的账号:\n\t\t\t\t\t     ") ;
    char a[9], b[MAX], c[MAX] ;
    s_gets(a, 9) ;
    printf("\n\t\t\t\t\t     请输入密码:\n\t\t\t\t\t     ") ;
    password_input(b) ;
    printf("\n\t\t\t\t\t     请再输入一遍密码进行确认:\n\t\t\t\t\t     ") ;
    password_input(c) ;
    if (strcmp(b, c)) {
        puts("\n\t\t\t\t\t     两次输入不一致!") ;
        puts("\n\t\t\t\t\t     请键入任意键返回上一层!") ;
        getch() ;
    }
    else {
        q = (Linklist_aap) malloc(sizeof(Node_aap)) ;
        strcpy(q->account_password.account, a) ;
        strcpy(q->account_password.password, b) ;
        p->next = q ;
        q->next = NULL ;
        puts("\n\t\t\t\t\t     注册成功!") ;
        puts("\n\t\t\t\t\t     请键入任意键返回上一层!") ;
        getch() ;
    }
}
int Print2 (Linklist_aap phead) {
    Linklist_aap p = phead->next ;
    if (phead == NULL || p == NULL) {
        puts("\t\t\t\t\t     无账号信息!") ;
        if (phead)
            return 1 ;
        else
            return 0 ;
    }
    else {
        while (p) {
            printf("\t\t\t\t\t     账号\t\t密码\n") ;
            printf("\t\t\t\t\t     %s\t\t%s\n", p->account_password.account, p->account_password.password) ;
            p = p->next ;
        }
        return 0 ;
    }
}
void Print3(Linklist_aap phead) {
    char a[9] ;
    printf("\t\t\t\t\t     请输入要查找的账号:\n") ;
    s_gets(a, 9) ;
    Linklist_aap p = phead -> next ;
    while (p && strcmp(a, p->account_password.account) != 0)
        p = p->next ;
    if (p==NULL)
        printf("\t\t\t\t\t     输入错误, 未找到该账号!\n") ;
    else
        printf("\t\t\t\t\t     账号:%s\n密码:%s\n", p->account_password.account, p->account_password.password) ;
    printf("\t\t\t\t\t     请键入任意键返回上一层!") ;
    getch() ;
}
