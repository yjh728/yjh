#include<stdio.h>
#include<stdlib.h>
typedef struct student {        //����һ���ṹ��
    int x;
    struct student * llist;     //ǰ������ָ��
    struct student * rlist;     //��̽���ָ��
} Node, * linklist;             //Nodeλһ�����, linklistΪ����ָ��
linklist chuangjian() {         //β�巨��������
    int x;      //�洢һ����ʱֵ
    printf("������һ������, ���븺���˳�!");
    scanf("%d", &x);        //��ȡ��ʱֵ
    linklist head, p, q;
    head = (linklist) malloc (sizeof(Node));
    head->llist = NULL;
    head->rlist = NULL;
    p = head;
    while (x>=0) {
        //�����ʱֵΪ�Ǹ����ʹ���һ�����
        q = (linklist) malloc (sizeof(Node));
        //����ʱֵ��ֵ����������
        q->x = x;
        //ʹ�½���ǰ��ָ��ָ��ԭ����ǰһ�����
        q->llist = p;
        //ʹ�½��ĺ��ָ��ָ���
        q->rlist = NULL;
        //ʹǰһ�����ĺ��ָ��ָ���´����Ľ��
        p->rlist = q;
        //ʹpָ��ǰ���
        p = q;
        printf("��������һ������, ���븺���˳�!");
        //��ȡ��ʱֵ
        scanf("%d", &x);
    }
    q->rlist = head;
    head->llist = q;
    return head;
}
void add (linklist phead) {         //��ӽ�㵽����β��
    linklist n;
    n = (linklist) malloc (sizeof(Node));   //ΪҪ��ӵĽ�㶯̬�����ڴ�
    printf("��������Ҫ��ӵķǸ���:");
    scanf("%d", &n->x);     //��ȡ��ӵĽ�������
    n->rlist = phead;       //ʹ�½���ǰ��ָ��ͷ���
    n->llist = phead->llist; //ʹ�½��ĺ��ָ���һ�����
    phead->llist->rlist = n;    //ʹ���һ�����ĺ��ָ���½��
    phead->llist = n;       //ʹͷ���ĺ��ָ���½��
}
void del(linklist phead) {      //ɾ�����
    int x;
    printf("��������Ҫɾ��������:");
    scanf("%d", &x);       //��ȡҪɾ��������
    linklist p, q;
    p = q = phead;      //ʹp��q��ָ��ͷ���
    while (q->rlist != phead && q->x != x) {    //���q��Ϊ���һ���ڵ���q��ֵ��ΪҪɾ��������
        p = q;          //ʹpָ��ǰ���, ��ָ��ǰһ�����
        q = q->rlist;   //ʹqָ����һ�����
    }
    if (q->rlist == phead->rlist)   //��qָ��ͷ���, �����δ�ҵ�������
        puts("δ�ҵ�������!");
    else {                          //�ҵ�Ҫɾ��������
        p->rlist = q->rlist;        //ʹǰһ�����ָ��Ҫɾ������һ�����
        q->rlist->llist = p;        //ʹҪɾ������һ������ǰ��ָ��Ҫɾ����ǰһ�����
        free(q);                    //�ͷ�ɾ���Ľ��ռ�
    }
}
void Print(linklist phead, int n) {     //��ӡ��������
    linklist p = phead;  //pָ���һ�����
    if (n==1)           //n=1ʱ��ʾ�������
        while (p->rlist != phead) {     //��p��Ϊ���һ�����
            p = p->rlist;               //��pָ���һ�����
            printf("%d\n", p->x);       //��ӡ�ý�������
        }
    else                //�����ʾ�������
        while (p->llist != phead) {      //��p��Ϊ���һ�����
            p = p->llist;               //��pָ��ǰһ�����
            printf("%d\n", p->x);       //��ӡ�ý�������
        }
}
int main(void) {
    linklist head = NULL;
    head = chuangjian();
    Print(head, 1);
    Print(head, 2);
    add(head);
    Print(head, 1);
    Print(head, 2);
    del(head);
    Print(head,1);
    Print(head,2);
}
