#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d", &n) ;
    int a[100][100] = {0};
    int x = 0, y = n - 1, c ;
    c = a[x][y] = 1 ;
    while (c < n * n) {
        while (x < n - 1 && ! a[x+1][y])
            a[++x][y] = ++ c ;
        while (y > 0 && ! a[x][y-1])
            a[x][--y] = ++ c ;
        while (x > 0 && ! a[x-1][y])
            a[--x][y] = ++ c ;
        while (y < n - 1 && ! a[x][y+1])
            a[x][++y] = ++ c ;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            printf("%4d", a[i][j]) ;
        printf("\n") ;
    }
    return 0;
}
