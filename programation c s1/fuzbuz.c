#include <stdio.h>

int main() 
{
    int a ;
    printf("Enter a number: ");
    scanf("%d", &a);
    if (a > 0) {
        for (int i=1;i<=a;i++)
        {
            if (i%3==0&&i%5==0)
            {
                printf("fuzz buzz\n");
            }else if (i%3==0)
            {
                printf("fuzz\n");
            }else if (i%5==0)
            {
                printf("buzz\n");
            }else if (i%3!=0&&i%5!=0) {
                printf("%d\n",i);
            }
        }
    }else{
        printf("invalid input");
    }
}