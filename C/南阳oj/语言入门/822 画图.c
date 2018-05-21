#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    for (int i=0; i<n*n; i++) {
        putchar('*') ;
        if ((i+1) % n == 0) putchar('\n') ;
    }
    return 0;
}
