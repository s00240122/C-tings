#include <stdio.h>
#define MAXDATA 1024

typedef struct {
    double data[MAXDATA];
    int nrows;
    int ncols;
} Matrix;

int main() {
    void printmat(Matrix M);
    Matrix matrixmult(Matrix A, Matrix B);

    Matrix A = {
            {1.2, 2.3,
            3.4, 4.5,
            5.6, 6.7},
            3,
            2};
    Matrix B = { {5.5, 6.6, 7.7,
                  1.2, 2.1, 3.3},
                 2,
                 3};

    printmat(B);
    printf("\n");
    printmat(matrixmult(A, B));

    return 0;
}

void printmat(Matrix M) {
    for (int i = 0; i < M.nrows; i++) {
        printf("[ ");
        for (int j = 0; j < M.ncols; j++) {
            printf("%6.3f ", M.data[i * M.ncols + j]);
        }
        printf("]\n");
    }
}

Matrix matrixmult(Matrix A, Matrix B) {
    Matrix C;
    C.nrows = A.nrows;
    C.ncols = B.ncols;
    for (int i = 0; i < C.nrows * C.ncols; i++) {
        C.data[i] = 0.0;
    }

    if (A.ncols != B.nrows) {
        printf("Bruh you can't multiply those");
        return C;
    }

    for (int i = 0; i < C.nrows; i++) {
        for (int j = 0; j < C.ncols; j++) {
            double temp = 0.0;
            for (int k = 0; k < A.ncols; k++) {
                temp += A.data[i * A.ncols + k] * B.data[k * B.ncols + j];
            }
            C.data[i * C.ncols + j] = temp;
        }
    }

    return C;
}
