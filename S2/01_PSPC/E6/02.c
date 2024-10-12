#include <stdio.h>

struct Complex {
  int real;
  int imaginary;
};

struct Complex complex_add(struct Complex a, struct Complex b) {
  struct Complex complex;
  complex.real = a.real + b.real;
  complex.imaginary = a.imaginary + b.imaginary;
  return complex;
}

struct Complex complex_subtract(struct Complex a, struct Complex b) {
  struct Complex complex;
  complex.real = a.real - b.real;
  complex.imaginary = a.imaginary - b.imaginary;
  return complex;
}

struct Complex complex_multiply(struct Complex a, struct Complex b) {
  struct Complex complex;
  complex.real = (a.real * b.real) - (a.imaginary * b.imaginary);
  complex.imaginary = (a.real * b.imaginary) + (a.imaginary * a.real);
  return complex;
}

struct Complex complex_divide(struct Complex a, struct Complex b) {
  struct Complex complex;
  int denominator = (b.real * b.real) + (b.imaginary * b.imaginary);
  complex.real =
      ((a.real * b.real) + (a.imaginary * b.imaginary)) / denominator;
  complex.imaginary =
      ((a.imaginary * a.real) - (a.real * b.imaginary)) / denominator;
  return complex;
}

void create_complex(struct Complex *complex) {
  printf("Enter real part: ");
  scanf("%d", &complex->real);
  printf("Enter imaginary part: ");
  scanf("%d", &complex->imaginary);
}

void display_complex(struct Complex *complex) {
  printf("%d + %di", complex->real, complex->imaginary);
}

int main() {
  struct Complex x, y;
  printf("Enter first complex number:\n");
  create_complex(&x);
  printf("Enter second complex number:\n");
  create_complex(&y);
  char choice;
choose:
  printf("Choose operation (+,-,*,/): ");
  scanf(" %c", &choice);

  struct Complex result;

  switch (choice) {
  case '+':
    result = complex_add(x, y);
    break;
  case '-':
    result = complex_subtract(x, y);
    break;
  case '*':
    result = complex_multiply(x, y);
    break;
  case '/':
    result = complex_divide(x, y);
    break;
  case 'q':
    return 0;
  default:
    printf("invalid operation. use q to quit");
    goto choose;
  }

  display_complex(&x);
  printf(" %c ", choice);
  display_complex(&y);
  printf(" = ");
  display_complex(&result);
  printf("\n");
  return 0;
}
