#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char a[10],b[10];
    int n=0;
    while(scanf("%s%s",a,b)!=EOF){
        printf("Case %d: ",++n);
        if(a[1]=='b'){
            if(a[0]=='A')
                printf("G# ");
            else
                printf("%c# ",a[0]-1);
            puts(b);
        }
        else if(a[1]=='#'){
            if(a[0]=='G')
                printf("Ab ");
            else
                printf("%cb ",a[0]+1);
            puts(b);
        }
        else
            printf("UNIQUE\n");
    }
    return 0;
}
