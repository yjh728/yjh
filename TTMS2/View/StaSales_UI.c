#include "StaSales_UI.h"

#include "../Common/List.h"
#include "../Service/Sale.h"
#include "../Service/Account.h"
#include "../Common/common.h"
#include "../Service/SalesAnalysis.h"
#include <stdio.h>
extern account_t gl_CurUser;
//统计销售额界面
void StaSales_UI_MgtEntry (){
    if (gl_CurUser.type == USR_CLERK)
        StaSales_UI_Self();
    else if (gl_CurUser.type == USR_MANG)
        StaSales_UI_Clerk();
    else
        printf("抱歉,该账号没有权限!");
}

//统计个人销售额界面
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
    printf("[D]查询当日销售额统计\n");
    printf("[M]查询当月销售额统计\n");
    printf("请选择你要进行的查询:");
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

//统计售票员销售额界面
void StaSales_UI_Clerk(){
    int id;
    ttms_date_t startdata, enddata;
    char Usrname[30];
    printf("请输入售票员名称:");
    fflush(stdin);
    gets(Usrname);
    account_t *buf;
    if (Account_Srv_FetchByName(Usrname, buf) == 0)
        printf("该用户不存在!");
    else {
        id = buf->id;
        printf("请输入开始日期(年/月/日):");
        fflush(stdin);
        scanf("%d/%d/%d", &startdata.year, &startdata.month, &startdata.day);
        printf("请输入结束日期(年/月/日):");
        fflush(stdin);
        scanf("%d/%d/%d", &enddata.year, &enddata.month, &enddata.day);
        SalesAnalysis_Srv_CompSaleVal(id, startdata, enddata);
    }
}
