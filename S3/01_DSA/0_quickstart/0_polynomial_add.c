#include <stdio.h>

int get_integer() {
	int integer;
	scanf("%d", &integer);
	return integer;
}

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

int main() {	
	printf("Enter the degree of the first polynomial: ");
	int d1 = get_integer();
	
	int p1[d1 + 1];
	printf("Enter the coeffiecients of first polynomial:\n");
	input_polynomial(p1, d1);
	print_polynomial(p1, d1);
	
	printf("Enter the degree of the second polynomial: ");
	int d2 = get_integer();
	
	int p2[d2 + 1];
	printf("Enter the coeffiecients of second polynomial:\n");
	input_polynomial(p2, d2);
	print_polynomial(p2, d2);
	
	int result_degree = d1 > d2 ? d1 : d2;
	int result[result_degree + 1];
	
	for (int i = 0; i < result_degree + 1; i++) {
		result[i] = 0;
		if (i < d1 + 1) {
			result[i] += p1[i];
		}
		if (i < d2 + 1) {
			result[i] += p2[i];
		}
	}
	
	print_polynomial(result, result_degree);
	return 0;
}
