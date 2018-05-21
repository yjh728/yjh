#include <stdio.h>
#include <stdlib.h>

void
int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int x ;
        scanf("%d", &x) ;
        long a[x][3] ;
        for (int i=0; i<x; i++)
            scanf("%ld %ld %ld",&a[i][0], &a[i][1], &a[i][2]) ;
    }
    return 0;
}
