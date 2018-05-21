#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int x, count = 0 ;
        scanf("%d", &x) ;
        for (int i=2; i*i<=x+1; i++)
            if ((x+1)%i==0)
                count ++ ;
        printf("%d\n", count) ;
    }
    return 0;
}
