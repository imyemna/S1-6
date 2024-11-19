#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game1 ()
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

int game2 ()
{
    int input ;
    srand(time(NULL));
    int a=rand()%10+1;
    do
    {
        printf("Enter a number entre 0 et 10: ");
        scanf("%d", &input);
        if (a<input)
        {
            printf("lil lower\n");
        }else if(a>input){
            printf("lil higher\n");
        }
        
    } while (input != a);
    printf("you win !\n");
    return 0;
}

int main()
{
    int input;
    do
    {
        printf("for game1 press 1\nfor game2 press 2\nfor exit press 0\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game1();
            break;
        
        case 2:
            game2();
            break;
        
        default:
            printf("thella\n");
            break;
        }
    } while (input != 0);
    
}