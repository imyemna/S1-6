#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n; 
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive step
}

int main () {
    fibonacci(9);
    printf("%d",fibonacci(9));
}