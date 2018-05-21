#include <stdio.h>
#include <stdlib.h>

int zdgys (int a, int b) {
    return b == 0 ? a : zdgys(b, a%b) ;
}
/*
    int a, b, c ;
    scanf("%d %d", &a, &b) ;
    while (b) {
        c = a % b ;
        a = b ;
        b = c ;
    }
    printf("%d", b) ;
*/
int main()
{
    int n, i, j ;
    scanf("%d", &n) ;
    while (n--) {
        scanf("%d %d", &i, &j) ;
        int x ;
        x = zdgys(i, j) ;
        printf("%d %d\n", x, i*j/x) ;
    }
    return 0;
}
