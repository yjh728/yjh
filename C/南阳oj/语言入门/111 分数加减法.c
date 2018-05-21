#include <stdio.h>
#include <stdlib.h>

int Y (int a, int b) {
    return b == 0 ? a : Y (b, a % b) ;
}

int main()
{
    int a, b, c, d ;
    char o ;
    while (scanf("%d/%d%c%d/%d",&a, &b, &o, &c, &d) != EOF) {
        int fz, fm ;
        switch (o) {
            case '-' : fz = a * d - b * c ; break ;
            case '+' : fz = a * d + b * c ; break ;
        }
        fm = b * d ;
        if (fz) {
            if (abs(fz % fm)) {
                if (fz>0)   printf("%d/%d\n", fz / Y (fz, fm), fm / Y (fz, fm)) ;
                else printf("%d/%d\n", - fz / Y (fz, fm), - fm / Y (fz, fm)) ;
            }
            else printf("%d\n", fz / fm) ;
        }
        else printf("0\n") ;
    }
    return 0;
}
