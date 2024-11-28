#include <stdio.h>

int Rfactoriel ();

int main()
{
    int a;
    printf("entrer un nombre  ");
    scanf("%d",&a);
    int b =Rfactoriel(a);
    printf("le factoriel est :%d",b);
}

int Rfactoriel (int a )
{
    if (a==1||a==0){
        return 1;
    }
    return a* Rfactoriel(a-1);
}