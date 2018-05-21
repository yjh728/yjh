#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n ;
    scanf("%d %d", &m, &n) ;
    while (m != 0 && n != 0) {
        int i, j, t, count = 0 ;
        i = m % 10 ;
        j = n % 10 ;
        t = i + j ;
        while (m) {
            if (t>=10){
                count ++ ;
                m /= 10 ;
                n /= 10 ;
                i = m % 10 ;
                j = n % 10 ;
                t = i + j + 1 ;
            }
            else    {
                m /= 10 ;
                n /= 10 ;
                i = m % 10 ;
                j = n % 10 ;
                t = i + j ;
            }
        }
        printf("%d\n", count) ;
        scanf("%d %d", &m, &n) ;
    }
    return 0;
}
