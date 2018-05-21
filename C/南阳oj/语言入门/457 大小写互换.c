#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    getchar() ;
    while (n--) {
        char a[101] ;
        gets(a) ;
        for (int i=0; i<strlen(a); i++)
            if (a[i]>='A' && a[i]<='Z')
                a[i] += 32 ;
            else
                a[i] -= 32 ;
        puts(a) ;
    }
    return 0;
}
