#include <stdio.h>
#include <stdlib.h>

int jttl (int n, int m) {
    for (int i=0; i<=n; i++) {
        int j = n - i ;
        if (i * 2 + j * 4 == m)     {
            printf("%d %d\n", i, j) ;
            return 0 ;
        }
    }
    return 1 ;
}
int main()
{
    int a, m, n ;
    scanf("%d", &a) ;
    while (a--) {
        scanf("%d %d", &n, &m) ;
        if (jttl(n, m))
            printf("No answer\n") ;
    }
    return 0;
}
