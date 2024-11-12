#include<stdio.h>

int main()
{
    int longe,large;
    scanf("%d",&longe);
    scanf("%d",&large);
    char a[longe][large];
    for (int i = 0; i < longe; i++)
    {
        for (int j = 0; j < large; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("%s",a);
    return 0;
} 