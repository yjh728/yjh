#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, b ;
    int count = 0 ;
    while (scanf("%d %d", &a, &b) == 2) {
        count ++ ;
        int bh = 0, lx = 0 ;
        for (int i=a; i<=b; i++) {
            char x[6] ;
            int t = i ;
            for (int i=0; i<6 && t; i++) {
                x[i] = t % 10 + '0';
                t /= 10 ;
            }
            if (strchr(x, '1')&&strchr(x, '2')&&strchr(x, '5'))
                bh ++ ;
            if (strstr(x, "125"))
                lx ++ ;
        }
        printf("Case %d:%d %d\n", count, bh, lx) ;
    }
    return 0;
}
