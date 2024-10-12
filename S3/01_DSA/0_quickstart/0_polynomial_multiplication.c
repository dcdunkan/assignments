#include <stdio.h>

void input_polynomial(int *poly, int degree) {
  for (int i = 0; i < degree + 1; i++) {
    printf("Enter the coeffiecient of x^%d: ", degree - i);
    scanf("%d", poly + degree - i);
  }
}

void print_polynomial(int *poly, int degree) {
  for (int i = 0; i < degree + 1; i++) {
    int coeffiecient = poly[degree - i];
    if (coeffiecient == 0)
      continue;

    int power = degree - i;
    if (power != degree)
      printf(" + ");

    printf("%d", coeffiecient);

    if (power != 0)
      printf("x");

    if (power > 1)
      printf("^%d", power);
  }
  printf("\n");
}

void fill_array(int *arr, int length, int with) {
  for (int i = 0; i < length; i++) {
    arr[i] = with;
  }
}

int main() {
  int degree1;
  printf("Enter degree of the first polynomial: ");
  scanf("%d", &degree1);

  int poly1[degree1 + 1];
  input_polynomial(poly1, degree1);
  printf("First polynomial: ");
  print_polynomial(poly1, degree1);

  int degree2;
  printf("Enter degree of the first polynomial: ");
  scanf("%d", &degree2);

  int poly2[degree1 + 1];
  input_polynomial(poly2, degree2);
  printf("Second polynomial: ");
  print_polynomial(poly2, degree2);

  int result_length = degree1 + degree2 + 1;
  int result[result_length];
  fill_array(result, result_length, 0);

  for (int i = 0; i < degree1 + 1; i++) {
    for (int j = 0; j < degree2 + 1; j++) {
      result[i + j] += poly1[i] * poly2[j];
    }
  }

  printf("Resultant polynomial (after multiplication): ");
  print_polynomial(result, result_length - 1);

  return 0;
}
