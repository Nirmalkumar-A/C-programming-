#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}


int maxSubArraySum(int arr[], int size) {
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < size; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, size);
    printf("Maximum subarray sum: %d\n", maxSum);

    return 0;
}
