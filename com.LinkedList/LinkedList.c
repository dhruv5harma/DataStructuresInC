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

void DisplayReverseRecursive(struct Node *p) {
	if (p) {
		DisplayRecursive(p->next);
		printf("%d ", p->data);
	}
}

int ElementsCount(struct Node *p) {
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

int ElementsSum(struct Node *p) {
	int sum = 0;
	while (p) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

void ImprovedLinearsearch(struct Node *p, int key) {
	struct Node *q = NULL;
	while (p) {
		if (p->data == key) {
			q->next = p->next;
			p->next = first;
			first = p;
		}
		q = p;
		p = p->next;
	}
}

void InsertElement(struct Node *p, int position, int data) {
	struct Node *q = NULL;
	struct Node *node;
	int count = 1;
	node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	if (position == 1) {
		node->next = first;
		first = node;
	} else {
		while (position - count > 0) {
			q = p;
			p = p->next;
			count++;
		}
		q->next = node;
		node->next = p;
	}
}

//This method won't delete the tail node
void DeleteNode(struct Node *p) {
	if (p == first) {
		first = p->next;
	} else {
		p->data = p->next->data;
		p->next = p->next->next;
	}
}

void InsertInSortedLinkedList(struct Node *p, int data) {
	struct Node *temp;
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	if (data < p->data) {
		temp->next = p;
		first = temp;
	} else {
		while (p->next != NULL) {
			if (p->next->data > data) {
				temp->next = p->next;
				p->next = temp;
				break;
			}
			p = p->next;
		}
	}
}

void SortedInserted(struct Node *p, int x) {
	struct Node *t, *q = NULL;
	t = (struct Node*) malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	if (first == NULL) {
		first = t;
	} else {
		while (p && p->data < x) {
			q = p;
			p = p->next;
		}
		if (p == first) {
			t->next = p;
			first = t;
		} else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int checkSortedLinkedList(struct Node *p) {
	int temp = INT_MIN;
	while (p) {
		if (temp > p->data) {
			return -1;
		}
		temp = p->data;
		p = p->next;
	}
	return 1;
}

void RemoveDublicateFromSortedLinkedList() {
	struct Node *p = first, *q = first->next;
	while (q) {
		if (p->data != q->data) {
			p = q;
			q = q->next;
		} else {
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

void ReverseingLinkedList(){
	struct Node *p=first,*q=first;
	while(first){
		first=first->next;
		p=first->next;


	}
}

int main() {
	int A[] = { 1, 1, 3, 3, 3, 7 };
	Create(A, 6);
	Display(first);
	//struct Node *p=LinearSearch(first,6);
	//printf("\n%d",p->data);
	//printf("\nMin Element is %d",min(first));
	// printf("\nMax Element is %d",max(first));
	//DisplayReverseRecursive(first);
	//printf("Count of Elements in Linked List is %d" , ElementsCount(first));
	//printf("\nSum of Elements in Linked List is %d" , ElementsSum(first));
	printf("\n");
	//ImprovedLinearsearch(first,5);
	//DeleteNode(first->next->next);
	//SortedInserted(first, 8);
	//printf("Check Sorted Linked List %d", checkSortedLinkedList(first));
	RemoveDublicateFromSortedLinkedList();
	RemoveDublicateFromSortedLinkedList();
	Display(first);
	return 0;
}
