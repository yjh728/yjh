#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    getchar() ;
    while (n--) {
        char a;
        int b ;
        scanf("%c %d", &a, &b) ;
        getchar() ;
        if (a>='A' && a<= 'Z')
            printf("%d\n", a - 65 + 1 + b) ;
        else if (a>='a' && a<='z')
            printf("%d\n", -(a - 97 + 1) + b) ;
    }
    return 0;
}
