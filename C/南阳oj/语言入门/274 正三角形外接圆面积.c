#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main()
{
    int n ;
    scanf("%d", &n) ;
    for (int i=0; i<n; i++) {
        double a ;
        scanf("%lf", &a) ;
        printf("%.2lf\n", PI * a * a / 3) ;
    }
    return 0;
}
