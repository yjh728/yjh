#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    getchar() ;
    while (n--) {
        char a, b ;
        scanf("%c %c", &a, &b) ;
        getchar() ;
        if (a>b)
            printf("%c<%c\n", a, b) ;
        else if (a==b)
            printf("%c=%c\n", a, b) ;
        else
            printf("%c>%c\n", a, b) ;
    }
    return 0;
}
