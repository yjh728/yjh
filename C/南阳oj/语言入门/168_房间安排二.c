#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std ;  
int s[10005];  
int main()  
{  
    int i, j, n, test, ans, a, b, c ;  
    scanf ("%d", &test) ;  
    while (test--)  {  
        memset (s, 0, sizeof(s)) ;  
        scanf ("%d", &n) ;  
        for (i=0, ans=0; i<n; i++)  {  
            scanf ("%d %d %d", &a, &b, &c) ;  
            for (j=b; j<b+c; j++)  {  
                s[j] += a ;  
                ans = max (s[j], ans) ;   
            }  
        }  
        printf ("%d\n", ans) ;  
    }  
    return 0 ;  
}