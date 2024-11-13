#include <stdio.h>

int main()
{
    int a;
    printf("Enter the number of elements in that array: ");
    scanf("%d", &a);
    int nums[a],somm =0;
    for (int i = 0; i < a; i++)
    {
        printf("Enter number : ");
        scanf("%d",&nums[i]);
    }
    for (int j = 0; j < a; j++)
    {
        somm += nums[j];
    }
    
    printf("the avvreg of these nums is %d ",somm/a);

}