#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int min(int a, int b) {
    return (a < b) ? a : b;
    }

void findMaxProductPair(int arr[], int size) {
    if (size < 2) {
        printf("Array size must be at least 2.\n");
        return;
    }

    int firstMax = INT_MIN, secondMax = INT_MIN;
    int firstMin = INT_MAX, secondMin = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax) {
            secondMax = arr[i];
        }

        if (arr[i] < firstMin) {
            secondMin = firstMin;
            firstMin = arr[i];
        } else if (arr[i] < secondMin) {
            secondMin = arr[i];
        }
    }

    if (firstMax * secondMax >= firstMin * secondMin) {
        printf("Elements with maximum product: %d and %d\n", firstMax, secondMax);
        printf("Maximum product: %d\n", firstMax * secondMax);
    } else {
        printf("Elements with maximum product: %d and %d\n", firstMin, secondMin);
        printf("Maximum product: %d\n", firstMin * secondMin);
    }
}

int main() {
    int arr[] = {-10, -3, 5, 6, -2};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMaxProductPair(arr, size);

    return 0;
}
