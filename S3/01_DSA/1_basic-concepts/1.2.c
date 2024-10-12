#include <stdbool.h>
#include <stdio.h>
#include <strings.h>

typedef struct {
    int coefficient;
    int power;
} Term;

void swap_terms(Term *term1, Term *term2) {
    Term temp = *term1;
    *term1 = *term2;
    *term2 = temp;
}

void input_polynomial(Term *poly, int *terms) {
    for (int i = 0; i < *terms; i++) {
        printf("Enter the power of the term: ");
        scanf("%d", &poly[i].power);
        printf("Enter the coefficient of x^%d: ", poly[i].power);
        scanf("%d", &poly[i].coefficient);
    }
}

void print_polynomial(Term *poly, int terms) {
    int needs_plus = 0;

    for (int i = 0; i < terms; i++) {
        if (poly[i].coefficient == 0) {
            needs_plus = 0;
            continue;
        }
        if (needs_plus)
            printf(" + ");

        if (i != terms - 1)
            needs_plus = 1;

        printf("%d", poly[i].coefficient);

        if (poly[i].power != 0)
            printf("x");

        if (poly[i].power > 1)
            printf("^%d", poly[i].power);
    }
    printf("\n");
}

void add_polynomials(Term *result, int result_terms, Term *p1, int terms1,
                     Term *p2, int terms2) {

    for (int i = 0; i < result_terms; i++) {
        Term term = {0, i};
        if (i < terms1 + 1) {
            term.coefficient += p1[i].coefficient;
        }
        if (i < terms2 + 1) {
            term.coefficient += p2[i].coefficient;
        }
        result[i] = term;
    }
}

void multiply_polynomials(Term *result, int result_terms, Term *p1, int terms1,
                          Term *p2, int terms2) {
    int top = 0;
    for (int i = 0; i < terms1; i++) {
        for (int j = 0; j < terms2; j++) {
            int coefficient = p1[i].coefficient * p2[j].coefficient;
            int power = p1[i].power + p2[j].power;

            Term term = {coefficient, power};
            result[top++] = term;
        }
    }
}

// Checks whether the polynomial needs resolution.
bool needs_resolution(Term *poly, int terms) {
    for (int i = 0; i < terms; i++) {
        for (int j = i + 1; j < terms; j++) {
            if (poly[i].power == poly[j].power) {
                return true;
            }
        }
    }
    return false;
}

// Resolves a polynomial expression, into merging coefficients, and modifies
// the number of terms to the actual number of terms.
void resolve_expression(Term *poly, int *terms) {
    for (int i = 0; i < *terms; i++) {
        for (int j = i + 1; j < *terms; j++) {
            if (poly[i].power == poly[j].power) {
                poly[i].coefficient += poly[j].coefficient;
                swap_terms(&poly[j], &poly[--(*terms)]);
            }
        }
    }
}

// Sorts polynomial expression terms in descending order of power.
void sort_poly_terms(Term *poly, int terms) {
    for (int i = 0; i < terms; i++) {
        bool swapped = false;
        for (int j = 0; j < terms - i - 1; j++) {
            if (poly[j].power < poly[j + 1].power) {
                swap_terms(&poly[j], &poly[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

int main() {
    int terms1;
    printf("Enter the number of terms of the first polynomial: ");
    scanf("%d", &terms1);

    Term poly1[terms1];
    input_polynomial(poly1, &terms1);
    print_polynomial(poly1, terms1);

    int terms2;
    printf("Enter the number of terms of the second polynomial: ");
    scanf("%d", &terms2);

    Term poly2[terms2];
    input_polynomial(poly2, &terms2);
    print_polynomial(poly2, terms2);

    // ====== ADDITION =========
    // printf("Result of addition:\n");
    //
    // int add_result_degree = terms1 > terms2 ? terms1 : terms2;
    // struct PolyTerm add_result[add_result_degree];

    // add_polynomials(add_result, add_result_degree, poly1, terms1, poly2,
    //                 terms2);
    // print_polynomial(add_result, &add_result_degree);

    // ===== MULTIPLICATION =====
    printf("Result of multiplication:\n");

    int multiply_result_terms = terms1 * terms2;
    Term mul_result[multiply_result_terms];

    multiply_polynomials(mul_result, multiply_result_terms, poly1, terms1,
                         poly2, terms2);

    if (needs_resolution(mul_result, multiply_result_terms)) {
        printf("before resolution:\n");
        print_polynomial(mul_result, multiply_result_terms);

        printf("after resolution:\n");
        resolve_expression(mul_result, &multiply_result_terms);
        sort_poly_terms(mul_result, multiply_result_terms);
    } else {
        print_polynomial(mul_result, multiply_result_terms);
    }

    return 0;
}
