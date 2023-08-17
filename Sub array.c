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

    int start, end;
    printf("Enter the starting and ending indices of the subarray: ");
    scanf("%d %d", &start, &end);

    if (start < 0 || start >= n || end < start || end >= n) {
        printf("Invalid subarray indices.\n");
    } else {
        printf("Subarray: ");
        for (int i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
