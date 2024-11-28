#include <stdio.h>

int main ()
{
    int a =1,b=3;
    int * ptra=a;
    int * ptrb = b;
    printf("a = %d\nb = %d\n",a,b);
    a = ptrb;
    b = ptra;
    printf("a = %d\nb = %d",a,b);

    return 0;
}