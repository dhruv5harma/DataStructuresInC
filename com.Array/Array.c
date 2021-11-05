#include<stdio.h>
#include<stdlib.h>

struct Array {
	int A[20];
	int length;
	int size;
};

int* createArray(int size) {
	return (int*) malloc(size * sizeof(int));
}

void display(struct Array arr) {
	int i;
	printf("[");
	for (i = 0; i < arr.length; i++) {
		printf(" %d ", arr.A[i]);
	}
	printf("]");
}

int main() {
	struct Array arr = { { 10, 20, 15, 1, 7 },5 , 10 };
	display(arr);

}

