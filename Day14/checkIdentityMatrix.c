//Problem: Write a program to check whether a given square matrix is an Identity Matrix.
//An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

#include <stdio.h>

int main() {
    int n;

    printf("Enter Size of Matrix: ");
    scanf("%d", &n);

    int arr[n][n];

    printf("Enter Elements of Matrix(%dx%d):\n", n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                if(arr[i][j] != 1){
                    printf("Not an Identity Matrix");
                    return 0;
                }
            }
            else{
                if(arr[i][j] != 0){
                    printf("Not an Identity Matrix");
                    return 0;
                }
            }
        }
    }

    printf("Identity Matrix");

    return 0;
}