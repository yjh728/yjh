#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    int m, x, y, z ;
    scanf("%d", &n) ;
    while (n--) {
        float t ;
        scanf("%d %d %d %d", &m, &x, &y, &z) ;
        t = (m * x + 0.0) / (y - x) ;
        printf("%.2f\n", t * z) ;
    }
    return 0;
}
