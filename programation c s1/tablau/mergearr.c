#include<stdio.h>

int main()
{
    int arr1[5],arr2[5];
    for (int  i = 0; i < 5; i++)
    {
        printf("Enter number : ");
        scanf("%d",&arr1[i]);
    }
    for (int  j = 0; j < 5; j++)
    {
        printf("Enter number : ");
        scanf("%d",&arr2[j]);
    }
    int mergarr[10];
    for (int k = 0; k < 5; k++)
    {
        mergarr[k] = arr1[k];
        mergarr[k+5] = arr2[k];
    }
    for (int m = 0; m < 10; m++)
    {
        printf("%d\n",mergarr[m]);
    }
    return 0;
}