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

void Display(struct Node *p) {
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
}

struct Node * LinearSearch(struct Node *p,int key){
	p=first;
	while(p){
		if(p->data==key){
			return p;
		}
		p=p->next;
	}
	return 0;
}

int min(struct Node *p){
	int minElement=INT_MAX;
	while(p){
		if(p->data<minElement){
			minElement=p->data;
		}
	}
	return minElement;
}

int main() {
	int A[]={1,2,3,4,5,6};
	Create(A,6);
	Display(first);
	struct Node *p=LinearSearch(first,7);
	printf("Min Element is %d %d",min(first),p->data);
	return 0;
}
