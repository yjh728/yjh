#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main()
{
    float r ;
    while (scanf("%f", &r) != EOF)
        printf("%.0f\n", 4.0 / 3 * PI * r * r * r) ;
    return 0;
}
