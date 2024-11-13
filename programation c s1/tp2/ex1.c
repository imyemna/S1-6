#include<stdio.h>

int main() 
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    if ( a % 3 == 0 && a % 13 == 0)
    {
        printf("A :%d est devisible par 3 et 13",a);    
    } else {
        printf("A :%d n'est pas devisible par 3 et 13",a);
    }

    return 0;
}