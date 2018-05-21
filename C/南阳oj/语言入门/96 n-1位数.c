#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int M, w ;
    scanf("%d", &M) ;
    while (M--) {
        scanf("%d", &w) ;
        int t = w ;
        int count = 0 ;
        while (t) {
            count ++ ;
            t /= 10 ;
        }
        printf("%d\n", w % (int)(pow(10, count-1))) ;
    }
    return 0;
}
