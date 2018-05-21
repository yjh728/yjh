#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int jiangxuejin = 0 ;
struct student {
    char name[MAX] ;
    int qimo ;
    int pingyi ;
    char ganbu ;
    char xibu ;
    int lunwen ;
    int jiangxuejin ;
};
typedef struct student Item;
void Jiangxuejin (Item * item) {
    item -> jiangxuejin = 0 ;
    if (item -> qimo > 80 && item -> lunwen >= 1)
        item -> jiangxuejin += 8000 ;
    if (item -> qimo > 85 && item -> pingyi > 80)
        item -> jiangxuejin += 4000 ;
    if (item -> qimo > 90)
        item -> jiangxuejin += 2000 ;
    if (item -> qimo > 85 &&item -> xibu == 'Y')
        item -> jiangxuejin += 1000 ;
    if (item -> pingyi > 80 && item -> ganbu == 'Y')
        item -> jiangxuejin += 850 ;
}
int Max(const Item * a, int X) {
    int max = 0 ;
    for (int i=0; i<X; i++) {
        jiangxuejin += a[i].jiangxuejin ;
        if (a[max].jiangxuejin < a[i].jiangxuejin)
            max = i ;
    }
    return max ;
}
int main()
{
    int N, X ;
    scanf("%d", &N) ;
    while (N--) {
        scanf("%d", &X) ;
        Item a[100] ;
        for (int i=0; i<X; i++) {
            scanf("%s %d %d %c %c %d", a[i].name, &a[i].qimo, &a[i].pingyi
                  ,&a[i].ganbu, &a[i].xibu, &a[i].lunwen) ;
            Jiangxuejin(&a[i]) ;
        }
        int max = Max(a, X) ;
        printf("%s\n%d\n%d\n", a[max].name, a[max].jiangxuejin, jiangxuejin) ;
    }
    return 0;
}
