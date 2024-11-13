#include <stdio.h>

int main()
{
    char str[100];
    printf("entrer une chaine se caractere :");
    fgets(str, sizeof(str),stdin);
    //scanf("%s",&str);
    for (int i = 0; str[i]!='\0'; i++)
    {
        printf("%c\n",str[i]);
    }
    return 0;
}