#include <stdio.h>

int main()
{
    int i = 3;
    int *p,*q;
    printf("%d %d %d\n",&i,p,q);
    //*p=&i;
    p=&i;
    printf("%d %d %d\n",p,*p,i);
    *p=2025;
    printf("%d %d %d\n",p,*p,i);
    i=-34;
    printf("%d %d %d\n",p,*p,i);
    q=p;
    printf("%d %d %d\n",i,*p,*q);

    printf("%d %d %d %p\n",&i,&p,&q,&p);

    return 0;
}