#include "head.h"
// ѧ���˿�

extern Linklist_student head ;
extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;
void student_interface () {
    system ("cls") ;
    printf ("\n\n\n\n\n\n\t\t\t\t\t    ��ӭ����ѧ��ϵͳ\n") ;
    printf ("\t\t\t\t\t   *******************\n") ;
    printf ("\t\t\t\t\t        1.ע��   \n\t\t\t\t\t        2.��¼\n") ;
    printf ("\t\t\t\t\t        3.������һ��\n\t\t\t\t\t        0.�˳�\n") ;
    printf ("\t\t\t\t\t   *******************\n") ;
    printf ("\t\t\t\t\t  ��ѡ����Ҫ���еĲ���:\n\t\t\t\t\t  ") ;
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
                printf ("\n\t\t\t\t\t  ��ѡ�����˳�!") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t  �����˳�...") ;
                sleep (1) ;
                printf ("\n\t\t\t\t\t  ���˳�\n") ;
                exit(0) ;
            default :
                printf ("\t��������, ����������:\n\t") ;
                printf("�������������½���ѡ��!") ;
                getch() ;
        }
        student_interface() ;
    }
    while (x != 0) ;
}
void student_power(const char * p) {
    system("cls") ;
    puts("\n\n\n\n\n\n\t\t\t\t\t     ��ѡ����Ҫ���еĹ���:") ;
    puts("\t\t\t\t\t     ****************************") ;
    puts("\t\t\t\t\t           1.��ѯ���˳ɼ�") ;
    puts("\t\t\t\t\t           2.��ѯȫ��ɼ�") ;
    puts("\t\t\t\t\t           3.�ɼ�����") ;
    puts("\t\t\t\t\t           4.�޸�����") ;
    puts("\t\t\t\t\t           5.������һ��") ;
    puts("\t\t\t\t\t           0.�˳�") ;
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
                    printf("\n\n\n\t����\t\t\tѧ��\t\t\t����\t\t����\t\tc����\t\t��Ӣ\t\t�ܷ�\t\tƽ����\n") ;
                    printf("\t%d\t\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.1f\n", count, q->student.xuehao, q->student.name,
                        atoi(q->student.Advanced), atoi(q->student.C_language_programming), atoi(q->student.English), q->student.total,
                        q->student.average) ;
                }
                else {
                    puts("\t\t\t\t\t\t    ��Ǹ, �Ҳ�����ѧ��!") ;
                    puts("\t\t\t\t\t\t    ����������������һ��!") ;
                    getch() ;
                    student_power(p) ;
                }
                printf("\t����������������һ��\n") ;
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
                puts("\t\t\t\t\t     ��ѡ�����˳�!") ;
                sleep(1) ;
                puts("\t\t\t\t\t     �����˳�...") ;
                sleep(1) ;
                puts("\t\t\t\t\t     ���˳�\n") ;
                exit (0) ;
            default :
                puts("\t\t\t\t\t     �������, ������ѡ��:") ;
                printf("\t\t\t\t\t     �������������½���ѡ��:") ;
                getch() ;
        }
        student_power(p) ;
    }
    while (x != 0) ;
}
