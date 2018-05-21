#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        char a[40], b[40] ;
        scanf("%s %s", a, b) ;
        strcat(a, b) ;
        for (int i=strlen(a); i>=0; i--)
            if (a[i] >= 'a' && a[i] <= 'z')
                putchar(a[i]) ;
        putchar('\n') ;
    }
    return 0;
}
