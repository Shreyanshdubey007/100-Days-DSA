//Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j.
//Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once
//and then at the end come back to city 0 at minimum cost.

#include <stdio.h>
#include <limits.h>

#define MAX 15

int n;
int cost[MAX][MAX];
int visited[MAX];
int minCost = INT_MAX;

// TSP using backtracking
void tsp(int curr, int count, int currCost) {

    if (count == n && cost[curr][0]) {
        int totalCost = currCost + cost[curr][0];
        if (totalCost < minCost)
            minCost = totalCost;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[curr][i]) {
            visited[i] = 1;

            tsp(i, count + 1, currCost + cost[curr][i]);

            visited[i] = 0; // backtrack
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // initialize
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1; // start from city 0

    tsp(0, 1, 0);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}