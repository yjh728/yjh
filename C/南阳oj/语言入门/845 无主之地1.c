#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, j = 0 ;
    int a[100] = {0} ;
    int b[100] = {0} ;
    while (scanf("%d %d", &m, &n) != EOF) {
        if (m==0 && n==0)
            break ;
        a[m] += n ;
        b[j++] = m ;
    }
    j = 0 ;
    for (int i=0; i<99; i++)
        for (int j=i+1; j<100; j++)
            if (b[i]!=0&&b[j]!=0&&b[j]==b[i])
                b[j] = 0 ;
    for (j=0; j<100; j++)
        if (b[j]!=0)    printf("%d %d\n", b[j], a[b[j]]) ;
    return 0;
}
