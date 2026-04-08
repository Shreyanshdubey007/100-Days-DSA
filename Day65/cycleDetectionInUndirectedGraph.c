//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

#include <stdio.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int n)
{
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1)
        {
            if (!visited[i])
            {
                if (dfs(i, node, n))
                {
                    return 1;
                }
            }
            else if (i != parent)
            {
                return 1;
            }
        }
    }

    return 0;
}

int hasCycle(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, n))
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (hasCycle(n))
    {
        printf("Cycle detected: YES\n");
    }
    else
    {
        printf("Cycle detected: NO\n");
    }

    return 0;
}