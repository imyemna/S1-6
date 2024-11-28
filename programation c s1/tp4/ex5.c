#include <stdio.h>

int main ()
{
    char tab [100];
    printf("entre une chaine du carachtere");
    gets(tab);
    printf("la longeur de cet chaine de carachtere est %d",strlen(tab));
}