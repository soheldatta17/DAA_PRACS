#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        // Find leftmost element greater than pivot
        while (i <= high && A[i] <= pivot)
        {
            i++;
        }

        // Find rightmost element less than or equal to pivot
        while (j >= low && A[j] > pivot)
        {
            j--;
        }

        // Swap elements if i is still less than j
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Swap the pivot element with A[j]
    A[low] = A[j];
    A[j] = pivot;

    return j;
}


void quickSort(int *A, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 31, 43, 2, 19};
    int n = (int)(sizeof(A)/sizeof(int));
    printf("Before Sorting : ");
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printf("After Sorting : ");
    printArray(A, n);
    return 0;
}
