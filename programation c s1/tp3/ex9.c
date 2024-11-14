#include <stdio.h>

int main()
{
    int a[5]={1,2,3,4,5};
    int b[5]={1,2,3,4,5};
    int c[5];

    for (int i = 0; i < 5; i++)
    {
        c[i]=a[i]+b[i];
        printf("le troisemme tableau postion %d est %d\n",i,c[i]);
    }
    

}