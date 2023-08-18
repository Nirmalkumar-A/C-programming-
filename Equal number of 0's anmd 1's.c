#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int maxSubArrayEqual01(int arr[], int size) {
    int* diffIndices = (int*)malloc((2 * size + 1) * sizeof(int));
    for (int i = 0; i < 2 * size + 1; i++) {
        diffIndices[i] = -1;
    }

    int maxLen = 0;
    int diff = size;
    diffIndices[diff] = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            diff--;
        } else {
            diff++;
        }

        if (diffIndices[diff] != -1) {
            maxLen = max(maxLen, i - diffIndices[diff] + 1);
        } else {
            diffIndices[diff] = i + 1;
        }
    }

    free(diffIndices);
    return maxLen;
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxLength = maxSubArrayEqual01(arr, size);
    printf("Maximum subarray length with equal 0's and 1's: %d\n", maxLength);

    return 0;
}
