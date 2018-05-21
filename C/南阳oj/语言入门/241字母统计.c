#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n ;
    scanf("%d", &n) ;
    getchar() ;
    while (n--) {
        int a[26] = {0};
        char b ;
        while ((b=getchar()) != '\n')
            a[(int)(b-97)] ++ ;
        int max = 0 ;
        for (int i=0; i<26; i++)
            if (a[i]>a[max])
                max = i ;
        printf("%c\n", max+97) ;
    }
    return 0;
}
