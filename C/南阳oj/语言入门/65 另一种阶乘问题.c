#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, n ;
    scanf("%d", &a) ;
    while (a--) {
        scanf("%d", &n) ;
        int sum = 0 ;
        for (int i=1; i<=n; i++) {
            int x = 1 ;
            for (int j=1; j<=i; j+=2)
                x *= j ;
            sum += x ;
        }
        printf("%d\n", sum) ;
    }
    return 0;
}
