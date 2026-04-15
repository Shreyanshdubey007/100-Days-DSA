//Return the total number of provinces.

#include <stdio.h>
#define MAX 201

int n;
int isConnected[MAX][MAX];
int visited[MAX];

// DFS
void dfs(int city) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    // initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            provinces++;
        }
    }

    printf("Number of Provinces: %d\n", provinces);

    return 0;
}