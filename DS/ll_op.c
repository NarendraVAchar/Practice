#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
}

typedef Node;
Node *head = NULL;

Node *create(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	Node *ptr = head;

	temp->data = data;
	temp->next = NULL;

	return temp;
}

void display()
{
	Node *ptr = head;
	if (head == NULL)
		printf("List is empty\n");
	else {
		while (ptr != NULL) {
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n");
}

void insertend(int data)
{
	Node *temp = create(data);
	Node *ptr = head;

	if (head == NULL)
		head = temp;
	else {
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = temp;
	}

	display();
}

void insertbegin(int data)
{
	Node *temp = create(data);
	Node *ptr = head;

	if (head == NULL)
		head = temp;
	else {
		temp->next = ptr;
		head = temp;
	}

	display();
}

int findlen()
{
	int len = 0;
	Node *ptr = head;

	while (ptr != NULL) {
		len++;
		ptr = ptr->next;
	}

	return len;
}

void insertpos(int data, int pos)
{
	Node *temp = create(data), *ptr = head;

	if (pos <= findlen()) {
		if (head == NULL)
			head = temp;
		else {
			Node *prev;
			for (int i = 0; i < pos-1; i++) {
				prev = ptr;
				ptr = ptr->next;
			}
				temp->next = ptr;
				prev->next = temp;
		}
	}

	display();
}

void deleteend()
{
	Node *ptr = head, *prev;

	if (head == NULL)
		printf("EMPTY\n");
	else if (head->next == NULL) {
		head = NULL;
	}
	else {
		while (ptr->next != NULL) {
			prev = ptr;
			ptr = ptr->next;
		}

		prev->next = NULL;
		free(ptr);
	}

	display();
}

void deletebegin()
{
	Node *ptr = head, *temp;

	if (head == NULL)
		printf("EMPTY\n");
	else if (head->next == NULL)
		head = NULL;
	else {
		temp = ptr->next;
		head = temp;
		free(ptr);
	}

	display();
}

void deletepos(int pos)
{
	Node *ptr = head, *prev;

	if (pos <= findlen())
	{
		if (head == NULL)
			printf("EMPTY\n");
		else {
			for (int i = 0; i < pos - 1; i++) {
				prev = ptr;
				ptr = ptr->next;
			}

			prev->next = ptr->next;
			free(ptr);
		}
	}

	display();
}

void reverse()
{
	Node *ptr = head, *prev = NULL, *next = NULL;

	if (head == NULL)
		printf("Empty\n");
	else {
		while (ptr != NULL) {
			next = ptr->next;
			ptr->next = prev;
			prev = ptr;
			ptr = next;

		}

		head = prev;
	}

	display();
}

void back_print(Node *ptr)
{
	if (head == NULL)
                printf("EMPTY\n");
        else {
		if (ptr->next != NULL)	
			back_print(ptr->next);
	}
	printf("%d -> ", ptr->data);
}

int main(void)
{
	insertend(10);
	insertend(30);
	insertend(20);

	insertbegin(50);
	insertbegin(40);

	insertpos(90, 3);

	deleteend();
	deletebegin();
	deletepos(3);

	reverse();
	//back_print(head);

	return 0;
}
