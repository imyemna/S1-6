#include <stdio.h>

int main ()
{
    int a,b,c;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("avnt A:%d B:%d",a,b);
    c=a;
    a=b;
    b=c;
    printf("apre A:%d B:%d",a,b);
}