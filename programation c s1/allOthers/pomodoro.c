#include <stdio.h>
#include <unistd.h>

int main()
{
    int a;
    int sec=0,min=0;
    printf("Enter the number of cycles: ");
    scanf("%d",&a);
    for (int i = 0; i < a; i++)
    {
        printf("Time to focus!\n");
        for (int j = 0; j < 25 ; j++)
        {
            for (int l = 0; l < 59; l++)
            {
                //sleep(1);
                sec++;
                printf("\r%02d:%02d",min,sec);
                fflush(stdout);
            }
            sec = 0;
            min++;
        }
        min = 0;
        printf("\nCycle %d completed\n",i+1);
        if (a>=1)
        {
            printf("Time for a break!\n");
            for (int m = 0; m < 5 ; m++)
            {
                for (int p = 0; p < 59; p++)
                {
                    //sleep(1);
                    sec++;
                    printf("\r%02d:%02d",min,sec);
                    fflush(stdout);
                }
                sec = 0;
                min++;
            }
        }
    }
    return 0;
}
