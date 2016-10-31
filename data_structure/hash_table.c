#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
  char* key;
	int value;
	struct linked_list* next;
} List;

List* table[256] = {0};

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

void list_remove(char* key, List** list)
{
	if (*((*list)->key) == *key) {
    List* tmp = *list;
    *list = (*list)->next;
    free(tmp);
  } else if ((*list)->next == NULL) {
    return;
  } else {
    list_remove(key, &((*list)->next));
  }
}

int list_find(char* key, List* list)
{
  if (list == NULL) {
    return 0;
  } else if (*(list->key) == *key) {
    return list->value;
  } else if (list->next == NULL) {
    return 0;
  } else {
    list_find(key, list->next);
  }
}

void hash_table_add(char* key, int value)
{
  int key_number = 0;
  for (int i = 0; *(key + i) != '\0'; i++) {
    key_number += *(key + i); 
  }
  int hash = key_number % 256;
  if (table[hash] != 0) {
      table[hash] = list_new(key, value);
  } else {
    list_cons(key, value, &(table[hash]));
  }
}

int hash_find(char* key) 
{
  int key_number = 0;
  for (int i = 0; *(key + i) != '\0'; i++) {
    key_number += *(key + i); 
  }
  int hash = key_number % 256;
  return list_find(key, table[hash]);
}

int main(void) 
{
  hash_table_add("rain", 34);
  hash_table_add("whh", 530);
  printf("%d ", hash_find("rain"));
  printf("%d ", hash_find("whh"));
	return 0;
}
