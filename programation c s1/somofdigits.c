#include <stdio.h>

int main() {
    int a, sum = 0;
    
    // Prompt user to enter a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &a);
    
    // Calculate the sum of the digits
    while (a > 0) {
        sum += a % 10;  // Add the last digit to sum
        a /= 10;        // Remove the last digit
    }
    
    // Display the result
    printf("The sum of the digits is %d.\n", sum);
    
    return 0;
}