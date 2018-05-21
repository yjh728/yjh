#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int js (char * p, int n) {
    int count = 0 ;
    for (int i=0; i<n; i++)
        if (p[i] >= 'a' && p[i] <= 'z')
            count ++ ;
    return count % 26 ;
}
int main()
{
    int n ;
    scanf("%d", &n) ;
    getchar() ;
    while (n--) {
        char a[200] ;
        gets(a) ;
        int count = js(a, strlen(a)) ;
        if (count == 0)
            printf("%c\n", 'z') ;
        else
            printf("%c\n", count+96) ;
    }
    return 0;
}
