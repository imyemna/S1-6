#include <stdio.h>
#include<stdbool.h>
int main() {
    float decimalNumber;

    // Prompt user for a decimal number
    printf("Enter a decimal number: ");
    scanf("%f", &decimalNumber);


    // Convert to hexadecimal and octal and print
    printf("The hexadecimal representation is: %X\n", decimalNumber);
    printf("The hexadecimal representation is: %o\n", decimalNumber);
    while (true){

    }
    return 0;
}