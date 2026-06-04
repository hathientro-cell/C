#include <stdio.h>
#include <stdlib.h>

int binsearch(int n, int arr[], int key) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (key < arr[mid]) {
            r = mid - 1;
        } else if (key > arr[mid]) {
            l = mid + 1;
        } else {
            return mid; // found
        }
    }
    return -1; // not found
}

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    int temp[100];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int arr[10] = {10, 3, 5, 7, 2, 8, 1, 9, 6, 4};

    // Sort first
    mergeSort(arr, 0, 9);

    printf("Sorted array:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Then search
    int val = binsearch(10, arr, 2);
    if (val != -1)
        printf("Value Found at index %d\n", val);
    else
        printf("Value not found\n");

    return 0;
}
