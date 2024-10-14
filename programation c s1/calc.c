#include <stdio.h>

int main() {
  char operator;
  double num1, num2;

  // Get the operator from the user
  printf("Enter operator (+, -, *, /): ");
  scanf(" %c", &operator);

  // Get the first number from the user
  printf("Enter first number: ");
  scanf("%lf ", &num1);
  // Get the scand number from the user
  printf("Enter second number: ");
  scanf("%lf",  &num2);

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
    default:
      printf("Error! Invalid operator.\n");
  }

  return 0;
}