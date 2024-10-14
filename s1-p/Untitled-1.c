#include<stdio.h>

int main() {
    int a,b,c;
    printf("give me a number:");
    scanf("%d",&a);
    
    printf("give me an  other number:");
    scanf("%d",&b);

    c=a+b;
    printf("sum A :%d and B:%d is %d\n",a,b,c);

    c=a-b;
    printf("A :%d minus B:%d is %d\n",a,b,c);

    c=a/b;
    printf("div A :%d and B:%d is %d\n",a,b,c);

    c=a*b;
    printf("multuply A :%d and B:%d is %d\n",a,b,c);

    c=a%b;
    printf("A :%d module B:%d is %d\n",a,b,c);
}
