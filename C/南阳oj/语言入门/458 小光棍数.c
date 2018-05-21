#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        long long x ;
        scanf("%lld", &x) ;
        printf("%lld\n", (x-1)*1000+471) ;
    }
    return 0;
}
