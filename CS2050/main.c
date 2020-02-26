#include "DoublyLinkedLists.h"

int main(void)
{
	int i;
	List *uList = createDoublyLinkedList();
	for (i = 1; i < 4; i++)
	{
		insertNode(uList);
		printLinkedList(uList);
	}
	for (i = 0; i < 2; i++)
	{
		deleteNode(uList);
		printLinkedList(uList);
	}

	freeLinkedList(uList->head);

	return 0;
}
