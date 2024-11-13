#include<stdio.h>

int main()
{
    int a;
    printf("Enter un number entre 1 et 7: ");
    scanf("%d",&a);
    if (a<=7 && a>=1)
    {
       if (a==1)
    {
        printf("Lundi");
    }
    if (a==2)
    {
        printf("mardi");
    }
    if (a==3)
    {
        printf("mercredi");
    }
    if (a==4)
    {
        printf("jeudi");
    }
    if (a==5)
    {
        printf("vendredi");
    }
    if (a==6)
    {
        printf("samedi");
    }
    if (a==7)
    {
        printf("dimanche");
    }
    }else {
        printf("a n'est pas entre 1 et 7");
    }
}