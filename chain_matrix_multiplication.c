#include <stdio.h>
#include <limits.h>
#define INFY 999999999

long int m[20][20];
int s[20][20];
int p[20];

void print_optimal(int i, int j) {
    if (i == j) {
        printf(" A%d ", i);
    } else {
        printf("( ");
        print_optimal(i, s[i][j]);
        print_optimal(s[i][j] + 1, j);
        printf(" )");
    }
}

void MatrixChainMultiplication(int n) {
    long int q;
    int k, i, j;
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++) { // l is the chain length
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INFY;
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main() {
    int k, n, i, j;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("\nEnter the dimensions: \n");
    for (k = 0; k <= n; k++) {
        printf("P%d: ", k);
        scanf("%d", &p[k]);
    }

    MatrixChainMultiplication(n);

    printf("\n************ Cost Matrix M *************\n");
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            printf("m[%d][%d]: %ld\n", i, j, m[i][j]);
        }
    }
    printf("\n***************************************\n");

    printf("\n************ Multiplication Sequence *****\n");
    print_optimal(1, n);
    printf("\n***************************************\n");

    printf("\nMinimum number of multiplications is : %ld\n", m[1][n]);
    return 0;
}
