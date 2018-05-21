#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        long x ;
        scanf("%ld", &x) ;
        if (x<=10)
            printf("1\n") ;
        else
        {
            if (x % 10 <= 5)
                printf("%d\n", (x-1)/5) ;
            else
                printf("%d\n", x/5) ;
        }
    }
    return 0;
}
