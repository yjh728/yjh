#include <stdio.h>
#include <stdlib.h>

/*void swap (char *p, int m, int n)
{
    char x = p[m] ;
    p[m] = p[n] ;
    p[n] = x ;
}
void xzpx (char * p, int n)
{
    for (int i=0; i<n-1; i++) {
        int index = i ;
        for (int j=i+1; j<n; j++)
            if (p[index] > p[j])
                index = j ;
        if (index != i)
            swap(p, index, i) ;
    }
}
int main()
{
    int N ;
    char a[3] ;
    scanf("%d", &N) ;
    getchar();
    while (N--) {
        for (int i=0; i<3; i++)
            a[i] = getchar();
        getchar() ;
        xzpx(a, 3) ;
        for (int j=0; j<3; j++)
            printf("%c ", a[j]) ;
        printf("\n") ;
    }
    return 0;
}*/
int main(void)
{
    char a, b, c, d ;
    int m ;
    scanf("%d", &m) ;
    getchar() ;
    while (m--) {
        a = getchar() ;
        b = getchar() ;
        c = getchar() ;
        getchar() ;
        if (a>b) {
            d = a ;
            a = b ;
            b = d ;
        }
        if (a>c) {
            d = a ;
            a = c ;
            c = d ;
        }
        if (b>c) {
            d = b ;
            b = c ;
            c = d ;
        }
        printf("%c %c %c\n", a, b, c) ;
    }
}
