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

void setLowerTrianguarMatrix(struct Matrix *m, int i, int j, int element) {
	if (i >= j) {
		m->A[((i * (i - 1)) / 2) + j - 1] = element;
	}
}

int getLowerTrianguarMatrix(struct Matrix m, int i, int j) {
	if (i >= j) {
		return m.A[((i * (i - 1)) / 2) + j - 1];
	} else {
		return 0;
	}
}

void DisplayLowerTrianguarMatrix(struct Matrix m) {
	int i, j;
	for (i = 0; i < m.n; i++) {
		for (j = 0; j < m.n; j++) {
			printf("%d ", getLowerTrianguarMatrix(m, i + 1, j + 1));
		}
		printf("\n");
	}
}

int main() {

	struct Matrix m1;
	m1.n = 4;
	setLowerTrianguarMatrix(&m1, 1, 1, 1);
	setLowerTrianguarMatrix(&m1, 2, 1, 2);
	setLowerTrianguarMatrix(&m1, 2, 2, 3);
	setLowerTrianguarMatrix(&m1, 3, 1, 4);
	setLowerTrianguarMatrix(&m1, 3, 2, 5);
	setLowerTrianguarMatrix(&m1, 3, 3, 6);
	setLowerTrianguarMatrix(&m1, 4, 1, 7);
	setLowerTrianguarMatrix(&m1, 4, 2, 5);
	setLowerTrianguarMatrix(&m1, 4, 3, 6);
	setLowerTrianguarMatrix(&m1, 4, 4, 6);
	//setDiagonalMatrix(&m1, 4, 4, 40);
	DisplayLowerTrianguarMatrix(m1);

	return 0;
}
