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
        printf("\t   ����������:") ;
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
    puts("\n���Ѿ��������!ϵͳ��ǿ���˳�!") ;
    exit(1) ;
}
void manager_power () {
    system("cls") ;
    puts("\n\n\n\n\n\n\t\t\t\t\t��ӭ�������Ա����") ;
    puts("\t\t\t\t    ****************************") ;
    puts("\t\t\t\t\t1.����ѧ���˺���Ϣ") ;
    puts("\t\t\t\t\t2.�����ʦ�˺���Ϣ") ;
    puts("\t\t\t\t\t3.�޸�����") ;
    puts("\t\t\t\t\t4.������һ��") ;
    puts("\t\t\t\t\t0.�˳�") ;
    puts("\t\t\t\t    ****************************") ;
    int x ;
    printf("\t\t\t\t\t��������Ҫ���еĲ���:\n\t\t\t\t\t") ;
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
                printf ("\n\t\t\t\t\t��ѡ�����˳�!") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t�����˳�...") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t���˳�\n") ;
                exit(0) ;
            default :
                printf("\n\t\t\t\t\t�������, ����������:\n\t\t\t\t\t") ;
                printf("�������������½���ѡ��!") ;
                getch() ;
        }
        manager_power() ;
    }
    while (x != 0) ;
}
void password_change() {
    char a[MAX], b[MAX] ;
    printf("\n\n\n\n\n\n\t\t\t\t\t�������޸ĺ������:\n\t\t\t\t\t") ;
    password_input(a) ;
    printf("\n\n\t\t\t\t\t��������һ����ȷ��:\n\t\t\t\t\t") ;
    password_input(b) ;
    FILE * fp = fopen("manager_cAp.txt", "wt") ;
    if (strcmp(a, b) != 0)
        puts("\n\t\t\t\t\t�������벻һ��!") ;
    else {
        puts("�޸ĳɹ�!") ;
        fprintf(fp, "%s\n", a) ;
    }
    fclose(fp) ;
}
void student_handle() {
    system ("cls") ;
    puts ("\n\n\n\n\n\n\t\t\t\t\t     **************************") ;
    puts("\t\t\t\t\t           1.�޸�ѧ���˺�") ;
    puts("\t\t\t\t\t           2.ɾ��ѧ���˺�") ;
    puts("\t\t\t\t\t           3.����ѧ���˺�") ;
    puts("\t\t\t\t\t           4.���ѧ���˺�") ;
    puts("\t\t\t\t\t           5.������һ��") ;
    puts("\t\t\t\t\t           0.�˳�") ;
    puts ("\t\t\t\t\t     **************************") ;
    printf ("\t\t\t\t\t     ��ѡ����Ҫ���еĲ���:\n\t\t\t\t\t     ") ;
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
                    printf("\t\t\t\t\t     ��������Ҫ�޸ĵ��˺�:") ;
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
                    printf("\n\t\t\t\t\t     ��ѡ�����˳�!") ;
                    sleep(1) ;
                    printf("\n\t\t\t\t\t     �����˳�...") ;
                    sleep(1) ;
                    printf("\n\t\t\t\t\t     ���˳�\n") ;
                    exit (0) ;
                default :
                    printf ("\t\t\t\t\t     ��������, ����������:\n");
                    printf("\t\t\t\t\t     �������������½���ѡ��!") ;
                    getch() ;
            }
        }
        else {
            printf("\t\t\t\t\t     ����������������һ��!") ;
            getch() ;
        }
        student_handle() ;
    }
    while (x != 0) ;
}
void teacher_handle() {
    system ("cls") ;
    puts ("\n\n\n\n\n\n\t\t\t\t\t     **************************") ;
    puts("\t\t\t\t\t\t  1.�޸Ľ�ʦ�˺�") ;
    puts("\t\t\t\t\t\t  2.ɾ����ʦ�˺�") ;
    puts("\t\t\t\t\t\t  3.���ҽ�ʦ�˺�") ;
    puts("\t\t\t\t\t\t  4.��ӽ�ʦ�˺�") ;
    puts("\t\t\t\t\t\t  5.������һ��") ;
    puts("\t\t\t\t\t\t  0.�˳�") ;
    puts ("\t\t\t\t\t     **************************") ;
    printf ("\t\t\t\t\t     ��ѡ����Ҫ���еĲ���:\n\t\t\t\t\t     ") ;
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
                    printf("\t\t\t\t\t     ��������Ҫ�޸ĵ��˺�:") ;
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
                    printf("\n\t\t\t\t\t     ��ѡ�����˳�!") ;
                    sleep(1) ;
                    printf("\n\t\t\t\t\t     �����˳�...") ;
                    sleep(1) ;
                    printf("\n\t\t\t\t\t     ���˳�\n") ;
                    exit (0) ;
                default :
                    printf ("\t\t\t\t\t     ��������, ����������:\n");
                    printf("\t\t\t\t\t     �������������½���ѡ��!") ;
                    getch() ;
            }
        }
        else {
            printf("\t\t\t\t\t     ����������������һ��!") ;
            getch() ;
        }
        teacher_handle() ;
    }
    while (x != 0) ;
}
