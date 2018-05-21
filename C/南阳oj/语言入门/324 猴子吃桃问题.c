#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int m, x = 1 ;
        scanf("%d", &m) ;
        for (int i=m; i>0; i--)
            x = 2 * (x + 1) ;
        printf("%d\n", x) ;
    }
    return 0;
}
