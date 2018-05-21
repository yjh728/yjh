#include <stdio.h>
#include <stdlib.h>

void swap (int * p, int m, int n) {
    int x = p[m] ;
    p[m] = p[n] ;
    p[n] = x ;
}
void sort (int * p, int n) {
    for (int i=0; i<n-1; i++) {
        int x = i ;
        for (int j=i+1; j<n; j++)
            if (p[x]>p[j])
                x = j ;
        if (x!=i)
            swap(p, x, i) ;
    }
}
void qc (int * p, int n) {
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (p[i]!=0 && p[j]!=0 && p[j] == p[i])
                p[j] = 0 ;
}
void Print (int * p, int n) {
    int x = 0 ;
    for (int i=0; i<n; i++)
        if (p[i] != 0)
            x ++ ;
    printf("%d\n", x) ;
    for (int i=0; i<n; i++)
        if (p[i] != 0)
            printf("%d ", p[i]) ;
    putchar('\n') ;
}
int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int x ;
        scanf("%d", &x) ;
        int a[x] ;
        for (int i=0; i<x; i++)
            scanf("%d", &a[i]) ;
        sort(a, x) ;
        qc (a, x) ;
        Print(a, x) ;
    }
    return 0;
}
