//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCostConnectPoints(int points[][2], int n)
{
    int* minDist = (int*)malloc(n * sizeof(int));
    int* inMST   = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        minDist[i] = INT_MAX;
    }
    minDist[0] = 0;
    int totalCost = 0;

    for (int iter = 0; iter < n; iter++)
    {
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!inMST[i] && (u == -1 || minDist[i] < minDist[u]))
            {
                u = i;
            }
        }
        inMST[u] = 1;
        totalCost += minDist[u];

        for (int v = 0; v < n; v++)
        {
            if (!inMST[v])
            {
                int dist = abs(points[u][0] - points[v][0])
                         + abs(points[u][1] - points[v][1]);

                if (dist < minDist[v])
                {
                    minDist[v] = dist;
                }
            }
        }
    }
    free(minDist);
    free(inMST);

    return totalCost;
}
int main()
{
    int n;

    printf("Enter number of points: ");
    scanf("%d", &n);

    int points[n][2];

    printf("Enter points (x y):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Point %d: ", i + 1);
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    int result = minCostConnectPoints(points, n);

    printf("Minimum cost to connect all points: %d\n", result);

    return 0;
}