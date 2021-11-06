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

int getvowelCount(char A[]) {
	int i, count = 0;
	for (i = 0; A[i] != '\0'; i++) {
		if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o'
				|| A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I'
				|| A[i] == 'O' || A[i] == 'U') {
			count++;
		}
	}
	return count;
}

int main() {
	char A[] = "Test String";
	toggleCase(A);
	printf("'%s' Vowel count is %d", A, getvowelCount(A));
}
