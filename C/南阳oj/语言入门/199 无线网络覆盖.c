#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        double l, d, r ;
        scanf("%lf %lf %lf", &l, &d, &r) ;
        if (d>2*r)
            printf("impossible\n") ;
        else {
            double x = sqrt(4*r*r-d*d) ;
            if (x<1)
                printf("impossible\n") ;
            else if (d<2*r)
                printf("%d\n", (int)ceil(l/x)) ;
        }

    }
    return 0;
}
