#include <stdio.h>
#include <stdlib.h>

void swap (int * p, int m, int n) {
    int x = p[m] ;
    p[m] = p[n] ;
    p[n] = x ;
}
int main()
{
    int n ;
    while (scanf("%d", &n) && n != 0) {
        int a[n] ;
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]) ;
        int min = 0 ;
        for (int i=0; i<n; i++)
            if (a[min]>a[i])
                min = i ;
        if (min != 0)
            swap(a, 0, min) ;
        for (int i=0; i<n; i++)
            printf("%d ", a[i]) ;
        putchar('\n') ;
    }
    return 0;
}
