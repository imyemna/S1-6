#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;
    int **k=&p;
    printf("%i\n",a); // done la valeur
    printf("%p\n",a); // covertie la valeur en hexa
    printf("%p\n",&a); // done la l'adresse du variable a
    printf("%i\n",p); // done la valeur de la variable p
    printf("%i\n",*p); //done la valeur de la variable a
    printf("%p\n",&p); //done la l'adresse de la variable p
    printf("%i\n",*k); //done la valeur de la variable p
    printf("%p\n",&k); //done la l'adresse de la variable k
}
// %p est pour l'adresse
// * est pour extracter la valeur 
// & est pour obtenir l'adresse