//Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int orangesRotting(int grid[][10], int m, int n)
{
    int qr[100], qc[100];
    int front = 0, rear = 0;
    int fresh = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                qr[rear] = i;
                qc[rear] = j;
                rear++;
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    if (fresh == 0)
    {
        return 0;
    }

    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int minutes = 0;

    while (front < rear)
    {
        int size = rear - front;
        minutes++;

        for (int k = 0; k < size; k++)
        {
            int r = qr[front];
            int c = qc[front];
            front++;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dirs[d][0];
                int nc = c + dirs[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    fresh--;
                    qr[rear] = nr;
                    qc[rear] = nc;
                    rear++;
                }
            }
        }
    }

    if (fresh > 0)
    {
        return -1;
    }

    return minutes - 1;
}

int main()
{
    int m, n;

    printf("Enter rows: ");
    scanf("%d", &m);

    printf("Enter columns: ");
    scanf("%d", &n);

    int grid[10][10];

    printf("Enter grid values (0, 1, or 2):\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("grid[%d][%d]: ", i, j);
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, m, n);

    printf("Minimum minutes to rot all oranges: %d\n", result);

    return 0;
}