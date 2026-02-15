#include <stdio.h>

int main() {
    int n;

    printf("Enter Size of Square Matrix: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter Elements of Matrix(%dx%d):\n", n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
    sum += arr[i][i];
    }

    printf("The Sum of Diagonal Elements of Matrix: %d", sum);

    return 0;
}