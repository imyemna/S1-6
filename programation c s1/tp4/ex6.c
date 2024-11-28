#include <stdio.h>


int main()
{
    char tab [100];
    char tabc [100];
    printf("entre une chaine du carachtere:\n");
    gets(tab);
    strcpy(tabc,tab);
    puts(tabc);
}