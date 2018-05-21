#include <stdio.h>
#include <stdlib.h>

int Fibonacci (int n)
{
    if (n==1 || n==2)
        return 1;
    else
        return (Fibonacci(n-1) + Fibonacci(n-2)) ;
}
int main()
{
    int m, n ;
    scanf("%d", &m) ;
    for (int i=0; i<m; i++) {
        scanf("%d", &n) ;
        printf("%d\n", Fibonacci (n) ) ;
    }
    return 0;
}
