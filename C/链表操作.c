#include<stdio.h>
#include<stdlib.h>
typedef struct student {        //定义一个结构体
    int x;
    struct student * llist;     //前驱结点的指针
    struct student * rlist;     //后继结点的指针
} Node, * linklist;             //Node位一个结点, linklist为结点的指针
linklist chuangjian() {         //尾插法创建链表
    int x;      //存储一个临时值
    printf("请输入一个数字, 键入负数退出!");
    scanf("%d", &x);        //获取临时值
    linklist head, p, q;
    head = (linklist) malloc (sizeof(Node));
    head->llist = NULL;
    head->rlist = NULL;
    p = head;
    while (x>=0) {
        //如果临时值为非负数就创建一个结点
        q = (linklist) malloc (sizeof(Node));
        //将临时值赋值给结点的数据
        q->x = x;
        //使新结点的前驱指针指向原本的前一个结点
        q->llist = p;
        //使新结点的后继指针指向空
        q->rlist = NULL;
        //使前一个结点的后继指针指向新创建的结点
        p->rlist = q;
        //使p指向当前结点
        p = q;
        printf("请输入下一个数字, 键入负数退出!");
        //获取临时值
        scanf("%d", &x);
    }
    q->rlist = head;
    head->llist = q;
    return head;
}
void add (linklist phead) {         //添加结点到链表尾部
    linklist n;
    n = (linklist) malloc (sizeof(Node));   //为要添加的结点动态分配内存
    printf("请输入你要添加的非负数:");
    scanf("%d", &n->x);     //获取添加的结点的数据
    n->rlist = phead;       //使新结点的前驱指向头结点
    n->llist = phead->llist; //使新结点的后继指向第一个结点
    phead->llist->rlist = n;    //使最后一个结点的后继指向新结点
    phead->llist = n;       //使头结点的后继指向新结点
}
void del(linklist phead) {      //删除结点
    int x;
    printf("请输入你要删除的数字:");
    scanf("%d", &x);       //获取要删除的数字
    linklist p, q;
    p = q = phead;      //使p和q都指向头结点
    while (q->rlist != phead && q->x != x) {    //如果q不为最后一个节点且q的值不为要删除的数字
        p = q;          //使p指向当前结点, 即指向前一个结点
        q = q->rlist;   //使q指向下一个结点
    }
    if (q->rlist == phead->rlist)   //若q指向头结点, 则表明未找到该数字
        puts("未找到该数字!");
    else {                          //找到要删除的数字
        p->rlist = q->rlist;        //使前一个结点指向要删除的下一个结点
        q->rlist->llist = p;        //使要删除的下一个结点的前驱指向要删除的前一个结点
        free(q);                    //释放删除的结点空间
    }
}
void Print(linklist phead, int n) {     //打印链表内容
    linklist p = phead;  //p指向第一个结点
    if (n==1)           //n=1时表示正序输出
        while (p->rlist != phead) {     //若p不为最后一个结点
            p = p->rlist;               //让p指向后一个结点
            printf("%d\n", p->x);       //打印该结点的数据
        }
    else                //否则表示逆序输出
        while (p->llist != phead) {      //若p不为最后一个结点
            p = p->llist;               //让p指向前一个结点
            printf("%d\n", p->x);       //打印该结点的数据
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
