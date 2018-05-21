/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b ;
    while (scanf("%d %d", &a, &b) != EOF) {
        long sum = 0 ;
        for (int i=1; i<=a; i++)
            for (int j=1; j<=b; j++)
                sum += i * j ;
        printf("%ld\n", sum) ;
    }
    return 0;
}*/
#include <stdio.h>
int main()
{
    float a, b ;
    while (scanf("%f%f",&a,&b)==2)
        printf("%.0f\n",(a+1)*a*(b+1)*b/4);
}
