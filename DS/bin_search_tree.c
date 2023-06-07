#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;


Node *create(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));

	temp->data = data;
	temp->left = NULL;
	temp->right =  NULL;

	return temp;
}

void inorder(Node *ptr)
{
	if (ptr != NULL)
	{
		inorder(ptr->left);
		printf("%d\t", ptr->data);
		inorder(ptr->right);
	}
}

void preorder(Node *ptr)
{
	if (ptr != NULL) {
		printf("%d\t", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(Node *ptr)
{
	if (ptr != NULL) {
              	postorder(ptr->left);
                postorder(ptr->right);
                printf("%d\t", ptr->data);
        }
	
}

Node *insert(Node *ptr, int data)
{
	Node *temp = create(data);

	if (ptr == NULL)
		ptr = temp;
	else {
		if (data < ptr->data)
			ptr->left = insert(ptr->left, data);
		if (data >= ptr->data)
			ptr->right = insert(ptr->right, data);
	}

	return ptr;
}

Node *minValNode(Node *ptr)
{
	Node *temp = ptr;

	if (temp && temp->left != NULL)
		temp = temp->left;

	return temp;
}

Node *delete(Node *ptr, int data)
{
	if(ptr != NULL) {
		if (data < ptr->data)
			ptr->left = delete(ptr->left, data);
		else if (data > ptr->data)
			ptr->right = delete(ptr->right, data);
		else {
			if (ptr->left == NULL) {
				Node *temp =ptr->right;
				free(ptr);
				return temp;
			}
			else if (ptr->right == NULL) {
				Node *temp = ptr->left;
				free(ptr);
				return temp;
			}
			

			Node *temp = minValNode(ptr->right);

			ptr->data = temp->data;

			ptr->right = delete(ptr->right, temp->data);

		}
	}

	return ptr;
}

int main(void)
{
	Node *root = NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 4);

	root = delete(root, 10);

	inorder(root);
	printf("\n");

	preorder(root);
	printf("\n");

	postorder(root);
	printf("\n");
	
	return 0;
}
