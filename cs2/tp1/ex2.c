#include <stdio.h>

int main()
{
    int a=-2,b=a++,c=--b-2,*p1=&a,*p2=&b;printf(" %d %d %d %d %d \n",a,b,c,*p1,*p2);
    *p1=(*p2)+++2;printf(" %d %d %d %d %d \n",a,b,c,*p1,*p2);
    p1=p2;printf(" %d %d %d %d %d \n",a,b,c,*p1,*p2);
    p2=&c;printf(" %d %d %d %d %d\n",a,b,c,*p1,*p2);
    *p1-=(*p2)++;printf(" %d %d %d %d %d\n",a,b,c,*p1,*p2);
    ++*p2;printf(" %d %d %d %d %d\n",a,b,c,*p1,*p2);
    *p1*=++(*p2);printf("  %d %d %d %d %d\n",a,b,c,*p1,*p2);
    a= ++*p2 * *p1;printf(" %d %d %d %d %d\n",a,b,c,*p1,*p2);
    p1 =&a;printf(" %d %d %d %d  %d\n",a,b,c,*p1,*p2);
    *p2=*p1/=*p2;printf(" %d %d %d %d %d\n",a,b,c,*p1,*p2);

}