//Return the total number of provinces.

#include <stdio.h>
#include <stdlib.h>

void dfs(int** isConnected, int* visited, int node, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[node][i] == 1 && visited[i] == 0) {
            dfs(isConnected, visited, i, n);
        }
    }
}

int findCircleNum(int** isConnected, int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(isConnected, visited, i, n);
            provinces++;
        }
    }

    free(visited);
    return provinces;
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int** isConnected = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        isConnected[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter %d x %d adjacency matrix:\n", n, n);

    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    printf("Number of provinces: %d\n", findCircleNum(isConnected, n));

    for (int i = 0; i < n; i++) {
        free(isConnected[i]);
    }

    free(isConnected);

    return 0;
}