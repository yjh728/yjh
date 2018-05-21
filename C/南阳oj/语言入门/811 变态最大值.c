#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    while (scanf("%d", &n) == 1) {
        int a[n], b[n/3] ;
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]) ;
        int count = 0, j = 0 ;
        for (int i=0; i<n; i+=3) {
            count ++ ;
            if (count%2!=0)
                b[j++] = a[i]>a[i+1]?(a[i]>a[i+2]?a[i]:a[i+2]):(a[i+1]>a[i+2]?a[i+1]:a[i+2]) ;
            else
                b[j++] = a[i]>a[i+1]?(a[i+1]>a[i+2]?a[i+2]:a[i+1]):(a[i]>a[i+2]?a[i+2]:a[i]) ;
        }
        int max = b[0] ;
        for (int i=1; i<n/3; i++)
            if (max<b[i])
                max = b[i] ;
        printf("%d\n", max) ;
    }
    return 0;
}
