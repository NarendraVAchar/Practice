#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *head = NULL;

void display()
{
	Node *ptr = head;
	if (head == NULL)
		printf("EMPTY\n");
	else {
		while (ptr != NULL) {
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n");
}

Node *create(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));

	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
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
		temp->prev = ptr;
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
		ptr->prev = temp;
		head = temp;
        }

        display();	
}

int findlen()
{
	int len = 0;
	Node *ptr = head;

	while(ptr != NULL) {
		len++;
		ptr = ptr->next;
	}

	return len;
}

void insertpos(int data, int pos)
{
	Node *temp = create(data);
	Node *ptr = head, *prev;

	if (findlen() >= pos)
	{
		if (head == NULL)
			head = temp;
		else {
			for (int i = 0; i < pos-1; i++) {
				prev = ptr;
				ptr = ptr->next;
			}

			prev->next = temp;
			temp->prev = prev;
			temp->next = ptr;
			ptr->prev - temp;
		}
	}

	display();
}

void deletebegin()
{
	Node *ptr = head;
	if (head == NULL)
		printf("EMPTY\n");
	else {
		head = head->next;
		head->prev = NULL;
		free(ptr);
	}

	display();
}

void deleteend()
{
	Node *ptr = head, *prev;

	if (head == NULL)
                printf("EMPTY\n");
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

			Node *temp = prev;
			prev->next = ptr->next;
			prev->prev = temp;

			free(ptr);
		}
	}

	display();
}

void reverse()
{
	Node *ptr = head;
	Node *temp = NULL;

	if (head == NULL)
                printf("EMPTY\n");
        else {
		while (ptr != NULL) {
			temp = ptr->prev;
			ptr->prev = ptr->next;
			ptr->next = temp;
			ptr = ptr->prev;
		}
		Node *last = head;
		head = temp->prev;
		last->next = NULL;
	}

	display();
}

int main(void)
{
	insertend(10);
	insertend(50);
	insertend(30);

	insertbegin(40);
	insertbegin(60);
	
	insertpos(90, 3);

	deleteend();
	deletebegin();
	deletepos(2);

	reverse();

	return 0;
}
