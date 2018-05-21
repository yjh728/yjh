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
        //printf("\n\t���ļ�ʧ��, ʧ��ԭ��:%s\n", stderror(errno)) ;
        puts("\n\t�����������˳�!") ;
        getch() ;
        exit(1) ;
    }
    printf("\n\n\n\t�������û���(8λѧ��):") ;
    scanf("%s", aap1->account) ;
    fflush(stdin) ;
    while (!feof(fp)) {
        fscanf(fp, "%s %s\n", aap2->account, aap2->password) ;
        if (strcmp(aap1->account, aap2->account) == 0) {
            puts("\t���û��Ѵ���!������ע����¼!") ;
            printf("\t��������������ע�����!") ;
            getch() ;
            fclose(fp) ;
            free(aap1) ;
            free(aap2) ;
            student_interface() ;
        }
    }
    printf("\n\t����:\n\t") ;
    password_input (aap1->password) ;
    printf("\n\t��������һ�����ȷ��:\n\t") ;
    password_input(aap2->password) ;
    if (strcmp(aap1->password, aap2->password)) {
        puts("\n\t�������벻һ��!�����½���ע��!") ;
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
            //printf("\n\t���ļ�ʧ��, ʧ��ԭ��:%s\n", stderror(errno)) ;
            puts("\n\n\n\t�����������˳�!") ;
            getch() ;
            exit(1) ;
        }
        printf("\n\t�˺�:") ;
    }
    else {
        fp = fopen("student_cAp.txt", "rt") ;
        if (fp==NULL) {
            //printf("\n\t���ļ�ʧ��, ʧ��ԭ��:%s\n", stderror(errno)) ;
            puts("\n\n\n\t�����������˳�!") ;
            getch() ;
            exit(1) ;
        }
        printf("\n\n\n\t�˺�(8λѧ��):") ;
    }
    scanf("%s", aap1->account) ;
    fflush(stdin) ;
    while (!feof(fp)) {
        fscanf(fp, "%s %s\n", aap2->account, aap2->password) ;
        if (strcmp(aap1->account, aap2->account)==0) {
            printf("\n\t����:") ;
            for (int i=0; i<3; i++) {
                password_input (aap1->password) ;
                if (strcmp(aap1->password, aap2->password)==0) {
                    puts ("��¼�ɹ�!") ;
                    if (n==1)
                        student_power(aap1->account) ;
                    else
                        teacher_power(aap1->account) ;
                }
                else
                    printf("\n\t�������!����������(������%d�λ���):\n\t", 2-i) ;
            }
            printf("\t���Ѿ��������,ϵͳ��ǿ���˳�!\n");
            exit(1) ;
        }
    }
    fclose (fp) ;
    printf ("\t���û�������!����������ַ��˳�\n") ;
    getch () ;
    exit (1) ;
}
