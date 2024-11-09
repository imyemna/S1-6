#include <stdio.h>

int main ()
{
    int a,b;
    printf("Enter a number: ");
    scanf("%d",&a);
    b=1;
    for (int  i = 1; i <= a; i++)
    { 
        b = b*i;
    }
    printf("le factorielle du %d  est %d",a,b);
}