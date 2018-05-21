#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int * p, int m, int n) {
    int x = p[m] ;
    p[m] = p[n] ;
    p[n] = x ;
}
void sort (int * p, int n) {
    for (int i=0; i<n-1; i++) {
        int x = i ;
        for (int j=i+1; j<n; j++)
            if (p[x]>p[j])
                x = j ;
        if (x!=i)
            swap(p, x, i) ;
    }
}
int main()
{
    int a, b[4] ;
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        scanf("%d", &a) ;
        int count = 1 ;
        while (1) {
            int z = a, x = 0, y = 0 ;
            int t = a ;
            for (int i=3; i>=0; i--) {
                    b[i] = t % 10 ;
                    t /= 10 ;
            }
            sort(b) ;
            for (int i=0; i<4; i++) {
                x = x * 10 + a[i] ;
                y = y * 10 + a[3-i] ;
            }
            if (z == y - x)
                break ;
            else {
                count ++ ;
                int t = y - x ;
                for (int i=3; i>=0; i--) {
                    a[i] = t % 10 ;
                    t /= 10 ;
                }
            }
        }
        printf("%d\n", count) ;
    }
    return 0;
}
