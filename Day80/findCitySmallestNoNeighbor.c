//Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int dist[MAX][MAX];

    // init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    // edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        dist[u][v] = w;
        dist[v][u] = w;
    }
    int threshold;
    scanf("%d", &threshold);

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int minCount = INT_MAX, city = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= threshold)
                count++;
        }

        if (count <= minCount) {
            minCount = count;
            city = i;
        }
    }
    printf("%d\n", city);
    return 0;
}