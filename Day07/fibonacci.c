//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. 

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int* n;

    printf("Enter number of terms: ");
    scanf("%d", n);

    printf("Fibonacci Series: ");
    for(int i = 0; i < *n; i++){
        printf("%d ", fibonacci(i));
    }

    return 0;
}