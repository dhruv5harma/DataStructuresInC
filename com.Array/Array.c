#include<stdio.h>
#include<stdlib.h>

struct Array {
	int *A;
	int length;
	int size;
};

int * createArray(int size){
	return (int*) malloc(size * sizeof(int));
}

int main() {
	int i;
	struct Array arr;
	arr.A = createArray(5);
	printf("Hello");
	for (i = 0; i < 5; i++) {
		arr.A[i] = 10 + i;
	}
	for (i = 0; i < 5; i++) {
		printf("\n%d", arr.A[i]);
	}
}

