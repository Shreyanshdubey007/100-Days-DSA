//Return the modified image after performing the flood fill.

#include <stdio.h>
#include <stdlib.h>

void dfs(int** image, int m, int n, int sr, int sc, int color, int origColor) {
    if (sr < 0 || sr >= m || sc < 0 || sc >= n) {
        return;
    }

    if (image[sr][sc] != origColor) {
        return;
    }

    image[sr][sc] = color;

    dfs(image, m, n, sr - 1, sc, color, origColor);
    dfs(image, m, n, sr + 1, sc, color, origColor);
    dfs(image, m, n, sr, sc - 1, color, origColor);
    dfs(image, m, n, sr, sc + 1, color, origColor);
}

void floodFill(int** image, int m, int n, int sr, int sc, int color) {
    int origColor = image[sr][sc];

    if (origColor != color) {
        dfs(image, m, n, sr, sc, color, origColor);
    }
}

void printImage(int** image, int m, int n) {
    printf("Output:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int m, n;

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    int** image = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        image[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter image grid:\n");

    for (int i = 0; i < m; i++) {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;

    printf("Enter starting row: ");
    scanf("%d", &sr);

    printf("Enter starting column: ");
    scanf("%d", &sc);

    printf("Enter new color: ");
    scanf("%d", &color);

    floodFill(image, m, n, sr, sc, color);

    printImage(image, m, n);

    for (int i = 0; i < m; i++) {
        free(image[i]);
    }

    free(image);

    return 0;
}