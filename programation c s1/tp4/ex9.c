#include <stdio.h>

int add (int a, int b)
{
    int som =a+b;
    return som;
}

int main ()
{
    int nb1,nb2;
    printf("entrer deux entier");
    scanf("%d",&nb1);
    scanf("%d",&nb2);
    int som=add(nb1,nb2);
    printf("%d",som);
    return 0;
}