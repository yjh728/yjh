#include <stdio.h>
#include <stdlib.h>

int isrunnian  (int n) {
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        return 1 ;
    else
        return 0 ;
}
int main()
{
    int n, y, r, N ;
    scanf("%d", &N) ;
    while (N--) {
        scanf("%d %d %d", &n, &y, &r) ;
        int t = 0 ;
        if (isrunnian(n)) {
            for (int i=1; i<y; i++)
            switch (i) {
                case 1 : t += 31 ; break;
                case 2 : t += 29 ; break ;
                case 3 : t += 31 ; break;
                case 4 : t += 30 ; break;
                case 5 : t += 31 ; break;
                case 6 : t += 30 ; break;
                case 7 : t += 31 ; break;
                case 8 : t += 31 ; break;
                case 9 : t += 30 ; break;
                case 10 : t += 31 ; break;
                case 11 : t += 30 ; break;
                case 12 : t += 31 ; break;
            }
            t += r ;
        }
        else {
            for (int i=1; i<y; i++)
            switch (i) {
                case 1 : t += 31 ; break;
                case 2 : t += 28 ; break ;
                case 3 : t += 31 ; break;
                case 4 : t += 30 ; break;
                case 5 : t += 31 ; break;
                case 6 : t += 30 ; break;
                case 7 : t += 31 ; break;
                case 8 : t += 31 ; break;
                case 9 : t += 30 ; break;
                case 10 : t += 31 ; break;
                case 11 : t += 30 ; break;
                case 12 : t += 31 ; break;
            }
            t += r ;
        }
        printf("%d\n", t) ;
    }
    return 0;
}
