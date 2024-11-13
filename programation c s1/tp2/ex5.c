#include<stdio.h>


int main()
{
    int N,som;
    som=1;
    printf("entre un nombre :");
    scanf("%d", &N);
    while (N >=1)
    {
        som = N*som;
        N--;
    }
    printf("la somme des N a 1 est %d",som);
}