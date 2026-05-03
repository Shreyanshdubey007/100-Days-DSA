//Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.

#include <stdio.h>
#include <stdlib.h>

void relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* output)
{
    int count[1001] = {0};

    for (int i = 0; i < arr1Size; i++)
    {
        count[arr1[i]]++;
    }

    int idx = 0;

    for (int i = 0; i < arr2Size; i++)
    {
        while (count[arr2[i]] > 0)
        {
            output[idx++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    for (int i = 0; i <= 1000; i++)
    {
        while (count[i] > 0)
        {
            output[idx++] = i;
            count[i]--;
        }
    }
}

int main()
{
    int n, m;

    printf("Enter size of arr1: ");
    scanf("%d", &n);

    int arr1[n];

    printf("Enter arr1: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of arr2: ");
    scanf("%d", &m);

    int arr2[m];

    printf("Enter arr2: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int output[n];
    relativeSortArray(arr1, n, arr2, m, output);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}