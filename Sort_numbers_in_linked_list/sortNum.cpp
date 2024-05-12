#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void searchToInsert(node_t *hp, LType item) {
	if (hp->data > item && hp->data < item) {
		hp = addBeginning(hp, item);
	}
	else {
		node_t* tp;
		tp = hp;
		while (tp->next != NULL && tp->next->data < item) {
			tp = tp->next;
		}
		addAfter(tp, item);
	}
}

node_t *createList(FILE *inp) {
	node_t *headp = NULL;
	LType item;

	fscanf(inp, "%d", &item);
	headp = addBeginning(headp, item);

	while (fscanf(inp, "%d", &item) != EOF) {
		searchToInsert(headp, item);
	}
	headp = deleteFirst(headp, &item);

	searchToInsert(headp, item);
	
	return (headp);
}

void displayRec(node_t *tp) {
	if (tp != NULL) {
		printf("%d -> ", tp->data);
		displayRec(tp->next);
	}
	else
		printf("NULL\n");
}

int main(void)
{
	FILE *inp;
	inp = fopen("numList.txt", "r");
	if (inp == NULL)
		printf("Error");
	else
	{
		node_t *headp;
		headp = createList(inp);
		fclose(inp);

		printf("\nList is: ");
		displayRec(headp);
	}
	return 0;
}