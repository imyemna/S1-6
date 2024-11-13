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
    int mergarr[5];
    for (int k = 0; k < 5; k++)
    {
        mergarr[k] = arr1[k] +  arr2[k];
    }
        printf("{");
    for (int m = 0; m < 5; m++)
    {
        if (m!=4)
        {
            printf("%d - ",mergarr[m]);
        }
        
        if (m==4)
        {
            printf("%d }",mergarr[m]);
        }
        
    }
    return 0;
}