#include <stdio.h>
#include <stdlib.h>

int pd(int n, int k) {
    for (int i=1; i<=n/2; i++)
        if (i*(n-i)==k)
            return 1 ;
    return 0 ;
}
int main()
{
    int n, k ;
    while (scanf("%d %d", &n, &k) ==2) {
        if (n==0&&k==0)
            break ;
        int flag = pd (n, k) ;
        if (flag)
            puts("YES") ;
        else
            puts("NO") ;
    }
    return 0;
}
