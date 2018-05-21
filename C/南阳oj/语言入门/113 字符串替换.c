#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * s_gets (char * p, int n) {
    char * q, * find ;
    q = fgets(p, n, stdin) ;
    if (q) {
        find = strchr(p, '\n') ;
        if (find)
            * find = '\0' ;
        else
            while (getchar() != '\n')
                continue ;
    }
    return q ;
}
int main()
{
    char a[1000] ;
    while (s_gets(a, 1000) != NULL) {
        int n ;
        n = strlen(a) ;
        for (int i=0; i<n-2; i++)
            if (a[i]=='y' && a[i+1]=='o' && a[i+2]=='u') {
                a[i] = 'w' ;
                a[i+1] = 'e' ;
                for (int j=i+2; j<n; j++)
                    a[j] = a[j+1] ;
            }
        puts(a) ;
    }
    return 0;
}
