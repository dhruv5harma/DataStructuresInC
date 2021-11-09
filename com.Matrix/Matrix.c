#include<stdio.h>
#include<stdlib.h>

struct Matrix {
	int A[20];
	int n;
};

void setDiagonalMatrix(struct Matrix *m, int i, int j, int element) {
	if (i == j) {
		m->A[i - 1] = element;
	}
}

int getDiagonalMatrix(struct Matrix m, int i, int j) {
	if (i == j) {
		return m.A[i - 1];
	} else {
		return 0;
	}
}

void DisplayDiagonalMatrix(struct Matrix m) {
	int i, j;
	for (i = 0; i < m.n; i++) {
		for (j = 0; j < m.n; j++) {
			printf("%d ", getDiagonalMatrix(m, i + 1, j + 1));
		}
		printf("\n");
	}
}

int main() {


}
