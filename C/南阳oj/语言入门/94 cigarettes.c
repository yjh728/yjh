#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int a, b ;
        scanf("%d %d", &a, &b) ;
        int x = a, count = 0 ;
        while (x/b>0) {
            count ++ ;
            x -= b ;
            x += 1 ;
        }
        printf("%d\n", a + count) ;
    }
    return 0;
}
