#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M ;
    scanf("%d", &N) ;
    while (N--) {
        scanf("%d", &M) ;
        putchar(M>=90?'A':M>=80?'B':M>=70?'C':M>=60?'D':'E') ;
        putchar('\n') ;
    }
    return 0;
}
