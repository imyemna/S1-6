#include <stdio.h>

int triple(int n);

int main ()
{
    int n ,n3;
    scanf("%d",&n);
    n3 = triple(n);
    char c;
    c = n;
    printf("%c\n",c);
    c = n3;
    printf("%d\n",n3);
    printf("%c\n",c);
    return 0;
}

int triple (int n)
{
    int a;
    a = n*3;
    return a;
}