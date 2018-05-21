#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n ;
    int count = 0 ;
    while (scanf("%d", &n) && n!=0) {
        count ++ ;
        char a[n][26] ;
        for (int i=0; i<n; i++)
            scanf("%s", a[i]) ;
        for (int i=0; i<n-1; i++) {
            int m = i ;
            for (int j=i+1; j<n; j++) {
                if (strlen(a[m])>strlen(a[j]))
                    m = j ;
            }
            if (m != i) {
                char b[26] ;
                strcpy(b, a[i]) ;
                strcpy(a[i], a[m]) ;
                strcpy(a[m], b) ;
            }
        }
        printf("SET %d\n", count) ;
        int i, j ;
        for (i=0; i<n; i+=2)
            puts(a[i]) ;
        if (i==n+1)     j = n - 2 ;
        else            j = n - 1 ;
        for (; j>=0; j-=2)
            puts(a[j]) ;
    }
    return 0;
}
