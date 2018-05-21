#include<stdio.h>
#include<string.h>
int main()
{
    int n ;
    scanf ("%d", &n) ;
    while (n--)  {
        char s[100] ;
        scanf ("%s", s);
        int l = strlen(s) ;
        int flag = 0 ;
        while (l % 2 == 0) {
            for (int i=0; i<=l/2; i++)
                if(s[i]!=s[l-i-1]) {
                    flag = 1 ;
                    break ;
                }
            if (flag == 0)
                l = l / 2 ;
            else  {
                printf("%d\n", l) ;
                break ;
            }
        }
        if (l % 2 != 0)
            printf("%d\n", l) ;
    }
    return 0;
}
