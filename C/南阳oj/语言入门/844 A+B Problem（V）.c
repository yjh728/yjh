#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m[6], n[6] ;
    while (scanf("%s %s", m, n) == 2) {
        if (atoi(m)==0&&atoi(n)==0)
            break ;
        int x=strlen(m), y=strlen(n) ;
        char a[x+1], b[y+1] ;
        for (int i=x-1, j=0; i>=0; i--, j++)
            a[i] = m[j] ;
        a[x] = '\0' ;
        for (int i=y-1, j=0; i>=0; i--, j++)
            b[i] = n[j] ;
        b[y] = '\0' ;
        printf("%d\n", atoi(a) + atoi(b)) ;
    }
    return 0;
}
