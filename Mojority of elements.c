#include <stdio.h>


int findMajority(int arr[], int size) {
    int candidate = -1;
    int count = 0;


    for (int i = 0; i < size; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else {
            if (arr[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
    }


    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > size / 2) {
        return candidate;
    } else {
        return -1; //
    }
}

int main() {
    int arr[] = {2, 2, 3, 2, 5, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int majorityElement = findMajority(arr, size);
    if (majorityElement != -1) {
        printf("Majority Element: %d\n", majorityElement);
    } else {
        printf("No Majority Element\n");
    }

    return 0;
}
