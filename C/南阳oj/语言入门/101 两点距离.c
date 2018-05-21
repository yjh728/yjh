#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        float a, b, c, d ;
        scanf("%f %f %f %f", &a, &b, &c, &d) ;
        printf("%.2f\n", sqrt(pow(a-c, 2) + pow(b-d, 2))) ;
    }
    return 0;
}
