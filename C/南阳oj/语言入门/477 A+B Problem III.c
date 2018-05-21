#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        float a, b, c ;
        scanf("%f %f %f", &a, &b, &c) ;
        if (fabs(a+b-c)<pow(10,-6))
            puts("Yes") ;
        else
            puts("No") ;
    }
    return 0;
}
