#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int m ;
        scanf("%d", &m) ;
        for (int i=1; i<=m; i++) {
            for (int j=i; j<=9; j++)
                printf("%d*%d=%d ", i, j, i*j) ;
            putchar('\n') ;
        }
    }
    return 0;
}
