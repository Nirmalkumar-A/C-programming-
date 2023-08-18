#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void longestSubarrayWithSum(int arr[], int size, int targetSum) {
    int maxLength = 0;
    int endIndex = -1;

    int currentSum = 0;
    int startIndex = 0;
    int sumMap[100000];

    for (int i = 0; i < size; i++) {
        currentSum += arr[i];

        if (currentSum == targetSum) {
            maxLength = i + 1;
            endIndex = i;
        }

        if (sumMap[currentSum - targetSum] != 0) {
            if (maxLength < i - sumMap[currentSum - targetSum] + 1) {
                maxLength = i - sumMap[currentSum - targetSum] + 1;
                endIndex = i;
            }
        }

        if (sumMap[currentSum] == 0) {
            sumMap[currentSum] = i + 1;
        }
    }

    if (endIndex == -1) {
        printf("No subarray found with the given sum.\n");
    } else {
        printf("Longest subarray with sum %d is from index %d to %d.\n", targetSum, endIndex - maxLength + 1, endIndex);
    }
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 15;

    longestSubarrayWithSum(arr, size, targetSum);

    return 0;
}
