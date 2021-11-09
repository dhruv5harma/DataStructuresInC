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
	m->n = i;
}

void main() {

}
