#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int value;
	struct list* next;
} List;

void addlist(List** list, int value)
{
	List* newlist = malloc(sizeof(List));
	newlist->next = *list;
	newlist->value = value;
	*list = newlist;
}

int main(void) 
{
	List* list = malloc(sizeof(List));
	list->value = 10;
	list->next = NULL;

	addlist(&list, 50);	
	addlist(&list, 50);	
	addlist(&list, 50);	
	addlist(&list, 50);	

	for (List* i = list; i != NULL; i = i->next) {
		printf("%d\n", i->value);
	}

	return 0;
}
