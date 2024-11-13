#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2;

    // Get the operator from the user
    printf("Enter operator (+, -, *, /, p=pow, s=sqrt, l=ln): ");
    scanf(" %c", &operator);

    // For sqrt and ln, we only need one number
    if (operator == 's' || operator == 'l') {
        printf("Enter number: ");
        scanf("%lf", &num1);
    } else {
        // Get the first number from the user
        printf("Enter first number: ");
        scanf("%lf", &num1);
        // Get the second number from the user
        printf("Enter second number: ");
        scanf("%lf", &num2);
    }

    // Perform the calculation based on the operator
    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero is not allowed.\n");
            } else {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            }
            break;
        case 'p': // For power
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2));
            break;
        case 's': // For square root
            if (num1 < 0) {
                printf("Error! Square root of a negative number is not allowed.\n");
            } else {
                printf("sqrt(%.2lf) = %.2lf\n", num1, sqrt(num1));
            }
            break;
        case 'l': // For natural logarithm
            if (num1 <= 0) {
                printf("Error! Natural logarithm of non-positive number is not allowed.\n");
            } else {
                printf("ln(%.2lf) = %.2lf\n", num1, log(num1));
            }
            break;
        default:
            printf("Error! Invalid operator.\n");
    }

    return 0;
}