#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5] ;
    int max = 0, min = 0 ;
    for (int i=0; i<5; i++)
        scanf("%d", &a[i]) ;
    for (int i=1; i<5; i++) {
        if (a[max]<a[i])    max = i ;
        if (a[min]>a[i])    min = i ;
    }
    printf("%d %d\n", a[min], a[max]) ;
    return 0;
}
