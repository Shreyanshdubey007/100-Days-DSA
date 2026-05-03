//Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float val;
    struct Node *next;
} Node;

Node* insertSorted(Node *head, float val)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->val  = val;
    newnode->next = NULL;

    if (head == NULL || val < head->val)
    {
        newnode->next = head;
        return newnode;
    }

    Node *curr = head;

    while (curr->next != NULL && curr->next->val < val)
    {
        curr = curr->next;
    }

    newnode->next = curr->next;
    curr->next    = newnode;

    return head;
}

void bucketSort(float arr[], int n)
{
    Node **buckets = (Node**)calloc(n, sizeof(Node*));

    for (int i = 0; i < n; i++)
    {
        int idx      = (int)(arr[i] * n);
        buckets[idx] = insertSorted(buckets[idx], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        Node *curr = buckets[i];

        while (curr != NULL)
        {
            arr[k++]  = curr->val;
            Node *tmp = curr;
            curr      = curr->next;
            free(tmp);
        }
    }

    free(buckets);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter real numbers in [0, 1):\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}