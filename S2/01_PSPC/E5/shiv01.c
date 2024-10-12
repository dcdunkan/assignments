#include <stdio.h>
int main() {
  int n;
  int num(int);
  printf("How many numbers do you want to print? ");
  scanf("%d", &n);
  num(n);
  return 0;
}

int num(int n) {
  if (n != 0) {
    num(n - 1);
  } else
    return 0;

  printf("%d", n);
}
