#include "Main_Menu.h"
#include "Schedule_UI.h"
#include "Studio_UI.h"
#include "Play_UI.h"
#include "Sale_UI.h"
#include "Account_UI.h"
#include "MaiAccount_UI.h"
#include "SalesAnalysis_UI.h"
#include "StaSales_UI.h"
#include <stdio.h>

#include "../View/Studio_UI.h"
void Main_Menu(account_t usr) {
	char choice;
	switch (usr.type) {
    case 0:
    case 9:
        do {
            system("cls");
            printf("\n==================================================================\n");
            printf("************************* 系统管理员界面 *************************\n");
            printf("                          1.维护个人资料\n");
            printf("                          2.管理系统用户\n");
            printf("                          3.管理演出厅\n");
            printf("                          0.退出系统\n");
            printf("\n==================================================================\n");
            printf("请输入你的选择:");
            scanf(" %c", &choice);
            fflush(stdin);
            switch (choice) {
            case '1':
                Account_UI_MgtEntry(1);
                break;
            case '2':
                Account_UI_MgtEntry(0);
                break;
            case '3':
                Studio_UI_MgtEntry();
                break;
            }
        } while (choice != '0');
        break;
    case 1:
        do {
            system("cls");
            printf("\n==================================================================\n");
            printf("*************************** 售票员界面 ***************************\n");
            printf("                            1.管理票(售票/退票)\n");
            printf("                            2.查看演出\n");
            printf("                            3.统计销售额\n");
            printf("                            4.维护个人资料\n");
            printf("                            0.退出\n");
            printf("\n==================================================================\n");
            printf("请输入你的选择:");
            scanf(" %c", &choice);
            fflush(stdin);
            switch (choice) {
                case '1':
                    Sale_UI_MgtEntry();
                    break;
                case '2':
                    Schedule_UI_Show();
                    break;
                case '3':
                    StaSales_UI_MgtEntry();
                    break;
                case '4':
                     Account_UI_MgtEntry(1);
                    break;
            }
        } while (choice != '0');
        break;
    case 2:
        do {
            system("cls");
            printf("\n==================================================================\n");
            printf("**************************** 经理界面 ****************************\n");
            printf("                            1.管理剧目\n");
            printf("                            2.查看演出\n");
            printf("                            3.统计销售额\n");
            printf("                            4.维护个人资料\n");
            printf("                            5.统计票房\n");
            printf("                            0.退出\n");
            printf("\n==================================================================\n");
            printf("请输入你的选择:");
            scanf(" %c", &choice);
            fflush(stdin);
            switch (choice) {
                case '1':
                    Play_UI_MgtEntry();
                    break;
                case '2':
                    Schedule_UI_Show();
                    break;
                case '3':
                    StaSales_UI_MgtEntry();
                    break;
                case '4':
                    Account_UI_MgtEntry(1);
                    break;
                case '5':
                    SalesAnalysis_UI_MgtEntry();
                    break;
            }
        } while (choice != '0');
        break;
	}
}

