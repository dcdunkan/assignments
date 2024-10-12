#include <stdio.h>

struct PolyTerm {
    int coefficient;
    int power;
};

void input_polynomial(struct PolyTerm *poly, int *degree) {
    for (int i = 0; i < *degree + 1; i++) {
        int coefficient;
        printf("Enter the coefficient of x^%d: ", *degree - i);
        scanf("%d", &coefficient);
        struct PolyTerm term = {coefficient, *degree - i};
        poly[*degree - i] = term;
    }
}

void print_polynomial(struct PolyTerm *poly, int *degree) {
    for (int i = 0; i < *degree + 1; i++) {
        if (poly[*degree - i].coefficient == 0)
            continue;
        printf("+ %dx^%d", poly[*degree - i].coefficient,
               poly[*degree - i].power);
    }
    printf("\n");
}

void add_polynomials(struct PolyTerm *result, int result_degree,
                     struct PolyTerm *p1, int d1, struct PolyTerm *p2, int d2) {
    for (int i = 0; i < result_degree + 1; i++) {
        struct PolyTerm term = {0, i};
        if (i < d1 + 1) {
            term.coefficient += p1[i].coefficient;
        }
        if (i < d2 + 1) {
            term.coefficient += p2[i].coefficient;
        }
        result[i] = term;
    }
}

void multiply_polynomials(struct PolyTerm *result, int result_degree,
                          struct PolyTerm *p1, int d1, struct PolyTerm *p2,
                          int d2) {
    for (int i = 0; i < result_degree + 1; i++) {
        struct PolyTerm term = {0, i};
        result[i] = term;
    }

    for (int i = 0; i < d1 + 1; i++) {
        for (int j = 0; j < d2 + 1; j++) {
            result[i + j].coefficient += p1[i].coefficient * p2[j].coefficient;
        }
    }
}

int main() {
    int degree1;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);

    struct PolyTerm poly1[degree1 + 1];
    input_polynomial(poly1, &degree1);
    print_polynomial(poly1, &degree1);

    int degree2;
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);

    struct PolyTerm poly2[degree2 + 1];
    input_polynomial(poly2, &degree2);
    print_polynomial(poly2, &degree2);

    // ADDITION
    printf("Result of the addition:\n");

    int add_result_degree = degree1 > degree2 ? degree1 : degree2;
    struct PolyTerm add_result[add_result_degree + 1];

    add_polynomials(add_result, add_result_degree, poly1, degree1, poly2,
                    degree2);
    print_polynomial(add_result, &add_result_degree);

    // MULTIPLICATION
    printf("Result of the multiplication:\n");

    int mul_result_degree = degree1 + degree2;
    struct PolyTerm mul_result[mul_result_degree + 1];

    multiply_polynomials(mul_result, mul_result_degree, poly1, degree1, poly2,
                         degree2);
    print_polynomial(mul_result, &mul_result_degree);

    return 0;
}
