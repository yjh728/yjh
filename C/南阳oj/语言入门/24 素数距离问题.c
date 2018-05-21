#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ss (int n) {
    for (int i=2; i<=sqrt(n); i++)
        if (n%i==0)
            return 1 ;
    return 0 ;
}
int left (int n) {
    while (ss(--n))
        continue ;
    return n ;
}
int right (int n) {
    while (ss(++n))
        continue ;
    return n ;
}
int main()
{
    int n, m ;
    scanf("%d", &n) ;
    while (n--) {
        scanf("%d", &m) ;
        int x, y ;
        if (m==1)
            printf("2 1\n") ;
        else {
            if (!ss(m))
                printf("%d %d\n", m, 0) ;
            else {
                x = left(m) ;
                y = right(m) ;
                if (m-x<=y-m)   printf("%d %d\n", x, m-x) ;
                else    printf("%d %d\n", y, y-m) ;
            }
        }
    }
    return 0;
}
