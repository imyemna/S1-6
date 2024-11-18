#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
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