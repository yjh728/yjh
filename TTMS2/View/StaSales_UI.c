#include "StaSales_UI.h"
#include "../Common/List.h"
#include "../Service/Sale.h"
#include "../Service/Account.h"
#include "../Common/common.h"
#include "../Service/SalesAnalysis.h"
#include <stdio.h>
extern account_t gl_CurUser;

void StaSales_UI_MgtEntry (){
    if (gl_CurUser.type == USR_CLERK)
        StaSales_UI_Self();
    else if (gl_CurUser.type == USR_MANG)
        StaSales_UI_Clerk();
    else
        printf("��Ǹ,���˺�û��Ȩ��!");
}

void StaSales_UI_Self(){
    int id = gl_CurUser.id;
    ttms_date_t p, curdate, startdata, enddate;
    p = DateNow();
    curdate = p;
    p.day = 1;
    startdata = p;
    p.day = 31;
    enddate = p;
    char choice;
    int amount = 0;
    printf("[D]��ѯ�������۶�ͳ��\n");
    printf("[M]��ѯ�������۶�ͳ��\n");
    printf("��ѡ����Ҫ���еĲ�ѯ:");
    choice = getchar();
    fflush(stdin);
    switch (choice) {
        case 'm':
        case 'M':
            amount = SalesAnalysis_Srv_CompSaleVal(id, startdata, enddate);
            printf("IDΪ%d�������۶�Ϊ%d\n", id, amount);
            break;
        case 'd':
            amount = SalesAnalysis_Srv_CompSaleVal(id, curdate, curdate);
            printf("IDΪ%d�������۶�Ϊ%d\n", id, amount);
            break;
    }
    getchar();
}

void StaSales_UI_Clerk(){
    int id;
    ttms_date_t startdata, enddata;
    char Usrname[30];
    printf("��������ƱԱ����:");
    gets(Usrname);
    fflush(stdin);
    account_t buf;
    if (Account_Srv_FetchByName(Usrname, &buf) == 0)
        printf("���û�������!");
    else {
        id = buf.id;
        printf("�����뿪ʼ����(��/��/��):");
        scanf("%d/%d/%d", &startdata.year, &startdata.month, &startdata.day);
        fflush(stdin);
        printf("�������������(��/��/��):");
        scanf("%d/%d/%d", &enddata.year, &enddata.month, &enddata.day);
        fflush(stdin);
        int amount = SalesAnalysis_Srv_CompSaleVal(id, startdata, enddata);
        printf("���ʱ��IDΪ%d����ƱԱ�����۶�Ϊ%d\n", id, amount);
    }
    getchar();
}
