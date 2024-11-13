#include<stdio.h>

int main ()
{
    int a ;
    printf("Enter a number: ");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("lundi");
    break;
    case 2:
        printf("mardi");
    break;
    case 3:
        printf("mardi");
    break;
    case 4:
        printf("jeudi");
    break;
    case 5:
        printf("vendredi");
    break;
    case 6:
        printf("samedi");
    break;
    case 7:
        printf("dimanche");
    break;  
    default:
        printf("le numero de jour est invalid");
    break;
    }
}