#include <stdio.h>

void fill_with_input(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", arr + i);
    }
}

int recursive_search(int *arr, int low, int high, int search, int *count) {
    int mid = (low + high) / 2;
    if (high >= low) {
        (*count)++;
        if (arr[mid] == search) {
            return 1;
        } else if (search > arr[mid]) {
            return recursive_search(arr, mid + 1, high, search, count);
        } else {
            return recursive_search(arr, low, mid - 1, search, count);
        }
    }
    return 0;
}

int iterative_search(int *arr, int n, int search, int *count) {
    int low = 0, high = n - 1;

    while (low != high) {
        int mid = (low + high) / 2;
        (*count)++;

        if (arr[mid] == search) {
            return 1;
        } else if (search > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0;
}

int main() {
    int n, search;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers to begin the search with: ", n);
    fill_with_input(arr, n);

    printf("Integer to be searched for: ");
    scanf("%d", &search);

    int count = 0;
    int found = recursive_search(arr, 0, n - 1, search, &count);

    printf("using recursive search:\n");
    if (found) {
        printf("found the integer.");
    } else {
        printf("couldn't find the element.");
    }
    printf(" number of comparisons made: %d\n", count);

    count = 0;
    printf("using iterative search:\n");

    found = iterative_search(arr, n, search, &count);

    if (found) {
        printf("found the integer.");
    } else {
        printf("couldn't find the element.");
    }

    printf(" number of comparisons made: %d\n", count);

    return 0;
}
