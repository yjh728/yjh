#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int m, count = 0 ;
        float time = 0 ;
        scanf("%d", &m) ;
        for (int i=0; i<m; i++) {
            char a[5] ;
            float b ;
            scanf("%s", a) ;
            if (a[0] == 'I') count ++ ;
            else if (a[0] == 'O')   count -- ;
            else if (a[0] == 'S') {
                scanf("%f", &b) ;
                for (int i=0; i<count; i++)
                    b /= 20 ;
                time += b * 60 ;
            }
        }
        printf("%d\n", (int)time) ;
    }
    return 0;
}
