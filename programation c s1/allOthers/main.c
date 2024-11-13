#include <stdio.h>

int main(){
    int A;
    printf("Enter a value for A: ");
    scanf("%d", &A);

    for (int i = A; i >= 0 ; i--)
        printf("%d ", i);

    return 0;
}