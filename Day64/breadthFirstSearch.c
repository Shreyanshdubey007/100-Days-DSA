//Problem: Perform BFS from a given source using queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int val)
{
    queue[rear++] = val;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front == rear;
}

void bfs(int n, int s)
{
    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty())
    {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main()
{
    int n, e, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    bfs(n, s);

    return 0;
}