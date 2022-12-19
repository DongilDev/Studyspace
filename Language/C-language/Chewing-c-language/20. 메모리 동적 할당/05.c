#include <stdio.h>
#include <stdlib.h>

struct node* createnode(int data);
struct node* insertnode(int data, struct node* current);
void destroynode(struct node* destroy);
void printnode(struct node* head);

struct node {
	int data;
	struct node* nextnode;
	struct node* prevnode;
};

int main() {
	struct node* node1 = createnode(100);
	struct node* node2 = insertnode(200, node1);
	struct node* node3 = insertnode(300, node2);
	struct node* node4 = insertnode(400, node3);
	
	destroynode(node3);
	printnode(node1);

	return 0;
}

struct node* createnode(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	newnode->data = data;
	newnode->nextnode = NULL;
	newnode->prevnode = NULL;

	return newnode;
}

struct node* insertnode(int data, struct node* current) {
	struct node* after = current->nextnode;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->nextnode = after;
	newnode->prevnode = current;

	current->nextnode = newnode;

	return newnode;
}

void destroynode(struct node* destroy) {
	struct node* before = destroy->prevnode;
	before->nextnode = destroy->nextnode;
	free(destroy);
}

void printnode(struct node* head) {
	while (head) {
		printf("node 데이터 값 : %d \n", head->data);
		head = head->nextnode;
	}
}