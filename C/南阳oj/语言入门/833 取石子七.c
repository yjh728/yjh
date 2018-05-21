#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    while (scanf("%d", &n) == 1) {
        if (n>=3)
            printf("Yougth\n") ;
        else
            printf("Hrdv\n") ;
    }
    return 0;
}
