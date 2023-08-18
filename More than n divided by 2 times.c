#include <stdio.h>

// Function to find the majority element
int findMajority(int arr[], int size) {
    int candidate = -1;
    int count = 0;

    // Find a candidate for the majority element
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

    // Verify if the candidate is the majority element
    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > size / 2) {
        return candidate;
    } else {
        return -1; // No majority element
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
