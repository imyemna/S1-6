#include <stdio.h>

int main()
{
    int a,b;
    printf("entrer un nombre poir calculer son factoriel :");
    scanf("%d",&a);b=1;
    if (a==0) {printf("1");}
    for (int i = 1; i <= a; i++)
    {
        b=b*i;
    }
    printf("factorielle de %d est %d",a,b);
}