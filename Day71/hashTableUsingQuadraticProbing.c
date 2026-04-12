//Problem Statement: Implement a hash table using quadratic probing with formula:

#include <stdio.h>
#include <string.h>
#define EMPTY -1

int table[1000];
int m;

int hash(int k)
{
    return k % m;
}
void insert(int k)
{
    int i = 0;

    while (i < m)
    {
        int pos = (hash(k) + i * i) % m;

        if (table[pos] == EMPTY)
        {
            table[pos] = k;
            return;
        }

        i++;
    }
}
void search(int k)
{
    int i = 0;

    while (i < m)
    {
        int pos = (hash(k) + i * i) % m;

        if (table[pos] == k)
        {
            printf("FOUND\n");
            return;
        }

        if (table[pos] == EMPTY)
        {
            break;
        }

        i++;
    }

    printf("NOT FOUND\n");
}
int main()
{
    int n;

    scanf("%d", &m);
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
    {
        table[i] = EMPTY;
    }

    for (int i = 0; i < n; i++)
    {
        char op[10];
        int k;

        scanf("%s %d", op, &k);

        if (strcmp(op, "INSERT") == 0)
        {
            insert(k);
        }
        else if (strcmp(op, "SEARCH") == 0)
        {
            search(k);
        }
    }
    return 0;
}