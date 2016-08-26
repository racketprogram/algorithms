#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* left;
	struct node* right;

} Node;

void addnode(Node** node, int newvalue)
{

	if (newvalue > (*node)->value) {
		if ((*node)->right == NULL) {
			Node* newnode = malloc(sizeof(Node));
			newnode->value = newvalue;
			newnode->left = NULL;
			newnode->right = NULL;
			(*node)->right = newnode;
		} else {
			addnode(&((*node)->right), newvalue);
		}
	} else if (newvalue < (*node)->value) {
		if ((*node)->left == NULL) {
			Node* newnode = malloc(sizeof(Node));
			newnode->value = newvalue;
			newnode->left = NULL;
			newnode->right = NULL;
			(*node)->left = newnode;
		} else {
			addnode(&((*node)->left), newvalue);
		}
	} else {
		return;
	}
	
}

void printtree(Node* node) 
{
	if (node->left != NULL) {
		printtree(node->left);
	}
	
	printf("%d ", node->value);
	
	if (node->right != NULL) {
		printtree(node->right);
	}
}
		
void change(Node** node, Node** oldleft) 
{
	if (*oldleft != NULL) {
		if ((*node)->right != NULL) {
			change(&((*node)->right), &((*node)->right->left));
			*node = (*node)->right;
			(*node)->left = *oldleft;
		} else if ((*node)->left != NULL) {
			*node = *oldleft;
		}
	} else {
		*node = (*node)->right;
	}
}

void delete(Node** node, int deletevalue)
{
	if ((*node)->value > deletevalue && (*node)->left != NULL) {
		delete(&((*node)->left), deletevalue);
	} else if ((*node)->value < deletevalue && (*node)->right != NULL) {
		delete(&((*node)->right), deletevalue);
	} else if ((*node)->value == deletevalue) {
		printf("%d\n", (*node)->value);
		change(node, &((*node)->left));
	}
}


int main(void) 
{
	Node* node = malloc(sizeof(Node));
	node->value = 5;
	node->left = NULL;
	node->right = NULL;


	addnode(&node, 9);	
	addnode(&node, 2);	
	addnode(&node, 3);	
	addnode(&node, 4);	
	addnode(&node, 1);	
	addnode(&node, 6);	
	addnode(&node, 7);	
	addnode(&node, 11);	
	printtree(node);
	printf("\n");
	delete(&node, 5);
	printtree(node);

	return 0;
}
