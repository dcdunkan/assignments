#include <stdio.h>

int findMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (max < arr[i])
      max = arr[i];
  }
  return max;
}

int main() {
  int n;
  printf("Enter the limit: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Max: %d\n", findMax(arr, n));
  return 0;
}
