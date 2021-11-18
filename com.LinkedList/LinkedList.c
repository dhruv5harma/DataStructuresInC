#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *first = NULL;

void Create(int A[], int size) {
	int i;
	struct Node *temp, *last;
	first = (struct Node*) malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < size; i++) {
		temp = (struct Node*) malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void Display(struct Node *p) {
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

struct Node* LinearSearch(struct Node *p, int key) {
	p = first;
	while (p) {
		if (p->data == key) {
			return p;
		}
		p = p->next;
	}
	return 0;
}

int min(struct Node *p) {
	int minElement = INT_MAX;
	while (p) {
		if (p->data < minElement) {
			minElement = p->data;
		}
		p = p->next;
	}
	return minElement;
}

int max(struct Node *p) {
	int maxElement = INT_MIN;
	while (p) {
		if (p->data > maxElement) {
			maxElement = p->data;
		}
		p = p->next;
	}
	return maxElement;
}

void DisplayRecursive(struct Node *p) {
	if (p) {
		printf("%d ", p->data);
		DisplayRecursive(p->next);
	}
}

int main() {
	int A[] = { 8, 2, 3, 4, 5, 6 };
	Create(A, 6);
	//Display(first);
	//struct Node *p=LinearSearch(first,6);
	//printf("\n%d",p->data);
	/*printf("\nMin Element is %d",min(first));
	 printf("\nMax Element is %d",max(first));*/
	DisplayRecursive(first);
	return 0;
}
