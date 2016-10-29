#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int value;
	struct linked_list* next;
} List;

List* list_create(int value)
{
	List* list = malloc(sizeof(List));
  list->value = value;
  list->next = NULL;
  return list;
}

void list_push_value(List** list, int value)
{
	List* newlist = malloc(sizeof(List));
  newlist->value = value;
	newlist->next = *list;
	*list = newlist;
}

List* list_pop_list(List** list)
{
  List* poplist = *list;
  *list = (*list)->next;
  return poplist;
}

int list_pop_value(List** list)
{
  int pop_value = (*list)->value; 
  List* delete_list = *list;
  *list = (*list)->next;
  free(delete_list);
  return pop_value;
}

int main(void) 
{
	List* list = list_create(1);
	list_push_value(&list, 2);	
	list_push_value(&list, 3);	
	list_push_value(&list, 4);	
	list_push_value(&list, 5);
	for (List* i = list; i != NULL; i = i->next) {
		printf("%d ", i->value);
	}
  printf("\n");
  List* poplist = list_pop_list(&list);
  printf("%d \n",poplist->value);
  int pop_value = list_pop_value(&list);
  printf("%d \n",pop_value);
	for (List* i = list; i != NULL; i = i->next) {
		printf("%d ", i->value);
	}
  printf("\n");
	return 0;
}
