#include "DoublyLinkedLists.h"

List *createDoublyLinkedList(void)
{
	List *uList = malloc(sizeof(List));
	if (!uList)
	{
		printf("ERROR: Failed to allocate memory.\n");
	}

	uList->head = NULL;
	uList->tail = NULL;
	uList->size = 0;
	return uList;
}

/*
* Creates a new node. Returns NULL if malloc failed
*/

Node *createNode(Key k)
{
	Node *node = malloc(sizeof(Node));
	if (node)
	{
		node->key = k;
		node->prev = NULL;
		node->next = NULL;
	}
	return node;
}

/*
* Asks user for the key and returns it
*/
Key getKey(void)
{
	Key key;
	scanf("%d", &key);
	return key;
}

/*
* Inserts a node into the list after the node with the given key
*/

List *insertNode(List *uList)
{
	Node *temp = uList->head;
	Key k;
	printf("Enter the key of the node you wish to insert: ");
	k = getKey();
	if (temp == NULL)
	{
		return addToHead(uList, k);
	}
	printf("Now enter the key of the node you wish to insert after: ");
	Node *key = searchLinkedList(uList, getKey());
	if (key == NULL)
	{
		printf("The key you entered is not in the list.\n");
		return uList;
	}

	if (uList->tail == key) //If the desired node is the last node, call appendNode
	{
		return appendNode(uList, k);
	}

	Node *new_node = createNode(k);
	if (!new_node)
	{
		fprintf(stderr, "ERROR: Failed to insert node\n");
		return uList;
	}
	
	new_node->prev = key;
	new_node->next = key->next;
	key->next = new_node;
	uList->size++;

	return uList;
}

/*
* Appends node at the end of the linked list where uList is the pointer to existing list
* and k is the key to be included in the node
*/
List *appendNode(List *uList, Key k)
{
	Node *new_node = createNode(k);
	if (!new_node)
	{
		fprintf(stderr, "ERROR: Failed to insert node\n");
		return uList;
	}
	new_node->prev = uList->tail;
	uList->tail->next = new_node;
	uList->tail = new_node;
	uList->size++;

	return uList;
}

/*
* Inserts node at the beginning of the linked list where head is a pointer to the existing list,
* k is the key to be included in the node
*/

List* addToHead(List *uList, Key k)
{
	Node *new_node = createNode(k);
	if (!new_node)
	{
		fprintf(stderr, "ERROR: Failed to insert node\n");
		return uList;
	}
	new_node->next = uList->head;
	uList->head = new_node;
	if (uList->tail == NULL)
	{
		uList->tail = new_node;
	}
	if (uList->size > 1)
	{
		new_node->next->prev = new_node;
	}
	uList->size++;
	return uList;
}

/*
*	Removes the element at the head of the list. If the head pointer passed is NULL, returns NULL. If there is only one
*	element in the list, returns NULL. Else returns the new List pointer.
*/

List *removeHead(List *uList)
{
	Node *temp = uList->head;

	if (uList->head == NULL)
	{
		uList->size = 0;
		return NULL;
	}
	else if (uList->head->next == NULL)
	{
		freeLinkedList(uList->head);
		uList->size--;
		return NULL;
	}
	else
	{
		uList->head->next->prev = NULL;
		uList->head = uList->head->next;
		uList->size--;
		free(temp);
		temp = NULL;
	}
	return uList;
}

List* deleteNode(List *uList)
{
	Key k;
	Node *temp = uList->head;
	printf("Enter the key of the node you wish to remove: ");
	k = getKey();
	Node *key = searchLinkedList(uList, k);
	if (key == NULL)
		return uList;
	if (uList->head == key)
	{
		return removeHead(uList);
	}
	if (key->prev != NULL)
	{
		key->prev->next = key->next;
	}
	if (key->next != NULL)
	{
		key->next->prev = key->prev;
	}
	uList->size--;
	free(key);
	key = NULL;
	return uList;
}
/*
* Searches each element of uList for Key k. Returns address of element containing k, else returns NULL
*/

Node *searchLinkedList(List *uList, Key k)
{
	Node *temp = uList->head;
	while (temp != NULL)
	{
		if (temp->key == k)
			return temp;
		temp = temp->next;
	}
	printf("Element not in list.\n");
	return NULL;
}


/*
* Prints each element of the list and then the number of nodes in the list
*/
void printLinkedList(List *uList)
{
	Node *temp = uList->head;
	printf("\nList:\n");
	while (temp != NULL)
	{
		printf("%-4d", temp->key);
		temp = temp->next;
	}
	printf("\n");
	printf("Number of Nodes: %d\n\n", uList->size);
	return;
}

/*
*	Frees each element of the list
*/
void freeLinkedList(Node* head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		head = temp->next;
		free(temp);
		temp = head;
	}
	printf("Linked list freed\n");
}


/*
* Goes to the element given by index and compares the key in that node with value
* Returns 1 if key and value are the same, 0 if they are not, and -1 if the index
* does not exist or if the passed head pointer is NULL
*/
int checkItem(List *uList, int index, Key value)
{
	int counter = 0;
	Node *temp = uList->head;
	if (temp == NULL)
		return -1;
	while (temp != NULL)
	{
		if (counter + 1 == index)
		{
			if (temp->key == value)
				return 1;
			else
				return 0;
		}
		if (temp->next == NULL)
			return -1;
		temp = temp->next;
		counter++;
	}

	return 0;
}
