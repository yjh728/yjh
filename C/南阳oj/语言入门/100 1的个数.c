#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M ;
    scanf("%d", &N) ;
    while (N--) {
        scanf("%d", &M) ;
        int count = 0 ;
        while (M) {
            if (M%2)
                count ++ ;
            M /= 2 ;
        }
        printf("%d\n", count) ;
    }
    return 0;
}
