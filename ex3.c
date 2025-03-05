#include <stdio.h>

int main()
{
    int n,m,*p,*q;
    p=&n;
    q=&m;
    printf("entrer deux valeurs:");
    scanf("%d",p);
    scanf("%d",q);
    (*p)++;
    (*q)--;
    printf("%d %d\n",n,m);
    printf("%d %d",*p,*q);
    return 0;
}