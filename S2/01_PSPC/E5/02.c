#include <stdarg.h>
#include <stdio.h>

float average(int terms, ...) {
  va_list args_ptr;
  va_start(args_ptr, terms);

  int n = 0;
  float sum = 0;

  for (; n < terms; n++) {
    sum += va_arg(args_ptr, int);
  }

  va_end(args_ptr);
  return sum / n;
}

int main() {
  printf("%f\n", average(6, 1, 2, 3, 4, 5, 6));
  printf("%f\n", average(3, 10, 10, 10));
  printf("%f\n", average(4, 3, 5, 3, 5));
  return 0;
}
