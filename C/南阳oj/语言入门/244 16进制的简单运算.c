#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int n ;
    scanf("%d", &n) ;
    getchar() ;
    while (n--) {
        char a[15] ;
        gets(a) ;
        int sum = 0 ;
        int x = 0, y = strlen(a) ;
        for (int i=0; i<y; i++) {
            if (a[i] == '+' || a[i] == '-')
                break ;
            x ++ ;
        }
        y = y - x - 1 ;
        if (strchr(a, '+')) {
            for (int i=x-1, j=0; i>=0; i--, j++)
                if (a[i]>='0' && a[i] <='9')
                    sum += (a[i]-'0') * pow(16, j) ;
                else
                    sum += (a[i]-'a'+10)*pow(16, j) ;
            for (int i=strlen(a)-1, j=0; i>=x+1;i--, j++)
                if (a[i]>='0' && a[i] <='9')
                    sum += (a[i]-'0') * pow(16, j) ;
                else
                    sum += (a[i]-'a'+10)*pow(16, j) ;
        }
        else {
            for (int i=x-1, j=0; i>=0; i--, j++)
                if (a[i]>='0' && a[i] <='9')
                    sum += (a[i]-'0') * pow(16, j) ;
                else
                    sum += (a[i]-'a'+10)*pow(16, j) ;
            for (int i=strlen(a)-1, j=0; i>=x+1;i--, j++)
                if (a[i]>='0' && a[i] <='9')
                    sum -= (a[i]-'0') * pow(16, j) ;
                else
                    sum -= (a[i]-'a'+10)*pow(16, j) ;
        }
        printf("%o\n", sum) ;
    }
    return 0;
}
