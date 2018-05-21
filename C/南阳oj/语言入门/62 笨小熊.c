#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ss (int n) {
    if (n<2)
        return 0 ;
    else
        for (int i=2; i<=sqrt(n); i++)
            if (n % i == 0)
                return 0 ;
    return 1 ;
}
int yon (const char * p, int n) {
    int max = 0, min  = 100 ;
    int b [26] = {0};
    for (int i=0; i < n; i++)
        b[p[i]-'a'] ++ ;
    for (int i=0; i<26; i++) {
        if (max < b[i])
            max = b[i] ;
        if (b[i] != 0 && min > b[i])
            min = b[i] ;
    }
    if (ss(max - min))
        return (max - min) ;
    else
        return 0 ;
}
int main()
{
    char a [101] ;
    int N ;
    scanf("%d", &N) ;
    getchar() ;
    while (N--) {
        gets(a) ;
        int n = strlen(a) ;
        int m = yon(a, n) ;
        if (m)
            printf("Lucky Word\n%d\n", m) ;
        else
            printf("No Answer\n%d\n", m) ;
    }
    return 0;
}
