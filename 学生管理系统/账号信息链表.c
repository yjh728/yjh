#include "head.h"

extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;
int change2(Linklist_aap phead, const char * q) {
    Linklist_aap p = phead->next ;
    while (p && strcmp(p->account_password.account, q) != 0)
        p = p->next ;
    if (p == NULL) {
        puts("\t\t\t\t\t     �������, δ�ҵ����˺�!") ;
        puts("\t\t\t\t\t   ����������������һ��!") ;
        getch() ;
        return 0 ;
    }
    else {
        char a[20], b[20] ;
        printf("\t\t\t\t\t     ������ԭ����:\n\t\t\t\t\t     ") ;
        password_input(a) ;
        if (strcmp(a, p->account_password.password)==0) {
            puts("\n\t\t\t\t\t     �������޸ĺ������:") ;
            printf("\t\t\t\t\t     ") ;
            password_input(a) ;
            puts("\n\t\t\t\t\t     ��������һ����ȷ��:") ;
            printf("\t\t\t\t\t     ") ;
            password_input(b) ;
            if (strcmp(a, b) != 0) {
                puts("\n\t\t\t\t\t     �������벻һ��!\n\t\t\t\t\t     ����������������һ��!") ;
                return 0 ;
            }
            else {
                puts("\n\t\t\t\t\t     �޸ĳɹ�!") ;
                strcpy(p->account_password.password, a) ;
                puts("\t\t\t\t\t   ����������������һ��!") ;
                getch() ;
                return 1 ;
            }
        }
        else {
            puts("\n\t\t\t\t\t     ԭ�������!\n\t\t\t\t\t     ����������������һ��!") ;
            getch() ;
            return 0 ;
        }
    }
}
void del2(Linklist_aap phead) {
    Linklist_aap q = phead->next, p = phead->next ;
    char account[9] ;
    printf("������Ҫɾ�����˺�:") ;
    s_gets(account, 10) ;
    while (q && strcmp(q->account_password.account, account) != 0) {
        p = q ;
        q = q->next ;
    }
    if (q == NULL)
        puts("�������, δ�ҵ����˺�!") ;
    else {
        if (q == phead->next)
            phead->next = q->next ;
        else
            p->next = q->next ;
        puts("��ɾ��!") ;
        free(q) ;
    }
    printf("����������ַ��˳�\n") ;
    getch() ;
}
void add2(Linklist_aap phead) {
    Linklist_aap p = phead, q ;
    while (p->next)
        p = p->next ;
    printf("\t\t\t\t\t     ������Ҫ��ӵ��˺�:\n\t\t\t\t\t     ") ;
    char a[9], b[MAX], c[MAX] ;
    s_gets(a, 9) ;
    printf("\n\t\t\t\t\t     ����������:\n\t\t\t\t\t     ") ;
    password_input(b) ;
    printf("\n\t\t\t\t\t     ��������һ���������ȷ��:\n\t\t\t\t\t     ") ;
    password_input(c) ;
    if (strcmp(b, c)) {
        puts("\n\t\t\t\t\t     �������벻һ��!") ;
        puts("\n\t\t\t\t\t     ����������������һ��!") ;
        getch() ;
    }
    else {
        q = (Linklist_aap) malloc(sizeof(Node_aap)) ;
        strcpy(q->account_password.account, a) ;
        strcpy(q->account_password.password, b) ;
        p->next = q ;
        q->next = NULL ;
        puts("\n\t\t\t\t\t     ע��ɹ�!") ;
        puts("\n\t\t\t\t\t     ����������������һ��!") ;
        getch() ;
    }
}
int Print2 (Linklist_aap phead) {
    Linklist_aap p = phead->next ;
    if (phead == NULL || p == NULL) {
        puts("\t\t\t\t\t     ���˺���Ϣ!") ;
        if (phead)
            return 1 ;
        else
            return 0 ;
    }
    else {
        while (p) {
            printf("\t\t\t\t\t     �˺�\t\t����\n") ;
            printf("\t\t\t\t\t     %s\t\t%s\n", p->account_password.account, p->account_password.password) ;
            p = p->next ;
        }
        return 0 ;
    }
}
void Print3(Linklist_aap phead) {
    char a[9] ;
    printf("\t\t\t\t\t     ������Ҫ���ҵ��˺�:\n") ;
    s_gets(a, 9) ;
    Linklist_aap p = phead -> next ;
    while (p && strcmp(a, p->account_password.account) != 0)
        p = p->next ;
    if (p==NULL)
        printf("\t\t\t\t\t     �������, δ�ҵ����˺�!\n") ;
    else
        printf("\t\t\t\t\t     �˺�:%s\n����:%s\n", p->account_password.account, p->account_password.password) ;
    printf("\t\t\t\t\t     ����������������һ��!") ;
    getch() ;
}
