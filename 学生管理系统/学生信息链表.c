#include "head.h"

extern Linklist_student head ;
extern int changdu ;
Linklist_student chuangjian() {
    system("cls") ;
    Linklist_student phead, pnew, pend ;
    phead = (Linklist_student) malloc(sizeof(Node_student)) ;
    pend = phead ;
    phead->next = NULL ;
    char xuehao[9] ;
    printf("\n\n\n\t������ѧ��ѧ��(8λ)[����Ǹ�������¼��]:") ;
    changdu = 0 ;
    while (s_gets(xuehao, 9) && atoi(xuehao)>0) {
        changdu ++ ;
        pnew = (Linklist_student) malloc(sizeof(Node_student)) ;
        pnew->next = NULL ;
        pend->next = pnew ;
        strncpy(pnew->student.xuehao, xuehao, 9) ;
        printf("\n\t�������������:") ;
        s_gets(pnew->student.name, MAX) ;
        printf("\n\t��������������ɼ�:") ;
        s_gets(pnew->student.Advanced, 4) ;
        printf("\n\t���������c���Գɼ�:") ;
        s_gets(pnew->student.C_language_programming, 4) ;
        printf("\n\t�����������Ӣ�ɼ�:") ;
        s_gets(pnew->student.English, 4) ;
        printf("\n\t��������һ��ѧ��ѧ��(8λ)[����Ǹ�������¼��]:") ;
        pnew->student.total = atoi(pnew->student.Advanced) + atoi(pnew->student.C_language_programming) + atoi(pnew->student.English) ;
        pnew->student.average = pnew->student.total / 3.0 ;
        pend = pnew ;
    }
    return phead ;
}
void add1 (Linklist_student phead) {
    system("cls") ;
    Linklist_student p = phead, pnew ;
    char xuehao[9] ;
    printf("\n\n\n\t������Ҫ��ӵ�ѧ��ѧ��:") ;
    s_gets(xuehao, 9) ;
    while (p->next)
        p = p->next ;
    pnew = (Linklist_student) malloc (sizeof(Node_student)) ;
    if (pnew == NULL)
        puts("\t���ʧ��!") ;
    else {
        strcpy(pnew->student.xuehao, xuehao) ;
        printf("\n\t�������������:") ;
        s_gets(pnew->student.name, MAX) ;
        printf("\n\t��������������ɼ�:") ;
        s_gets(pnew->student.Advanced, 4) ;
        printf("\n\t���������c���Գɼ�:") ;
        s_gets(pnew->student.C_language_programming, 4) ;
        printf("\n\t�����������Ӣ�ɼ�:") ;
        s_gets(pnew->student.English, 4) ;
        pnew->student.total = atoi(pnew->student.Advanced) + atoi(pnew->student.C_language_programming) + atoi(pnew->student.English) ;
        pnew->student.average = pnew->student.total / 3.0 ;
        p->next = pnew ;
        pnew->next = NULL ;
    }
    printf("\n\t����������ַ��˳�\n") ;
    getch() ;
}
void del1 (Linklist_student phead) {
    system("cls") ;
    Linklist_student q = phead->next, p = phead->next ;
    char xuehao[9] ;
    printf("\n\n\n\t������Ҫɾ����ѧ��:") ;
    s_gets(xuehao, 10) ;
    while (q && strcmp(q->student.xuehao, xuehao) != 0) {
        p = q ;
        q = q->next ;
    }
    if (q == NULL)
        puts("\t�������, δ�ҵ�����!") ;
    else {
        if (q == phead->next)
            phead->next = q->next ;
        else
            p->next = q->next ;
        puts("\t��ɾ��!") ;
        free(q) ;
    }
    printf("\t����������ַ��˳�\n") ;
    getch() ;
}
void change1 (Linklist_student phead) {
    system("cls") ;
    Linklist_student p = phead->next ;
    char xuehao[9] ;
    printf("\n\n\n\t������Ҫ�޸ĵ�ѧ��ѧ��:") ;
    s_gets(xuehao, 9) ;
    while (p && strcmp(p->student.xuehao, xuehao) != 0)
        p = p->next ;
    if (p == NULL)
        puts("\t�������, Ϊ�ҵ�����!") ;
    else {
        printf("\n\t\t\t1.����    \t\t\t2.�����ɼ�") ;
        printf("\n\t\t\t3.c���Գɼ�\t\t\t4.��Ӣ�ɼ�\n") ;
        printf("\t\t\t5.ѧ��\n") ;
        printf("\n\t������Ҫ�޸ĵ�����:") ;
        int x ;
        scanf("%d", &x) ;
        fflush(stdin) ;
        switch (x) {
            case 1 :
                printf("\n\t�������޸ĺ��ѧ������:") ;
                s_gets (p->student.name, MAX) ;
                break ;
            case 2 :
                printf("\n\t�������޸ĺ�ĸ����ɼ�:") ;
                s_gets(p->student.Advanced, 4) ;
                break ;
            case 3 :
                printf("\n\t�������޸ĺ��c���Գɼ�:") ;
                s_gets(p->student.C_language_programming, 4) ;
                break ;
            case 4 :
                printf("\n\t�������޸ĺ�Ĵ�Ӣ�ɼ�:") ;
                s_gets(p->student.English, 4) ;
                break ;
            case 5 :
                printf("\n\t�������޸ĺ��ѧ��:") ;
                s_gets(p->student.xuehao, 9) ;
                break ;
        }
        p->student.total = atoi(p->student.Advanced) + atoi(p->student.C_language_programming) + atoi(p->student.English) ;
        p->student.average = p->student.total / 3.0 ;
    }
    printf("\t�����������˳�\n") ;
    getch() ;
}
void find1 (const Linklist_student phead) {
    system("cls") ;
    Linklist_student p = phead->next ;
    char xuehao[9] ;
    printf("\n\n\n\t������Ҫ���ҵ�ѧ��ѧ��:") ; ;
    s_gets(xuehao, 9) ;
    sort() ;
    int count = 1 ;
    while (p && strcmp(xuehao, p->student.xuehao) != 0) {
        count ++ ;
        p = p->next ;
    }
    if (p == NULL)
        puts("\n\t�������, δ�ҵ�����!") ;
    else {
        printf("\n\t����\t\t\tѧ��\t\t\t����\t\t����\t\tc����\t\t��Ӣ\t\t�ܷ�\t\tƽ����\n") ;
        printf("\t%d\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%.1f\n", count, p->student.xuehao, p->student.name,
                p->student.Advanced, p->student.C_language_programming, p->student.English, p->student.total,
                p->student.average) ;
    }
    printf("\n\t�����������˳�\n") ;
    getch() ;
}
void swap (Linklist_student a, Linklist_student b) {
    Item r = a->student ;
    a->student = b->student ;
    b->student = r ;
}
void sort () {
    system("cls") ;
    puts("\n\n\n\n\n\n\t\t\t\t\t\t    ��ѡ����ʲô˳�����ѧ���ɼ�:") ;
    puts("\t\t\t\t\t\t    ****************************") ;
    puts("\t\t\t\t\t\t\t    1.�ܷ�") ;
    puts("\t\t\t\t\t\t\t    2.����") ;
    puts("\t\t\t\t\t\t\t    3.��Ӣ") ;
    puts("\t\t\t\t\t\t\t    4.c����") ;
    puts("\t\t\t\t\t\t\t    5.ѧ��") ;
    puts("\t\t\t\t\t\t    ****************************") ;
    printf("\t\t\t\t\t\t    ") ;
    int n ;
    scanf("%d", &n) ;
    fflush(stdin) ;
    Linklist_student q = head->next ;
    int flag = 1 ;
    for (int i=0; i<changdu && flag; i++) {
        q = head->next ;
        flag = 0 ;
        for (; q->next != NULL; q = q->next)
            if (n<1 || n>6) {
                puts("�������, ����������:") ;
                sort() ;
                break ;
            }
            else if (n==1 && q->student.total < q->next->student.total) {
                flag = 1 ;
                swap(q, q->next) ;
            }
            else if (n==2 && strcmp(q->student.Advanced, q->next->student.Advanced)<0) {
                flag = 1 ;
                swap(q, q->next) ;
            }
            else if (n==3 && strcmp(q->student.English, q->next->student.English)<0) {
                flag = 1 ;
                swap(q, q->next) ;
            }
            else if (n==4 && strcmp(q->student.C_language_programming, q->next->student.C_language_programming)<0) {
                flag = 1 ;
                swap(q, q->next) ;
            }
            else if (n==5 && strcmp(q->student.xuehao, q->next->student.xuehao)>0) {
                flag = 1 ;
                swap(q, q->next) ;
            }
    }
}
void Performance_analysis (Linklist_student phead) {
    system("cls") ;
    Linklist_student p = phead->next ;
    if (p && phead) {
        int c1, c2, c3, m1, m2, m3, y1, y2, y3 ;
        int gs_max, dy_max, cyy_max ;
        int gs_min, dy_min, cyy_min ;
        int sum_gs, sum_dy, sum_cyy ;
        float aver_gs, aver_dy, aver_cyy ;
        gs_max = gs_min = atoi(p->student.Advanced) ;
        dy_max = dy_min = atoi(p->student.English) ;
        cyy_max = cyy_min = atoi(p->student.C_language_programming) ;
        sum_gs = sum_dy = sum_cyy = 0 ;
        aver_gs = aver_dy = aver_cyy = 0 ;
        c1 = c2 = c3 = 0 ;
        m1 = m2 = m3 = 0 ;
        y1 = y2 = y3 = 0 ;
        while (p) {
            sum_gs += atoi(p->student.Advanced) ;
            sum_dy += atoi(p->student.English) ;
            sum_cyy += atoi(p->student.C_language_programming) ;
            if (gs_max<atoi(p->student.Advanced))
                gs_max = atoi(p->student.Advanced) ;
            if (gs_min>atoi(p->student.Advanced))
                gs_min = atoi(p->student.Advanced) ;
            if (dy_max>atoi(p->student.English))
                dy_max = atoi(p->student.English) ;
            if (dy_min>atoi(p->student.English)) ;
                dy_min = atoi(p->student.English) ;
            if (cyy_max<atoi(p->student.C_language_programming))
                cyy_max = atoi(p->student.C_language_programming) ;
            if (cyy_min>atoi(p->student.C_language_programming))
                cyy_min = atoi(p->student.C_language_programming) ;
            if (atoi(p->student.C_language_programming)>=60) {
                c2 ++ ;
                if (atoi(p->student.C_language_programming)>=85)
                    c3 ++ ;
            }
            else    c1 ++ ;
            if (atoi(p->student.Advanced)>=60) {
                m2 ++ ;
                if (atoi(p->student.Advanced)>=85)
                    m3 ++ ;
            }
            else    m1 ++ ;
            if (atoi(p->student.English)>=60) {
                y2 ++ ;
                if (atoi(p->student.English)>=85)
                    y3 ++ ;
            }
            else    y1 ++ ;
            p = p->next ;
        }
        aver_gs = sum_gs / (changdu + 0.0) ;
        aver_dy = sum_dy / (changdu + 0.0) ;
        aver_cyy = sum_cyy / (changdu + 0.0) ;
        printf("\n\n\n\n\n\n\t\t\t    ��������\t    ��������\t    ����������\t      ��߷�\t      ��ͷ�\t       ƽ����\n\n") ;
        printf("\t\t����\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n\n", m2, m3, m1, gs_max, gs_min, aver_gs) ;
        printf("\t\tc����\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n\n", c2, c3, c1, cyy_max, cyy_min, aver_cyy) ;
        printf("\t\t��Ӣ\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n\n", y2, y3, y1, dy_max, dy_min, aver_dy) ;
    }
    else
        puts("\n\n\n\n\n\n\t\t\t    ��ѧ����Ϣ!") ;
    printf("\t\t����������������һ��!") ;
    getch() ;
}
void Print1 () {
    system("cls") ;
    Linklist_student p = head->next ;
    int n = 1 ;
    if (p == NULL || head == NULL)
        printf("\n\n\n\t��ѧ����Ϣ!\n") ;
    else {
        printf("\n\n\n\n\t����\t\t\tѧ��\t\t\t����\t\t����\t\tc����\t\t��Ӣ\t\t�ܷ�\t\tƽ����\n") ;
        while (p) {
            printf("\t%d\t\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n", n++, p->student.xuehao, p->student.name,
                   atoi(p->student.Advanced), atoi(p->student.C_language_programming), atoi(p->student.English), p->student.total,
                   p->student.average) ;
            p = p->next ;
        }
    }
    printf("\t����������������һ��\n") ;
    getch() ;
}
