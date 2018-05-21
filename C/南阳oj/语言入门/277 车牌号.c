#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int m ;
        scanf("%d", &m) ;
        char a[m][6] ;
        for (int i=0; i<m; i++)
            scanf("%s", a[i]) ;
        int x = 0 ;
        for (int i=1; i<m; i++)
            if (strcmp(a[x], a[i]) > 0)
                x = i ;
        printf("%s\n", a[x]) ;
    }
    return 0;
}
