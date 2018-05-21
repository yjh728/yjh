#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sushu (int m) {
    if (m<=1)
        return 0;
    else if (m==2)
        return 1;
    else
        for (int i=2; i<sqrt(m); i++)
            if (m % i == 0)
                return 0 ;
    return 1;
}
int main()
{
    int m, n ;
    scanf("%d", &m) ;
    while (m--) {
        scanf("%d", &n) ;
        int a, sum =0 ;
        for (int j=0; j<n; j++) {
            scanf("%d", &a) ;
            if (sushu(a))
                sum += a ;
        }
        printf("%d\n", sum) ;
    }
    return 0;
}
