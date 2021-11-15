#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *first=NULL;

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

void display(struct Node *p) {
	p=first;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
}

int main() {
	int A[6];
	A={1,2,3,4,5,6);
	Create(A,6);
	display(first);
	return 0;
}
