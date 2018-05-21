#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Y(int m, int n) {
    return n == 0 ? m : Y(n, m % n) ;
}
int main()
{
    int n, d, u, sum ;
    double gl ;
    d = u = sum = 0 ;
    scanf("%d", &n) ;
    char x[n] ;
    scanf("%s", x) ;
    for (int i=0; i<n; i++)
        if (x[i] == 'U')
            u ++ ;
        else if (x[i] == 'D')
            d ++ ;
        else if (x[i] == 'S')
            puts("Bigo") ;
    sum = u + d ;
    gl = u *1.0 / sum ;
    int y = Y(sum, u) ;
    if (fabs(gl-0.5)<=0.003)
        printf("%d/%d\n", u/y, sum/y) ;
    else
        printf("Fail\n") ;
    return 0;
}
