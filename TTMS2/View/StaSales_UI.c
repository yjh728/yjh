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
        printf("抱歉,该账号没有权限!");
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
    printf("[D]查询当日销售额统计\n");
    printf("[M]查询当月销售额统计\n");
    printf("请选择你要进行的查询:");
    choice = getchar();
    fflush(stdin);
    switch (choice) {
        case 'm':
        case 'M':
            amount = SalesAnalysis_Srv_CompSaleVal(id, startdata, enddate);
            printf("ID为%d当月销售额为%d\n", id, amount);
            break;
        case 'd':
            amount = SalesAnalysis_Srv_CompSaleVal(id, curdate, curdate);
            printf("ID为%d当日销售额为%d\n", id, amount);
            break;
    }
    getchar();
}

void StaSales_UI_Clerk(){
    int id;
    ttms_date_t startdata, enddata;
    char Usrname[30];
    printf("请输入售票员名称:");
    gets(Usrname);
    fflush(stdin);
    account_t buf;
    if (Account_Srv_FetchByName(Usrname, &buf) == 0)
        printf("该用户不存在!");
    else {
        id = buf.id;
        printf("请输入开始日期(年/月/日):");
        scanf("%d/%d/%d", &startdata.year, &startdata.month, &startdata.day);
        fflush(stdin);
        printf("请输入结束日期(年/月/日):");
        scanf("%d/%d/%d", &enddata.year, &enddata.month, &enddata.day);
        fflush(stdin);
        int amount = SalesAnalysis_Srv_CompSaleVal(id, startdata, enddata);
        printf("这段时间ID为%d的售票员的销售额为%d\n", id, amount);
    }
    getchar();
}
