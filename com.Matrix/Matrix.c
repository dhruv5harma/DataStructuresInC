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

void setLowerTrianguarColumnMajorMatrix(struct Matrix *m, int i, int j,
		int element) {
	if (i >= j) {
		m->A[j * (1 - j * (j - 1) / 2) + (i - j)] = element;
	}
}

int getLowerTrianguarColumnMajorMatrix(struct Matrix m, int i, int j) {
	if (i >= j) {
		return m.A[j * (1 - j * (j - 1) / 2) + (i - j)];
	} else {
		return 0;
	}
}

void DisplayLowerTrianguarColumnMajorMatrix(struct Matrix m) {
	int i, j;
	for (i = 0; i < m.n; i++) {
		for (j = 0; j < m.n; j++) {
			printf("%d ", getLowerTrianguarColumnMajorMatrix(m, i + 1, j + 1));
		}
		printf("\n");
	}
}

void setUpperTrianguarMatrix(struct Matrix *m, int i, int j, int element) {
	if (i <= j) {
		m->A[((j * (j - 1)) / 2) + i - 1] = element;
	}
}

int getUpperTrianguarMatrix(struct Matrix m, int i, int j) {
	if (i <= j) {
		return m.A[((j * (j - 1)) / 2) + i - 1];
	} else {
		return 0;
	}
}

void DisplayUpperTrianguarMatrix(struct Matrix m) {
	int i, j;
	for (i = 0; i < m.n; i++) {
		for (j = 0; j < m.n; j++) {
			printf("%d ", getUpperTrianguarMatrix(m, i + 1, j + 1));
		}
		printf("\n");
	}
}

int main() {

	struct Matrix m1;
	m1.n = 4;
	/*setUpperTrianguarMatrix(&m1, 1, 1, 1);
	 setUpperTrianguarMatrix(&m1, 1, 2, 2);
	 setUpperTrianguarMatrix(&m1, 1, 3, 3);
	 setUpperTrianguarMatrix(&m1, 1, 4, 4);
	 setUpperTrianguarMatrix(&m1, 2, 2, 5);
	 setUpperTrianguarMatrix(&m1, 2, 3, 6);
	 setUpperTrianguarMatrix(&m1, 2, 4, 7);
	 setUpperTrianguarMatrix(&m1, 3, 3, 5);
	 setUpperTrianguarMatrix(&m1, 3, 4, 6);
	 setUpperTrianguarMatrix(&m1, 4, 4, 6);
	 //setDiagonalMatrix(&m1, 4, 4, 40);
	 DisplayUpperTrianguarMatrix(m1);*/

	setLowerTrianguarColumnMajorMatrix(&m1, 1, 1, 1);
	setLowerTrianguarColumnMajorMatrix(&m1, 2, 1, 2);
	setLowerTrianguarColumnMajorMatrix(&m1, 2, 2, 3);
	setLowerTrianguarColumnMajorMatrix(&m1, 3, 1, 4);
	setLowerTrianguarColumnMajorMatrix(&m1, 3, 2, 5);
	setLowerTrianguarColumnMajorMatrix(&m1, 3, 3, 6);
	setLowerTrianguarColumnMajorMatrix(&m1, 4, 1, 7);
	setLowerTrianguarColumnMajorMatrix(&m1, 4, 2, 8);
	setLowerTrianguarColumnMajorMatrix(&m1, 4, 3, 9);
	setLowerTrianguarColumnMajorMatrix(&m1, 4, 4, 10);
	//setDiagonalMatrix(&m1, 4, 4, 40);
	DisplayLowerTrianguarColumnMajorMatrix(m1);

	return 0;
}
