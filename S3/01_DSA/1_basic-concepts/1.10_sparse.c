#include <stdio.h>

int main() {
    printf("Enter your sparse matrix (in tuple form):\n");
    int rows, cols, non_zero_elements;
    scanf("%d %d", &rows, &cols);

    scanf("%d", &non_zero_elements);

    int sparse[non_zero_elements + 1][3];

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = non_zero_elements;

    for (int i = 1; i < non_zero_elements + 1; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }

    printf("The sparse matrix:\n");
    for (int i = 0; i < non_zero_elements + 1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }

    int transpose[non_zero_elements + 1][3];

    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    int m = sparse[0][1], n = sparse[0][2];
    int k = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (sparse[j][1] == i) {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }

    printf("Transpose of the sparse matrix:\n");
    for (int i = 0; i < non_zero_elements + 1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
