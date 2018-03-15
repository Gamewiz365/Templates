#include <stdio.h>
#include <stdlib.h>

typedef int Key; //Change the type before Key to desired type (int in this application)

typedef struct Node
{
	Key key;
	struct Node *prev;
	struct Node *next;
}Node;

typedef struct List {
	Node* head, *tail;  //head is the first node of the list and tail is the last node of the list.
	int size;
}List;

List *createDoublyLinkedList(void);

Node *createNode(Key);

List *addToHead(List *, Key);

List *removeHead(List *);

void printLinkedList(List *);

void freeLinkedList(Node *);

List *insertNode(List*);

List *appendNode(List *, Key);

List *deleteNode(List*);

Key getKey(void);

Node *searchLinkedList(List *, Key k);

int checkItem(List*, int, Key);