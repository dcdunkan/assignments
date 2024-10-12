#include <stdio.h>


void fill_with_input(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		scanf("%d", arr + i);
	}
}

int find_index(int* arr, int length, int search_element) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == search_element) return i;
	}
	return -1;
}

int main() {
	int n, search;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
	int arr[n];
	printf("Enter %d integers to begin the search with: ", n);
	fill_with_input(arr, n);
	
	printf("Enter the number to search for in the array: ");
	scanf("%d", &search);
	
	int index = find_index(arr, n, search);
	if (index == -1) {
		printf("Couldn't find the element in array.\n");
	} else {
		printf("Found the search element at index %d.\n", index);
	}
	
	return 0;
}
