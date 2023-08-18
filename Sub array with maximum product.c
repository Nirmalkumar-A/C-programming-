#include <stdio.h>

int max(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int maxProductSubarray(int arr[], int size) {
    int maxEndingHere = arr[0];
    int minEndingHere = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < size; i++) {
        int temp = maxEndingHere;
        maxEndingHere = max(arr[i], maxEndingHere * arr[i], minEndingHere * arr[i]);
        minEndingHere = min(arr[i], temp * arr[i], minEndingHere * arr[i]);

        maxSoFar = max(maxSoFar, maxEndingHere, minEndingHere);
    }

    return maxSoFar;
}

int main() {
    int arr[] = {2, 3, -2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSubarrayProduct = maxProductSubarray(arr, size);
    printf("Maximum subarray product: %d\n", maxSubarrayProduct);

    return 0;
}
