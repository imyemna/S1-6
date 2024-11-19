#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;
    printf("%i\n",a); // done la valeur
    printf("%p\n",a); // covertie la valeur en hexa
    printf("%p\n",&a); // done la l'adresse du variable a
    printf("%i\n",p); //
    printf("%i\n",*p); //done la valeur de la variable a
    printf("%p\n",&p); //done la l'adresse de la variable p
}