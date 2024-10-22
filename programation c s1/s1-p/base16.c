#include <stdio.h>

int main() {
    int decimalNumber;

    // Prompt user for a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert to hexadecimal and print
    printf("The hexadecimal representation is: %X\n", decimalNumber);

    return 0;
}