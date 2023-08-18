#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findSmallestMissingPositive(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        while (arr[i] > 0 && arr[i] <= size && arr[i] != arr[arr[i] - 1]) {
            swap(&arr[i], &arr[arr[i] - 1]);
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    return size + 1;
}

int main() {
    int arr[] = {3, 4, -1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int smallestMissing = findSmallestMissingPositive(arr, size);
    printf("Smallest missing positive integer: %d\n", smallestMissing);

    return 0;
}
