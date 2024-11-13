#include <stdio.h>
#define A 1
int main()
{
    int arr1[10];
    int min,max;
    for (int  i = 0; i < A; i++)
    {
        printf("Enter number : ");
        scanf("%d",&arr1[i]);
        
    }
    min=arr1[0];
    min=arr1[0];
    for (int j = 0; j < A; j++)
    {
        if (arr1[j]<=min)
        {
            min=arr1[j];
        }
        if (arr1[j]>=max)
        {
            max=arr1[j];
        }
    }
    
    printf("max :%d \nmin :%d",max,min);
    return 0;

}
