#include <stdio.h>
#include <stdlib.h>

int sc (int x) {
    if (x==1)
        return 1 ;
    else
        return x + sc (x-1) ;
}
int main()
{
    int n ;
    scanf("%d", &n) ;
    while(n--) {
        int x ;
        scanf("%d", &x) ;
        int sum = 0 ;
        for (int i=1; i<=x; i++)
            sum += sc(i) ;
        printf("%d\n", sum) ;
    }
    return 0;
}
