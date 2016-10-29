#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int value;
	struct list* next;
} List;


List* addlist(List* list, int value)
{
	if (list == NULL) {
		list = malloc(sizeof(List));
		list->value = value;
		list->next = NULL;
	} else {
		List* nextlist = malloc(sizeof(List));
		list->next = nextlist;
		nextlist->value = value;
		nextlist->next = NULL;
	}
	return list;
}

int main(void) 
{
	List* list1 = malloc(sizeof(List));
	list1->value = 1;
	list1->next = NULL;

	List* list2 = addlist(list1, 99);
	
	printf("%d\n", list2->next->value);
	
	return 0;
}
