#include <stdio.h>

int main ()
{
    int tab []={10,20,30,40,50,60};
    int * ptr = tab;
    printf("la valeur  en troisieme position du tableau est : %d\n",tab[2]);
    printf("la valeur  en troisieme position du tableau est : %d\n",*(tab+2));
    printf("la valeur  en troisieme position du tableau est : %d\n",ptr[2]);
    printf("la valeur  en troisieme position du tableau est : %d\n",*(ptr+2));

}