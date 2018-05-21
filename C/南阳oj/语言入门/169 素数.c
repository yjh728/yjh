#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ss (int n) {
    if (n==2)
        return 1 ;
    else
        for (int i=2; i<=sqrt(n); i++)
            if (n % i == 0)
                return 0 ;
    return 1 ;
}
int Left (int n) {
    while (!ss(n--))
        continue ;
    return n + 1 ;
}
int Right (int n) {
    while (!ss(n++))
        continue ;
    return n - 1 ;
}
int main()
{
    int n ;
    scanf("%d", &n) ;
    while (n--) {
        int x ;
        scanf("%d", &x) ;
        if (x==1)
            printf("2\n") ;
        else {
            if (ss(x))
                printf("%d\n", x) ;
            else {
                int left = Left(x), right = Right(x);
                if (x-left >= right-x)
                    printf("%d\n", right) ;
                else
                    printf("%d\n", left) ;
            }
        }
    }
    return 0;
}
