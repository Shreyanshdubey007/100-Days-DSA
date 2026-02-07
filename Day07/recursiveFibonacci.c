//Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number
//where fib(0)=0 and fib(1)=1.

#include <stdio.h>

int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for(int i = 0; i < n; i++){
        printf("%d ", fibonacci(i));
    }

    return 0;
}