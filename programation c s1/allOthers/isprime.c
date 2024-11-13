#include <stdio.h>
#include <math.h>

int main()
{
    int nb;
    printf("enter a number to check if he is prime :");
    scanf("%d",&nb);
    for (int i = 2; i <= sqrt(nb); i++)
    {
        if (nb % i == 0)
        {
            printf("%d is not a prime number",nb);
        } else {
            printf("%d is prime",nb);
        }
    }
    return 0;
}