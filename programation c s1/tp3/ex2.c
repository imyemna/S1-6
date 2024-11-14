#include <stdio.h>

int main ()
{
    int a;
    printf("entrer un entier :");
    scanf("%d",&a);
    for (int i = 1; i < 11; i++)
    {
        printf("%d * %d = %d\n",a,i,a*i);
    }
    return 0;   
}