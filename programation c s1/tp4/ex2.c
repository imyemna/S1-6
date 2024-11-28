#include <stdio.h>

int main ()
{
    int tab [5]={10,20,30,40,50};
    int * ptr = tab;
    printf("la taille du tab est :%d octets\n",sizeof(tab));
    printf("la taille du ptr est :%d octets\n",sizeof(ptr));
}