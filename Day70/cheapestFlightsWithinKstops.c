//You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
//If there is no such route, return -1.

#include <stdio.h>

#define MAX 100
#define INF 999999

int main() {
    int n, m;
    int flights[MAX][3];
    int dist[MAX], temp[MAX];
    int src, dst, k;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter number of flights: ");
    scanf("%d", &m);

    printf("Enter flights (u v cost):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);
    }

    printf("Enter source, destination, k: ");
    scanf("%d %d %d", &src, &dst, &k);

    // initialize
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Bellman-Ford (k+1 times)
    for (int i = 0; i <= k; i++) {

        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < m; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    if (dist[dst] == INF)
        printf("Output: -1\n");
    else
        printf("Output: %d\n", dist[dst]);

    return 0;
}