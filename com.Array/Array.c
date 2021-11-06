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

int binarySearch(struct Array arr, int element) {
	int l = 0;
	int h = arr.length - 1;
	int mid;
	while (l <= h) {
		mid = (l + h) / 2;
		if (arr.A[mid] == element) {
			return mid;
		} else if (arr.A[mid] < element) {
			l = mid + 1;
		} else {
			h = mid - 1;
		}
	}
	return -1;
}

int recursiveBinarySearch(struct Array arr, int l, int h, int element) {
	int mid = (l + h) / 2;
	if (l > h) {
		return -1;
	} else if (arr.A[mid] == element) {
		return mid;
	} else if (arr.A[mid] < element) {
		return recursiveBinarySearch(arr, mid + 1, h, element);
	} else {
		return recursiveBinarySearch(arr, l, mid - 1, element);
	}
}

int getKeyAtIndex(struct Array arr, int index) {
	if (index > 0 && index < arr.length) {
		return arr.A[index];
	}
	return 0;
}

int setKeyAtIndex(struct Array *arr, int index, int key) {
	if (index > 0 && index < arr->length) {
		arr->A[index] = key;
		return 1;
	}
	return 0;
}

int getAverage(struct Array arr) {
	int i, Average = 0;
	for (i = 0; i < arr.length; i++) {
		Average += arr.A[i];
	}
	return Average / i;
}

int getMax(struct Array arr) {
	int i, max = arr.A[0];
	for (i = 1; i < arr.length; i++) {
		if (arr.A[i] > max) {
			max = arr.A[i];
		}
	}
	return max;
}

int getMin(struct Array arr) {
	int i, min = arr.A[0];
	for (i = 1; i < arr.length; i++) {
		if (arr.A[i] < min) {
			min = arr.A[i];
		}
	}
	return min;
}

int main() {
	struct Array arr = { { 1000, 120, 30, 40, 50 }, 20, 5 };
	printf("%d\n", getMin(arr));
	display(arr);
	return 0;
}

