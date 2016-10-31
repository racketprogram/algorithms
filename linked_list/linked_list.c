#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
  char* key;
	int value;
	struct linked_list* next;
} List;

List* list_new(char* key, int value)
{
	List* list = malloc(sizeof(List));
  list->key = key;
  list->value = value;
  list->next = NULL;
  return list;
}

void list_cons(char* key, int value, List** list)
{
	List* newlist = malloc(sizeof(List));
  newlist->key = key;
  newlist->value = value;
	newlist->next = *list;
	*list = newlist;
}

void list_delete(char* key, List** list)
{
	if (*((*list)->key) == *key) {
    List* tmp = *list;
    *list = (*list)->next;
    free(tmp);
  } else if ((*list)->next == NULL) {
    return;
  } else {
    list_delete(key, &((*list)->next));
  }
}

int list_find(char* key, List* list)
{
	if (*(list->key) == *key) {
    return list->value;
  } else if (list->next == NULL) {
    return 0;
  } else {
    list_find(key, list->next);
  }
}

void list_print(List* list) 
{
	for (List* i = list; i != NULL; i = i->next) {
		printf("%s %d ", i->key, i->value);
	}
  printf("\n");
}

int main(void) 
{
	List* list = list_new("year", 2016);
	list_cons("month", 10, &list);	
	list_cons("day", 31, &list);	
  list_print(list);
  list_delete("month", &list);
  list_print(list);
  printf("what the year is ? %d \n", list_find("year", list));
	return 0;
}
