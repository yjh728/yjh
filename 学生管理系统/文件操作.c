#include "head.h"

extern int changdu ;

void entering1(Linklist_student phead) {        //学生信息导出
    Linklist_student p = phead->next ;
    FILE * fp = fopen("student_message.txt", "w+") ;
    if (fp != NULL) {
        while (p) {
            fprintf(fp, "%s %s %s %s %s %d %.1f\n", p->student.name, p->student.xuehao, p->student.Advanced,
                    p->student.C_language_programming, p->student.English, p->student.total, p->student.average) ;
            p = p->next ;
        }}
    fclose(fp) ;
}

Linklist_student export1 () {                   //学生信息导入
    changdu = 0 ;
    Linklist_student phead, p, q ;
    phead = (Linklist_student) malloc (sizeof(Node_student)) ;
    phead->next = NULL ;
    p = phead ;
    FILE * fp = fopen("student_message.txt", "rt") ;
    if (fgetc(fp)==EOF)
        ;
    else {
        rewind(fp) ;
        while (!feof(fp)) {
            q = (Linklist_student) malloc (sizeof(Node_student)) ;
            fscanf(fp, "%s %s %s %s %s %d %f\n", q->student.name, q->student.xuehao, q->student.Advanced,
                q->student.C_language_programming, q->student.English, &q->student.total, &q->student.average) ;
            changdu ++ ;
            p->next = q ;
            p = q ;
        }
        q->next = NULL ;
    }
    fclose(fp) ;
    return phead ;
}

void entering2(Linklist_aap phead, int n) {       //账号信息导出
    Linklist_aap p = phead->next ;
    FILE * fp ;
    if (n == 1)
        fp = fopen("student_cAp.txt", "w+") ;
    else
        fp = fopen("teacher_cAp.txt", "w+") ;
    while (p) {
        fprintf(fp, "%s %s\n", p->account_password.account, p->account_password.password) ;
        p = p->next ;
    }
    fclose(fp) ;
}

Linklist_aap export2 (int n) {                     //账号信息导入
    Linklist_aap phead, p, q ;
    phead = (Linklist_aap) malloc (sizeof(Node_aap)) ;
    phead->next = NULL ;
    p = phead ;
    FILE * fp ;
    if (n == 1)
        fp = fopen("student_cAp.txt", "rt") ;
    else
        fp = fopen("teacher_cAp.txt", "rt") ;
    if (fgetc(fp)==EOF)
        ;
    else {
        rewind(fp) ;
        while (!feof(fp)) {
            q = (Linklist_aap) malloc (sizeof(Node_aap)) ;
            fscanf(fp, "%s %s\n", q->account_password.account, q->account_password.password) ;
            p->next = q ;
            p = q ;
        }
        q->next = NULL ;
    }
    fclose(fp) ;
    return phead ;
}
