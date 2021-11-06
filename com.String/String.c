#include<stdio.h>

int getStringLength(char A[]) {
	int i;
	for (i = 0; A[i] != '\0'; i++) {
	}
	return i;
}

void toUpperCase(char *A) {
	int i;
	for (i = 0; A[i] != '\0'; i++) {
		if (A[i] > 'a' && A[i] < 'z') {
			A[i] = A[i] - 32;
		}
	}
}

void toLowerCase(char *A) {
	int i;
	for (i = 0; A[i] != '\0'; i++) {
		if (A[i] > 'A' && A[i] < 'Z') {
			A[i] = A[i] + 32;
		}
	}
}

void toggleCase(char *A) {
	int i;
	for (i = 0; A[i] != '\0'; i++) {
		if (A[i] >= 'a' && A[i] <= 'z') {
			A[i] = A[i] - 32;
		} else if (A[i] >= 'A' && A[i] <= 'Z') {
			A[i] = A[i] + 32;
		}
	}
}

int main() {
	char A[] = "Test String AaZz";
	toggleCase(A);
	printf("'%s' Length is %d", A, getStringLength(A));
}
