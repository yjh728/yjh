#include "head.h"

Linklist_student head = NULL ;      //ѧ����Ϣ����
Linklist_aap aap_s = NULL ;         //ѧ���˺���Ϣ����
Linklist_aap aap_t = NULL ;         //��ʦ�˺���Ϣ����
int changdu  = 0 ;

int main()
{
    head = export1() ;              //ѧ����Ϣ���ļ���������
    aap_s = export2(1) ;            //ѧ���˺ŵ�������
    aap_t = export2(2) ;            //��ʦ�˺ŵ�������
    show() ;                        //ѧ������ϵͳ����
    return 0 ;
}
