#include <stdio.h>

int main()
{
    int a[5]={1,2,3,4,5};
    int b,pn=0;
    printf("entrer une valeur pour la rechercher dans le tableau :");
    scanf("%d",&b);
    for (int i = 0; i < 5; i++)
    {
        if (b == a[i])
        {
            printf("%d est a la position %d dans le tableau ",b,i);
            break;
            pn=1;
        }
    }
    if (pn==0)
    {
        printf("%d n'est pas dans le tableau",b);
    } 
    return 0;
}