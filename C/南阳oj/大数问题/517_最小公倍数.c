#include <stdio.h>
#include <stdlib.h>

int Y (int m, int n) {
    return n == 0 ? m : Y (n, m % n) ;
}
int B (int m, int n) {
    return m * n / Y (m, n) ;
}
int main()
{
    int n ;
    int count = 0 ;
    while (scanf("%d", &n) != EOF && count <= 500) {
        count ++ ;
        int k ;
        if (n==1)
            k = 1 ;
        else
            k = B (n-1, n) ;
        printf("%d\n", k) ;
    }
    return 0;
}
