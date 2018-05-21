#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, s ;
    scanf("%d", &s) ;
    while (s--) {
        scanf("%d %d", &m, &n) ;
        int sum = 0 ;
        for (int i=1; i<=m; i++) {
            int k = i ;
            while (k % n == 0 && k != 0) {
                sum ++ ;
                k /= n ;
            }
        }
        printf("%d\n", sum) ;
    }
    return 0;
}
