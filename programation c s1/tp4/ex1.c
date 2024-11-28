#include <stdio.h>

int main ()
{
    int tab[] = {10,20,30,40};
    for (int i = 0; i < 4; i++)
    {
        printf("le valeur intiale du tab en position %d est %d \n",i+1,tab[i]);
    }
    tab[2]=5;
    tab[0]=2;
    tab[2]=tab[1];
    printf("\n");
    for (int j = 0; j < 4; j++)
    {
        printf("le valeur finale du tab en position %d est %d \n",j+1,tab[j]);
    }
    
    return 0;
}