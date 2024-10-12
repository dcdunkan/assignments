#include <stdio.h>

void fill_with_input(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", arr + i);
    }
}

void bubble_it(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        int swapped = 0;
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            return;
    }
}

void print_array(int *arr, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i != length - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    fill_with_input(arr, n);
    print_array(arr, n);

    printf("Bubbling...\n");
    bubble_it(arr, n);

    print_array(arr, n);

    return 0;
}
