//Return the minimum integer k such that she can eat all the bananas within h hours.

#include <stdio.h>
#include <stdlib.h>

int canFinish(int* piles, int n, long k, int h)
{
    long hours = 0;

    for (int i = 0; i < n; i++)
    {
        hours += (piles[i] + k - 1) / k;
    }

    return hours <= h;
}

int minEatingSpeed(int* piles, int n, int h)
{
    int lo = 1;
    int hi = 0;

    for (int i = 0; i < n; i++)
    {
        if (piles[i] > hi)
        {
            hi = piles[i];
        }
    }

    int result = hi;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (canFinish(piles, n, mid, h))
        {
            result = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return result;
}

int main()
{
    int n;

    printf("Enter number of piles: ");
    scanf("%d", &n);

    int piles[n];

    printf("Enter pile sizes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &piles[i]);
    }

    int h;

    printf("Enter hours available: ");
    scanf("%d", &h);

    int result = minEatingSpeed(piles, n, h);

    printf("Minimum eating speed: %d\n", result);

    return 0;
}