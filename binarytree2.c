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

void printtree2(Node* node) 
{
	if (node->right != NULL) {
		printtree(node->right);
	}

	printf("%d ", node->value);
	
	if (node->left != NULL) {
		printtree(node->left);
	}
	
}
		
		
void change(Node** node, Node** findnode) 
{
	if ((*node)->left == NULL) {
		*node = *findnode;
	} else if ((*findnode)->left->left == NULL) {
		Node** nodeleft = &((*node)->left);
		Node** noderight = &((*node)->right);
		Node** findnoderight = &((*findnode)->left->right);
		*node = (*findnode)->left;
		(*node)->left = *nodeleft;
		(*node)->right = *noderight;
		(*node)->left = *findnoderight;
	} else {
		change(node, &((*node)->left));
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
		change(node, &((*node)->right));
	}
}


int main(void) 
{
	Node* node = malloc(sizeof(Node));
	node->value = 5;
	node->left = NULL;
	node->right = NULL;


	addnode(&node, 9);	
	printtree(node);
	printf("\n");
	addnode(&node, 2);	
	printtree(node);
	printf("\n");
	addnode(&node, 3);	
	printtree(node);
	printf("\n");
	addnode(&node, 4);	
	printtree(node);
	printf("\n");
	addnode(&node, 1);	
	printtree(node);
	printf("\n");
	addnode(&node, 7);	
	printtree(node);
	printf("\n");
	addnode(&node, 6);	
	printtree(node);
	printf("\n");
	addnode(&node, 11);	
	printtree(node);
	printf("\n");
	delete(&node, 4);
	printtree(node);
	printf("\n");
	delete(&node, 11);
	printtree(node);
	printf("\n");

	return 0;
}
