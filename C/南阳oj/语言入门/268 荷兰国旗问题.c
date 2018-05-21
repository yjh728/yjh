#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    getchar() ;
    while (n--) {
        char a[1001] ;
        gets(a) ;
        int x = strlen(a) ;
        for (int i=x; i>=0; i--)
            if (a[i] == 'R')
                putchar(a[i]) ;
        for (int i=x; i>=0; i--)
            if (a[i] == 'W')
                putchar(a[i]) ;
        for (int i=x; i>=0; i--)
            if (a[i] == 'B')
                putchar(a[i]) ;
        putchar('\n') ;
    }
    return 0;
}
