#include <stdio.h>

int main ()
{
    int a,b,c;
    scanf("%d",&a);
    printf("%d",a);

    while (a != 0)
    {
        b =a%10;
        
        c = c * 10 + b;

        a = a / 10;
    }
    
    printf("image miroire de a est %d",c);

}