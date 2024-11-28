#include <stdio.h>
#include <string.h>
int main ()
{
    char chaine1[100], chaine2[100];

    printf("entrer  deux chaine de catactere :");
    gets(chaine1);
    gets(chaine2);
    int i = strcmp(chaine1,chaine2);
    if (i==0)
    {
        printf("les deux chain sont egau");
    }else if (i>0)
    {
        printf("la premiere chain est plus grand");
    }else {
        printf("la desieme chain est plus grand");
    }
    
    return 0;
}