#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i ;
    scanf("%d", &i) ;
    for (int x=0; x<i; x++) {
        scanf("%d", &n) ;
        for (int y=1; y<=n; y++)
            if (y % 2 != 0)
                printf("%d ", y) ;
        printf("\n") ;
        for (int y=1; y<=n; y++)
            if (y % 2== 0)
                printf("%d ", y) ;
        printf("\n") ;
    }
    printf("\n") ;
    return 0;
}
