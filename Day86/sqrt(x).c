//Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

#include <stdio.h>

int mySqrt(int x)
{
    if (x < 2)
    {
        return x;
    }

    int lo = 1;
    int hi = x / 2;
    int result = 1;

    while (lo <= hi)
    {
        long mid = lo + (hi - lo) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            result = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return result;
}
int main()
{
    int x;
    printf("Enter a non-negative integer: ");
    scanf("%d", &x);
    int result = mySqrt(x);
    printf("Square root of %d (rounded down): %d\n", x, result);
    return 0;
}