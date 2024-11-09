#include <unistd.h>
#include <stdio.h>

int main()
{
    int min ;

    printf("this program counts in min ");
    printf("enter number of mins ");
    scanf("%d",&min);
    min = min*60;
    for (int i = min; i >=0; i--)
    {
        printf("- %d \n",i);
        sleep(1);
    }
    
}