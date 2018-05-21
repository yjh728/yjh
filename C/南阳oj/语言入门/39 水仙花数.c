#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x ;
    scanf("%d", &x) ;
    while (x) {
        int k = x, sum = 0 ;
        while (k) {
        int i = k % 10 ;
        sum += i * i * i ;
        k /= 10 ;
        }
        if (x == sum)   printf("Yes\n") ;
        else    printf("No\n") ;
        scanf("%d", &x) ;
    }
    return 0;
}
