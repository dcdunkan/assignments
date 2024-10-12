#include <stdio.h>

void print_upto(int n) {
  static int i = 1;
  if (i > n)
    return;
  printf("%d ", i++);
  print_upto(n);
}

int main() {
  int n;
  printf("Enter the limit: ");
  scanf("%d", &n);
  print_upto(n);
  printf("\n");
  return 0;
}
