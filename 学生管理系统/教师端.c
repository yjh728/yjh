#include "head.h"
//��ʦ�˿�
extern Linklist_student head ;
extern Linklist_aap aap_t ;
extern Linklist_aap aap_s ;
void teacher_power (const char * p) {
    system ("cls") ;
    puts ("\n\n\n\n\n\n\t\t\t\t\t     **************************") ;
    puts ("\t\t\t\t\t           1.ѧ����Ϣ¼��") ;
    puts ("\t\t\t\t\t           2.����ѧ����Ϣ") ;
    puts ("\t\t\t\t\t           3.ɾ��ѧ����Ϣ") ;
    puts ("\t\t\t\t\t           4.�޸�ѧ����Ϣ") ;
    puts ("\t\t\t\t\t           5.����ѧ����Ϣ") ;
    puts ("\t\t\t\t\t           6.��ӡѧ����Ϣ") ;
    puts ("\t\t\t\t\t           7.�ɼ�����") ;
    puts ("\t\t\t\t\t           8.�޸�����") ;
    puts ("\t\t\t\t\t           9.������һ��") ;
    puts ("\t\t\t\t\t           0.�˳�") ;
    puts ("\t\t\t\t\t     **************************") ;
    printf ("\n\t\t\t\t\t     ��ѡ����Ҫ���еĲ���:\n\t\t\t\t\t     ") ;
    int x ;
    do {
        scanf ("%d", &x) ;
        fflush (stdin) ;
        switch (x) {
            case 1 :
                head = chuangjian () ;
                break ;
            case 2 :
                add1 (head) ;
                break ;
            case 3 :
                del1 (head) ;
                break ;
            case 4 :
                change1 (head) ;
                break ;
            case 5 :
                find1 (head) ;
                break ;
            case 6 :
                sort() ;
                Print1 () ;
                break ;
            case 7 :
                Performance_analysis(head) ;
                break ;
            case 8 :
                if (change2(aap_t, p)) {
                    entering2(aap_t, 2) ;
                    show() ;
                }
                break ;
            case 9 :
                show() ;
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
                printf ("\t\t\t\t\t��������, ����������:\n");
                printf("�������������½���ѡ��!") ;
                getch() ;
        }
        teacher_power(p) ;
    }
    while (x != 0) ;
}
