#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n ;
    while (scanf("%ld", &n) != EOF) {
        if (n==0)
            printf("0\n") ;
        else if (n==1)
            printf("1\n") ;
        else {
            int x[100] ;
            int t = n, i = 0, count = 0 ;
            while (t) {
                count ++ ;
                x[i++] = t % 2 ;
                t /= 2 ;
            }
            for (int i=count-1; i>=0; i--)
                printf("%d", x[i]) ;
            putchar('\n') ;
        }
    }
    return 0;
}
