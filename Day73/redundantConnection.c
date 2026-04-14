//Return an edge that can be removed so that the resulting graph is a tree of n nodes.

#include <stdio.h>

#define MAX 1001

int parent[MAX];

// find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// union
void unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

int main() {
    int n;
    printf("Enter number of edges: ");
    scanf("%d", &n);

    int edges[n][2];

    printf("Enter edges:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // initialize
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int ans_u = -1, ans_v = -1;

    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (find(u) == find(v)) {
            ans_u = u;
            ans_v = v;
        } else {
            unionSet(u, v);
        }
    }

    printf("Redundant edge: [%d, %d]\n", ans_u, ans_v);

    return 0;
}