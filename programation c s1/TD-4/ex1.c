#include <stdio.h>

int main()
{
    int a;
    printf("entrer un entier pour former son tableau de multiplication :");
    scanf("%d",&a);
    for (int i = 0; i < 11; i++)
    {
        printf("%d x %d = %d\n",a,i,a*i);
    }
    return 0;
}