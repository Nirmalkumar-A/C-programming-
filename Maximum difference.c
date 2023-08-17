#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_element = arr[0];
    int max_element = arr[0];


    for (int i = 1; i < n; i++) {
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    int max_difference = max_element - min_element;

    printf("Maximum difference between any two elements: %d\n", max_difference);

    return 0;
}
