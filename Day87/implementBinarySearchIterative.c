//Problem: Implement Binary Search Iterative - Implement the algorithm.

#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp  = arr[j];
                arr[j]    = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int target)
{
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;

    printf("Enter target to search: ");
    scanf("%d", &target);

    int index = binarySearch(arr, n, target);

    if (index != -1)
    {
        printf("Found at index: %d\n", index);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}