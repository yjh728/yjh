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
            printf("************************* ϵͳ����Ա���� *************************\n");
            printf("                          1.ά����������\n");
            printf("                          2.����ϵͳ�û�\n");
            printf("                          3.�����ݳ���\n");
            printf("                          0.�˳�ϵͳ\n");
            printf("\n==================================================================\n");
            printf("���������ѡ��:");
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
            printf("*************************** ��ƱԱ���� ***************************\n");
            printf("                            1.����Ʊ(��Ʊ/��Ʊ)\n");
            printf("                            2.�鿴�ݳ�\n");
            printf("                            3.ͳ�����۶�\n");
            printf("                            4.ά����������\n");
            printf("                            0.�˳�\n");
            printf("\n==================================================================\n");
            printf("���������ѡ��:");
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
            printf("**************************** ������� ****************************\n");
            printf("                            1.�����Ŀ\n");
            printf("                            2.�鿴�ݳ�\n");
            printf("                            3.ͳ�����۶�\n");
            printf("                            4.ά����������\n");
            printf("                            5.ͳ��Ʊ��\n");
            printf("                            0.�˳�\n");
            printf("\n==================================================================\n");
            printf("���������ѡ��:");
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

