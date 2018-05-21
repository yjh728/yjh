#include<stdio.h>  
#include<string.h>  
int main()  
{  
    char c[110];  
    while(scanf("%s",c+1) == 1)  {  
        c[0]='0';  
        int a,i,r=0,t=0;   
        a=strlen(c);  
        if(c[1]=='-')  {  
            c[1]='0';  
            r=1;  
        }   
        char *x;  
        if(x=strchr(c,'.'))  
            t=x-c;  
        if(t)  {  
            if(a-t==1)  {  
                c[t+1]='0';  
                c[t+2]='0';  
                c[t+3]=0;  
                a=t+3;  
            }  
            else if(a-t==2)  {  
                c[t+2]='0';  
                c[t+3]=0;  
                a=t+3;  
            }  
            else if(a-t>3)  {  
                int m;  
                if(c[t+3]>='5'&&c[t+3]<='9') m=1;  
                else m=0;  
                c[t+3]=0;  
                a=t+3;   
                for(i=t+2;i>=0;i--)  {  
                    if(i==t) continue;  
                    if(m)  
                        if(c[i]=='9') c[i]='0';  
                        else   {  
                            c[i]+=1;  
                            m=0;  
                         }  
                    else break;  
                }  
            }  
        }  
        else  {  
            t=a;  
            c[a]='.';  
            c[a+1]='0';  
            c[a+2]='0';  
            c[a+3]=0;  
            a+=3;  
              
        }    
        int k=0;               
        for(i=0;c[i]=='0';i++);  
        if(c[i]=='.') k=i-1;  
        else k=i;  
        if(r) putchar('(');  
          
        int sum,j=0,z,y;  
        z=t-k;  
        y=z/3;  
        z%=3;  
        for(i=k;i<k+z;i++,j++)  
             putchar(c[i]);  
        if(z&&y) putchar(',') ;
        for(i=k+z,sum=0;i<t;j++)  
        {  
            if(sum==3)  
            {  
                sum=0;  
                putchar(',');  
                continue;  
            }  
            putchar(c[i++]);  
            sum++;  
        }    
        putchar(c[t]);  
        putchar(c[t+1]);  
        putchar(c[t+2]);  
          
        if(r) putchar(')');  
        puts("");  
    }  
    return 0;  
}