#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b ;
    while (scanf("%d %d", &a, &b) == 2) {
        if (a*b>0)  printf("Signs are not opposot\n") ;
        else if (a*b<0)    printf("Signs are opposite\n") ;
        else    printf("Signs can't be sure\n") ;
    }
    return 0;
}
