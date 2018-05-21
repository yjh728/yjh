#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int m ;
        scanf("%d", &m) ;
        while (m) {
            int t = m % 10 ;
            m /= 10 ;
            switch (t) {
                case 0 : putchar('O') ; break ;
                case 1 : putchar('O') ; break ;
                case 2 : putchar('T') ; break ;
                case 3 : putchar('T') ; break ;
                case 4 : putchar('F') ; break ;
                case 5 : putchar('F') ; break ;
                case 6 : putchar('S') ; break ;
                case 7 : putchar('S') ; break ;
                case 8 : putchar('E') ; break ;
                case 9 : putchar('N') ; break ;
            }
        }
        putchar('\n') ;
    }
    return 0;
}
