#include<stdio.h>
#include<stdlib.h>

struct Array {
	int A[20];
	int size;
	int length;
};

int* createArray(int size) {
	return (int*) malloc(size * sizeof(int));
}

void display(struct Array arr) {
	int i;
	printf("Elements are- ");
	for (i = 0; i < arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
}

void append(struct Array *arr, int element) {
	if (arr->length < arr->size) {
		arr->A[arr->length++] = element;
	}
}

void insert(struct Array *arr, int element, int index) {
	int i;
	if (index >= 0 && index < arr->length) {
		for (i = arr->length; i > index; i--) {
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = element;
		arr->length++;
	}
}

void delete(struct Array *arr, int index) {
	int i;
	if (index >= 0 && index < arr->length) {
		for (i = index; i < arr->length; i++) {
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
	}
}

int linearSearch(struct Array arr, int element) {
	int i;
	for (i = 0; i < arr.length; i++) {
		if (arr.A[i] == element) {
			return i;
		}
	}
	return -1;
}

void swap(struct Array *arr, int posA, int posB) {
	int temp;
	if (posA >= 0 && posB >= 0 && posA < arr->length && posB < arr->length) {
		temp = arr->A[posA];
		arr->A[posA] = arr->A[posB];
		arr->A[posB] = temp;
	}
}

int linearSearchTransposition(struct Array *arr, int element) {
	int i;
	for (i = 0; i < arr->length; i++) {
		if (arr->A[i] == element) {
			if (i != 0) {
				swap(arr, i - 1, i);
				return i - 1;
			}
			return i;
		}
	}
	return -1;
}

int linearSearchBringToFront(struct Array *arr, int element) {
	int i;
	for (i = 0; i < arr->length; i++) {
		if (arr->A[i] == element) {
			if (i != 0) {
				swap(arr, 0, i);
			}
			return 0;
		}
	}
	return -1;
}

int main() {
	struct Array arr = { { 10, 20, 15, 1, 7 }, 20, 5 };
	printf("%d\n", linearSearchTransposition(&arr, 15));
	printf("%d\n", linearSearchBringToFront(&arr, 7));
	display(arr);
	return 0;
}

