#include "StaSales_UI.h"

#include "../Common/List.h"
#include "../Service/Sale.h"
#include "../Service/Account.h"
#include "../Common/common.h"
#include "../Service/SalesAnalysis.h"
#include <stdio.h>
extern account_t gl_CurUser;
//ͳ�����۶����
void StaSales_UI_MgtEntry (){
    if (gl_CurUser.type == USR_CLERK)
        StaSales_UI_Self();
    else if (gl_CurUser.type == USR_MANG)
        StaSales_UI_Clerk();
    else
        printf("��Ǹ,���˺�û��Ȩ��!");
}

//ͳ�Ƹ������۶����
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
    printf("[D]��ѯ�������۶�ͳ��\n");
    printf("[M]��ѯ�������۶�ͳ��\n");
    printf("��ѡ����Ҫ���еĲ�ѯ:");
    fflush(stdin);
    choice = getchar();
    fflush(stdin);
    switch (choice) {
        case 'm':
        case 'M':
            SalesAnalysis_Srv_CompSaleVal(id, startdata, enddate);
            break;
        case 'd':
            SalesAnalysis_Srv_CompSaleVal(id, curdate, curdate);
            break;
    }
}

//ͳ����ƱԱ���۶����
void StaSales_UI_Clerk(){
    int id;
    ttms_date_t startdata, enddata;
    char Usrname[30];
    printf("��������ƱԱ����:");
    fflush(stdin);
    gets(Usrname);
    account_t *buf;
    if (Account_Srv_FetchByName(Usrname, buf) == 0)
        printf("���û�������!");
    else {
        id = buf->id;
        printf("�����뿪ʼ����(��/��/��):");
        fflush(stdin);
        scanf("%d/%d/%d", &startdata.year, &startdata.month, &startdata.day);
        printf("�������������(��/��/��):");
        fflush(stdin);
        scanf("%d/%d/%d", &enddata.year, &enddata.month, &enddata.day);
        SalesAnalysis_Srv_CompSaleVal(id, startdata, enddata);
    }
}
