#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k ;
    scanf("%d %d", &n, &k) ;
    int a[n+1] ;
    for (int i=1; i<=n; i++)
        a[i] = i ;
    for (int i=2; i<=k; i++)
        for (int j=i; j<=n; j++)
            if (j % i == 0)
                a[j] = ! a[j] ;
    for (int i=1; i<=n; i++)
        if (a[i] != 0)
            printf("%d ", i) ;
    printf("\n") ;
    return 0;
}
