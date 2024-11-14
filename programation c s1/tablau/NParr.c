#include <stdio.h>

int main()
{
    int a[10];
    int countp =0 , countn =0;
    for (int i = 0; i < 10; i++)
    {
        printf("entre la valeur negative et posi.. pour le tableau a :");
        scanf("%d", &a[i]);
    }
    for (int j = 0; j< 10; j++)
    {
        if (a[j]<0)
        {
            countn += a[j];
        }
        else 
        {
            countp += a[j];
        }
        
    }
    printf("la somme des valeur positif est :%d\n",countp);
    printf("la somme des valeur negatif est :%d",countn);
}