#include<stdio.h>
#include<stdlib.h>
typedef struct student {
    int x;
    struct student * llist;
    struct student * rlist;
} Node, * linklist;
linklist chuangjian() {
    int x;
    printf("请输入一个数字, 键入负数退出!");
    scanf("%d", &x);
    linklist head, p, q;
    head = (linklist) malloc (sizeof(Node));
    head->llist = NULL;
    head->rlist = NULL;
    p = head;
    while (x>=0) {
        q = (linklist) malloc (sizeof(Node));
        q->x = x;
        q->llist = p;
        q->rlist = NULL;
        p->rlist = q;
        p = q;
        printf("请输入下一个数字, 键入负数退出!");
        scanf("%d", &x);
    }
    q->rlist = head;
    head->llist = q;
    return head;
}
void add (linklist phead) {
    linklist n;
    n = (linklist) malloc (sizeof(Node));
    printf("请输入你要添加的非负数:");
    scanf("%d", &n->x);
    n->rlist = phead;
    n->llist = phead->llist;
    phead->llist->rlist = n;
    phead->llist = n;
}
void del(linklist phead) {
    int x;
    printf("请输入你要删除的数字:");
    scanf("%d", &x);
    linklist p, q;
    q = phead;
    p = phead;
    while (q->rlist != phead && q->x != x) {
        p = q;
        q = q->rlist;
    }
    if (q->rlist == phead->rlist)
        puts("未找到该数字!");
    else {
        p->rlist = q->rlist;
        q->rlist->llist = p;
        free(q);
    }
}
void Print(linklist phead, int n) {
    linklist p = phead;
    if (n==1)
        while (p->rlist != phead) {
            p = p->rlist;
            printf("%d\n", p->x);
        }
    else
        while (p->llist != phead) {
            p = p->llist;
            printf("%d\n", p->x);
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
