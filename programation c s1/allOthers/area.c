#include <stdio.h>

int main() {
    float pi, R, S;
    printf("Enter the value of R: ");
    scanf("%f", &R);
    pi = 3.14;
    S = pi * R * R;  // Correct formula for area of a circle

    printf("The surface area is %f\n", S);  // Added semicolon and \n for newline
    return 0;  // Added return statement
}