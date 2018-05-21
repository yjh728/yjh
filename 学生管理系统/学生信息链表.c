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
    printf("\n\n\n\t请输入学生学号(8位)[输入非负数结束录入]:") ;
    changdu = 0 ;
    while (s_gets(xuehao, 9) && atoi(xuehao)>0) {
        changdu ++ ;
        pnew = (Linklist_student) malloc(sizeof(Node_student)) ;
        pnew->next = NULL ;
        pend->next = pnew ;
        strncpy(pnew->student.xuehao, xuehao, 9) ;
        printf("\n\t请输入该生姓名:") ;
        s_gets(pnew->student.name, MAX) ;
        printf("\n\t请输入该生高数成绩:") ;
        s_gets(pnew->student.Advanced, 4) ;
        printf("\n\t请输入该生c语言成绩:") ;
        s_gets(pnew->student.C_language_programming, 4) ;
        printf("\n\t请输入该生大英成绩:") ;
        s_gets(pnew->student.English, 4) ;
        printf("\n\t请输入下一个学生学号(8位)[输入非负数结束录入]:") ;
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
    printf("\n\n\n\t请输入要添加的学生学号:") ;
    s_gets(xuehao, 9) ;
    while (p->next)
        p = p->next ;
    pnew = (Linklist_student) malloc (sizeof(Node_student)) ;
    if (pnew == NULL)
        puts("\t添加失败!") ;
    else {
        strcpy(pnew->student.xuehao, xuehao) ;
        printf("\n\t请输入该生姓名:") ;
        s_gets(pnew->student.name, MAX) ;
        printf("\n\t请输入该生高数成绩:") ;
        s_gets(pnew->student.Advanced, 4) ;
        printf("\n\t请输入该生c语言成绩:") ;
        s_gets(pnew->student.C_language_programming, 4) ;
        printf("\n\t请输入该生大英成绩:") ;
        s_gets(pnew->student.English, 4) ;
        pnew->student.total = atoi(pnew->student.Advanced) + atoi(pnew->student.C_language_programming) + atoi(pnew->student.English) ;
        pnew->student.average = pnew->student.total / 3.0 ;
        p->next = pnew ;
        pnew->next = NULL ;
    }
    printf("\n\t请键入任意字符退出\n") ;
    getch() ;
}
void del1 (Linklist_student phead) {
    system("cls") ;
    Linklist_student q = phead->next, p = phead->next ;
    char xuehao[9] ;
    printf("\n\n\n\t请输入要删除的学号:") ;
    s_gets(xuehao, 10) ;
    while (q && strcmp(q->student.xuehao, xuehao) != 0) {
        p = q ;
        q = q->next ;
    }
    if (q == NULL)
        puts("\t输入错误, 未找到该生!") ;
    else {
        if (q == phead->next)
            phead->next = q->next ;
        else
            p->next = q->next ;
        puts("\t已删除!") ;
        free(q) ;
    }
    printf("\t请键入任意字符退出\n") ;
    getch() ;
}
void change1 (Linklist_student phead) {
    system("cls") ;
    Linklist_student p = phead->next ;
    char xuehao[9] ;
    printf("\n\n\n\t请输入要修改的学生学号:") ;
    s_gets(xuehao, 9) ;
    while (p && strcmp(p->student.xuehao, xuehao) != 0)
        p = p->next ;
    if (p == NULL)
        puts("\t输入错误, 为找到该生!") ;
    else {
        printf("\n\t\t\t1.姓名    \t\t\t2.高数成绩") ;
        printf("\n\t\t\t3.c语言成绩\t\t\t4.大英成绩\n") ;
        printf("\t\t\t5.学号\n") ;
        printf("\n\t请输入要修改的内容:") ;
        int x ;
        scanf("%d", &x) ;
        fflush(stdin) ;
        switch (x) {
            case 1 :
                printf("\n\t请输入修改后的学生姓名:") ;
                s_gets (p->student.name, MAX) ;
                break ;
            case 2 :
                printf("\n\t请输入修改后的高数成绩:") ;
                s_gets(p->student.Advanced, 4) ;
                break ;
            case 3 :
                printf("\n\t请输入修改后的c语言成绩:") ;
                s_gets(p->student.C_language_programming, 4) ;
                break ;
            case 4 :
                printf("\n\t请输入修改后的大英成绩:") ;
                s_gets(p->student.English, 4) ;
                break ;
            case 5 :
                printf("\n\t请输入修改后的学号:") ;
                s_gets(p->student.xuehao, 9) ;
                break ;
        }
        p->student.total = atoi(p->student.Advanced) + atoi(p->student.C_language_programming) + atoi(p->student.English) ;
        p->student.average = p->student.total / 3.0 ;
    }
    printf("\t请键入任意键退出\n") ;
    getch() ;
}
void find1 (const Linklist_student phead) {
    system("cls") ;
    Linklist_student p = phead->next ;
    char xuehao[9] ;
    printf("\n\n\n\t请输入要查找的学生学号:") ; ;
    s_gets(xuehao, 9) ;
    sort() ;
    int count = 1 ;
    while (p && strcmp(xuehao, p->student.xuehao) != 0) {
        count ++ ;
        p = p->next ;
    }
    if (p == NULL)
        puts("\n\t输入错误, 未找到该生!") ;
    else {
        printf("\n\t排名\t\t\t学号\t\t\t姓名\t\t高数\t\tc语言\t\t大英\t\t总分\t\t平均分\n") ;
        printf("\t%d\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%.1f\n", count, p->student.xuehao, p->student.name,
                p->student.Advanced, p->student.C_language_programming, p->student.English, p->student.total,
                p->student.average) ;
    }
    printf("\n\t请键入任意键退出\n") ;
    getch() ;
}
void swap (Linklist_student a, Linklist_student b) {
    Item r = a->student ;
    a->student = b->student ;
    b->student = r ;
}
void sort () {
    system("cls") ;
    puts("\n\n\n\n\n\n\t\t\t\t\t\t    请选择以什么顺序输出学生成绩:") ;
    puts("\t\t\t\t\t\t    ****************************") ;
    puts("\t\t\t\t\t\t\t    1.总分") ;
    puts("\t\t\t\t\t\t\t    2.高数") ;
    puts("\t\t\t\t\t\t\t    3.大英") ;
    puts("\t\t\t\t\t\t\t    4.c语言") ;
    puts("\t\t\t\t\t\t\t    5.学号") ;
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
                puts("输入错误, 请重新输入:") ;
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
        printf("\n\n\n\n\n\n\t\t\t    及格人数\t    优秀人数\t    不及格人数\t      最高分\t      最低分\t       平均分\n\n") ;
        printf("\t\t高数\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n\n", m2, m3, m1, gs_max, gs_min, aver_gs) ;
        printf("\t\tc语言\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n\n", c2, c3, c1, cyy_max, cyy_min, aver_cyy) ;
        printf("\t\t大英\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n\n", y2, y3, y1, dy_max, dy_min, aver_dy) ;
    }
    else
        puts("\n\n\n\n\n\n\t\t\t    无学生信息!") ;
    printf("\t\t请键入任意键返回上一层!") ;
    getch() ;
}
void Print1 () {
    system("cls") ;
    Linklist_student p = head->next ;
    int n = 1 ;
    if (p == NULL || head == NULL)
        printf("\n\n\n\t无学生信息!\n") ;
    else {
        printf("\n\n\n\n\t排名\t\t\t学号\t\t\t姓名\t\t高数\t\tc语言\t\t大英\t\t总分\t\t平均分\n") ;
        while (p) {
            printf("\t%d\t\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n", n++, p->student.xuehao, p->student.name,
                   atoi(p->student.Advanced), atoi(p->student.C_language_programming), atoi(p->student.English), p->student.total,
                   p->student.average) ;
            p = p->next ;
        }
    }
    printf("\t请键入任意键返回上一层\n") ;
    getch() ;
}
