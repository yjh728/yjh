#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[5] ;
    int count = 0 ;
    while (scanf("%s", a) != EOF) {
        getchar() ;
        count ++ ;
        if (strcmp(a,"I")==0)   printf("Case %d: 1\n", count) ;
        else if (strcmp(a,"II")==0) printf("Case %d: 2\n", count) ;
        else if (strcmp(a,"III")==0)    printf("Case %d: 3\n", count) ;
        else if (strcmp(a,"IV")==0) printf("Case %d: 4\n", count) ;
        else if (strcmp(a,"V")==0)  printf("Case %d: 5\n", count) ;
        else if (strcmp(a,"VI")==0) printf("Case %d: 6\n", count) ;
        else if (strcmp(a,"VII")==0)    printf("Case %d: 7\n", count) ;
        else if (strcmp(a,"VIII")==0)   printf("Case %d: 8\n", count) ;
        else if (strcmp(a,"IX")==0) printf("Case %d: 9\n", count) ;
        else if (strcmp(a,"X")==0)  printf("Case %d: 10\n", count) ;
        else if (strcmp(a,"XI")==0) printf("Case %d: 11\n", count) ;
        else if (strcmp(a,"XII")==0)    printf("Case %d: 12\n", count) ;
    }
    return 0;
}
