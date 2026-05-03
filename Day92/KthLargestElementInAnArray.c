//Given an integer array nums and an integer k, return the kth largest element in the array.

void heapifyDown(int *heap, int size, int i)
{
    int smallest = i;
    int left     = 2 * i + 1;
    int right    = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
    {
        smallest = left;
    }

    if (right < size && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        int temp       = heap[i];
        heap[i]        = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int *heap, int i)
{
    int parent = (i - 1) / 2;

    if (i > 0 && heap[i] < heap[parent])
    {
        int temp      = heap[i];
        heap[i]       = heap[parent];
        heap[parent]  = temp;
        heapifyUp(heap, parent);
    }
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int heap[k];
    int size = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (size < k)
        {
            heap[size] = nums[i];
            heapifyUp(heap, size);
            size++;
        }
        else if (nums[i] > heap[0])
        {
            heap[0] = nums[i];
            heapifyDown(heap, size, 0);
        }
    }

    return heap[0];
}