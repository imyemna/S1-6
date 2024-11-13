#include<stdio.h>

int main ()
{
    int a;
    printf("Enter a number: ");
    scanf("%d",&a);
    if (a==0)
    {
        printf("a est null ");
    }
    
    if (a % 2==0)
    {
        printf("A : %d est pair.",a);
    } else {
        printf("A : %d est impair.",a);
    }
    return 0;
}