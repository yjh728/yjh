#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int a, b ;
        scanf("%d %d", &a, &b) ;
        for (int i=a; i<=b; i++) {
            int x[6] ;
            int y = i ;
            for (int i=5; i>=0; i--) {
                x[i] = y % 10 ;
                y /= 10 ;
            }
            int flag = 1 ;
            for (int i=0; i<6; i++)
                if (x[i]>6) {
                    flag = 0 ;
                    break ;
                }
            for (int i=0; i<4; i++)
                if (x[i]==x[i+1]&&x[i+1]==x[i+2]) {
                    flag = 0 ;
                    break ;
                }
            for (int j=0; j<5; j++)
                if (fabs(x[j]-x[j+1])>4) {
                    flag = 0 ;
                    break ;
                }
            if (flag) {
                for (int i=0; i<6; i++)
                    printf("%d", x[i]) ;
                putchar('\n') ;
            }
        }
        putchar('\n') ;
    }
    return 0;
}
