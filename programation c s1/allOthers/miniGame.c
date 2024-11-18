#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int input;
    do
    {
        printf("1 = 7ajara\n2 = wara9a\n3 = mi9as\n0 =exit\n");
        scanf("%d",&input);
        int a=rand()%3;
        if (a==1&&input==1||a==2&&input==2||a==3&&input==3)
        {
            printf("drow t3adol\n");
        }else if (input == 1 && a == 3 || input == 2 && a == 1 || input == 3 && a == 2)
        {
            printf("you win rb7t al7mar\n");
        }else {
            printf("try again khsert al7mar\n");
        }
    } while (input != 0);
    printf("thella");
    return 0;
}