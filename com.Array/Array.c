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

void reverseArray(struct Array *arr) {
	int i, j;
	struct Array arr2;
	arr2.length = arr->length;
	for (i = 0, j = arr->length - 1; i < arr2.length; i++, j--) {
		arr2.A[i] = arr->A[j];
	}
	for (i = 0; i < arr2.length; i++) {
		arr->A[i] = arr2.A[i];
	}
}

void reverseArrayImproved(struct Array *arr) {
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--) {
		swap(arr, i, j);
	}
}

void leftShiftArray(struct Array *arr) {
	int i;
	for (i = 1; i < arr->length; i++) {
		arr->A[i - 1] = arr->A[i];
	}
	arr->length--;
}

void rightShiftArray(struct Array *arr) {
	int i;
	for (i = arr->length - 1; i > 0; i--) {
		arr->A[i] = arr->A[i - 1];
	}
	arr->A[0] = 0;
}

int checkSortedArray(struct Array arr) {
	int i;
	for (i = 0; i < arr.length - 2; i++) {
		if (arr.A[i] > arr.A[i + 1]) {
			return 0;
		}
	}
	return 1;
}

struct Array mergeSortedArray(struct Array arr1, struct Array arr2) {
	struct Array arr3;
	int i = 0, j = 0, k = 0;
	while (i < arr1.length && j < arr2.length) {
		if (arr1.A[i] < arr2.A[j]) {
			arr3.A[k++] = arr1.A[i++];
		} else {
			arr3.A[k++] = arr2.A[j++];
		}
	}
	for (; i < arr1.length; i++) {
		arr3.A[k++] = arr1.A[i];
	}
	for (; j < arr2.length; j++) {
		arr3.A[k++] = arr1.A[j];
	}
	arr3.length = k;
	return arr3;
}

struct Array intersectionArray(struct Array arr1, struct Array arr2) {
	struct Array arr3;
	int i, j, k = 0;
	for (i = 0; i < arr1.length; i++) {
		for (j = 0; j < arr2.length; j++) {
			if (arr1.A[i] == arr2.A[j]) {
				arr3.A[k++] = arr1.A[i];
			}
		}
	}
	arr3.length = k;
	return arr3;
}

struct Array unionArray(struct Array arr1, struct Array arr2) {
	struct Array arr3;
	int i, j, k = 0;
	for (i = 0; i < arr1.length; i++) {
		arr3.A[k++] = arr1.A[i];
	}
	for (i = 0; i < arr2.length; i++) {
		for (j = 0; j < k; j++) {
			if (arr2.A[i] == arr3.A[j]) {
				break;
			}
		}
		if (j == k) {
			arr3.A[k++] = arr2.A[i];
		}
	}
	arr3.length = k;
	return arr3;
}

struct Array unionOfSortedArrays(struct Array arr1, struct Array arr2) {
	struct Array arr3;
	int i=0, j=0, k = 0;
	while (i < arr1.length && j < arr2.length) {
		if (arr1.A[i] < arr2.A[j]) {
			arr3.A[k++] = arr1.A[i++];
		} else if (arr1.A[i] > arr2.A[j]) {
			arr3.A[k++] = arr2.A[j++];
		} else {
			arr3.A[k++] = arr1.A[i++];
			j++;
		}
	}
	while (i < arr1.length) {
		arr3.A[k++] = arr1.A[i++];
	}
	while (i < arr2.length) {
		arr3.A[k++] = arr1.A[j++];
	}
	arr3.length = k;
	return arr3;
}

struct Array differeceOfArray(struct Array arr1, struct Array arr2){
	struct Array arr3;
	int i,j;
	arr3.length=0;
	for(i=0;i<arr1.length;i++){
		for(j=0;j<arr2.length;j++){
			if(arr1.A[i]==arr2.A[j]){
				break;
			}
		}
		if(j==arr2.length){
			arr3.A[arr3.length++]=arr1.A[i];
		}
	}
	return arr3;
}

int main() {
	struct Array arr1 = { { 10, 20, 30, 40, 50, 57 }, 20, 6 };
	struct Array arr2 = { { 10, 12, 31, 33, 40, 50 }, 20, 6 };
	display(differeceOfArray(arr1, arr2));
	return 0;
}

