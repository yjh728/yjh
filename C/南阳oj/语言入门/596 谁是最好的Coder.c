#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    while (scanf("%d", &n) && n!=0) {
        int x, y ;
        scanf("%d %d", &x, &y) ;
        int max = x + y ;
        for (int i=1; i<n; i++) {
            scanf("%d %d", &x, &y) ;
            if (max<x+y)
                max = x + y ;
        }
        printf("%d\n", max) ;
    }
    return 0;
}
