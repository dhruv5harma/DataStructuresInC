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

void delete(struct Array *arr,int index){
	int i;
	if(index>=0&&index<arr->length){
		for(i=index;i<arr->length;i++){
			arr->A[i]=arr->A[i+1];
		}
		arr->length--;
	}
}

int main() {
	struct Array arr = { { 10, 20, 15, 1, 7 }, 20, 5 };
	delete(&arr, 2);
	display(arr);
	return 0;
}

