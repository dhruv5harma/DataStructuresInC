#include<stdio.h>
#include<stdlib.h>

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

int getConsonantCount(char A[]) {
	int i, count = 0;
	for (i = 0; A[i] != '\0'; i++) {
		if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z')) {
			if (!(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o'
					|| A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I'
					|| A[i] == 'O' || A[i] == 'U')) {
				count++;
			}
		}
	}
	return count;
}

int wordCount(char A[]) {
	int i, count = 0;
	for (i = 0; A[i] != '\0'; i++) {
		if (A[i] == ' ' && A[i - 1] != ' ') {
			count++;
		}
	}
	return count + 1;
}

int validateString(char A[]) {
	int i;
	for (i = 0; A[i] != '\0'; i++) {
		if (!((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z')
				|| (A[i] >= 48 && A[i] <= 57))) {
			return 0;
		}
	}
	return 1;
}

void revesingAString(char *A) {
	int i, j, size = getStringLength(A);
	char *temp;
	temp = (char*) malloc((size + 1) * sizeof(char));
	for (i = 0, j = size - 1; A[i] != '\0'; i++, j--) {
		temp[i] = A[j];
	}
	temp[i] = '\0';
	for (i = 0; temp[i] != '\0'; i++) {
		A[i] = temp[i];
	}
	free(temp);
}

void swapcharArray(char *A, int posA, int posB) {
	char temp;
	temp = A[posA];
	A[posA] = A[posB];
	A[posB] = temp;
}

void revesingAStringImporved(char *A) {
	int i, j = getStringLength(A) - 1;
	for (i = 0; i < j; i++, j--) {
		swapcharArray(A, i, j);
	}
}

int checkPallindrome(char *A) {
	int i, j = getStringLength(A) - 1;
	for (i = 0; i < j; i++, j--) {
		if (A[i] != A[j]) {
			return 0;
		}
	}
	return 1;
}

int* createHashTable(int size) {
	int i,*hashtable;
	hashtable = (int*) malloc(size * sizeof(int));
	for (i = 0; i < size; i++) {
		hashtable[i] = 0;
	}
	return hashtable;
}

int checkDuplicates(char A[]) {
	int i, *hashtable = createHashTable(26);
	for (i = 0; A[i] != '\0'; i++) {
		hashtable[A[i] - 97] += 1;
	}
	for (i = 0; i < 26; i++) {
		if (hashtable[i] > 1) {
			free(hashtable);
			return 0;
		}
	}
	free(hashtable);
	return 1;
}

int main() {
	char A[] = "mad";
	printf("'%s'  count is %d", A, checkDuplicates(A));
}
