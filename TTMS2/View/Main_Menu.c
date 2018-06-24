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
	int choice;
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
            fflush(stdin);
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                Account_UI_MgtEntry(1);
                break;
            case 2:
                Account_UI_MgtEntry(0);
                break;
            case 3:
                Studio_UI_MgtEntry();
                break;
            }
        } while (choice != 0);
        break;
    case 1:
        do {
            system("cls");
            printf("\n==================================================================\n");
            printf("*************************** ��ƱԱ���� ***************************\n");
            printf("                            1.��Ʊ\n");
            printf("                            2.�鿴�ݳ�\n");
            printf("                            3.�鿴�ݳ�Ʊ\n");
            printf("                            4.ͳ�����۶�\n");
            printf("                            5.ά����������\n");
            printf("                            6.��Ʊ\n");
            printf("                            0.�˳�\n");
            printf("\n==================================================================\n");
            printf("���������ѡ��:");
            fflush(stdin);
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    Sale_UI_MgtEntry();
                    break;
                case 2:
                    Schedule_UI_ListAll();
                    break;
                case 3:
                    Ticket_UI_Query();
                    break;
                case 4:
                    Sale_UI_MgtEntry();
                    break;
                case 5:
                     Account_UI_MgtEntry(1);
                    break;
                case 6:
                    Sale_UI_ReturnTicket();
                    break;
            }
        } while (choice != 0);
        break;
    case 2:
        do {
            system("cls");
            printf("\n==================================================================\n");
            printf("**************************** ������� ****************************\n");
            printf("                            1.�����Ŀ\n");
            printf("                            2.�鿴�ݳ�\n");
            printf("                            3.�鿴�ݳ�Ʊ\n");
            printf("                            4.ͳ�����۶�\n");
            printf("                            5.ά����������\n");
            printf("                            6.ͳ��Ʊ��\n");
            printf("                            0.�˳�\n");
            printf("\n==================================================================\n");
            printf("���������ѡ��:");
            fflush(stdin);
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    Play_UI_MgtEntry();
                    break;
                case 2:
                    Schedule_UI_ListAll();
                    break;
                case 3:
                    Ticket_UI_Query();
                    break;
                case 4:
                    StaSales_UI_MgtEntry();
                    break;
                case 5:
                     Account_UI_MgtEntry(1);
                    break;
                case 6:
                    SalesAnalysis_UI_MgtEntry();
                    break;
            }
        } while (choice != 0);
        break;
	}
}

