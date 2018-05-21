#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, count = 0 ;
    scanf("%d", &n) ;
    while (n--) {
        count ++ ;
        int k ;
        scanf("%d", &k) ;
        int t = 1 ;
        int sum = 0 ;
        for (int i=1; i<=k; i++) {
            t += i + 1 ;
            sum += t * i ;
        }
        printf("%d %d %d\n", count, k, sum) ;
    }
    return 0;
}
