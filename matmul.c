#include <stdio.h>
#include <limits.h> // Corrected header inclusion
#define MAX 10

int m[MAX][MAX], s[MAX][MAX];

void matrix_chain_order(int p[], int n) {
    int i, j, k, l, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (l = 2; l < n; l++) { // Corrected loop condition
        for (i = 1; i <= n - l; i++) { // Corrected loop indices
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) { // Corrected loop condition
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nCost Matrix:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++)
            printf("%d ", m[i][j]); // Added a space for better formatting
        printf("\n");
    }
    printf("\nParenthesization Matrix:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++)
            printf("%d ", s[i][j]); // Added a space for better formatting
        printf("\n");
    }
    printf("\nMinimal Cost = %d\n", m[1][n - 1]); // Changed indices here
    printf("\nOptimal Parenthesization = ");
    print_optimal_parens(1, n - 1); // Changed indices here
    printf("\n");
}

void print_optimal_parens(int i, int j) {
    if (i == j)
        printf("A%d", i); // Changed formatting here
    else {
        printf("(");
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j] + 1, j); // Changed indices here
        printf(")");
    }
}

int main() {
    int n, i;
    printf("Enter no of matrices:");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter dimensions:\n");
    for (i = 0; i < n + 1; i++) // Corrected loop condition
        scanf("%d", &p[i]);
    matrix_chain_order(p, n + 1);
    return 0;
}
