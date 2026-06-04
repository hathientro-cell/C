#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);

        quickSort(a, p + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
