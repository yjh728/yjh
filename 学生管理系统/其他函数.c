#include "head.h"

extern Linklist_student head ;
extern Linklist_aap aap_s ;
extern Linklist_aap aap_t ;

void show () {				//ϵͳ����
    system("cls") ;
    printf("\n\n\n\n\n\n\t\t\t\t\t   ��ӭ����yjh728��ѧ������ϵͳ\n") ;
    printf("\t\t\t\t\t   ****************************\n") ;
    printf("\t\t\t\t\t           1.ѧ����¼   \n\t\t\t\t\t           2.��ʦ��¼\n") ;
    printf("\t\t\t\t\t           3.����Ա��¼ \n\t\t\t\t\t           0.�˳�\n") ;
    printf("\t\t\t\t\t   ****************************\n") ;
    printf("\t\t\t\t\t   ��ѡ����ݽ��е�¼\n\t\t\t\t\t   ") ;
    int x ;
    fflush(stdin) ;
    do {
        scanf("%d", &x) ;
        fflush(stdin) ;
        switch (x) {
            case 1 :
                student_interface () ;
                break ;
            case 2 :
                login(2) ;
                break ;
            case 3 :
                manager_interface () ;
                break ;
            case 0 :
                entering1(head) ;
                entering2(aap_s, 1) ;
                entering2(aap_t, 2) ;
                printf("\n\t\t\t\t\t   ��ѡ�����˳�!") ;
                sleep(1) ;
                printf("\n\t\t\t\t\t   �����˳�...") ;
                sleep(1) ;
                printf("\n\t\t\t\t\t   ���˳�\n") ;
                exit (0) ;
            default :
                printf("\t\t\t\t\t   �������, ������ѡ��!\n") ;
                printf("\t\t\t\t\t   �������������½���ѡ��!") ;
                getch() ;
        }
        show() ;
    }
    while (x != 0) ;
}

char * s_gets (char * p, int n) {			//�ַ������뼰����
    char * q, * find ;
    q = fgets(p, n, stdin) ;
    if (q) {
        find = strchr(p, '\n') ;
        if (find)
            * find = '\0' ;
        else
            while (getchar() != '\n')
                continue ;
    }
    return q ;
}
