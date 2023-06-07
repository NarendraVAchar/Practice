#include <stdio.h>

#define MAX 5
int q[MAX];

int front = -1, rear = -1;

void display(void);

void insert(int data)
{
	if (rear == MAX - 1)
		printf("Queue is full\n");
	else {
		if (front == -1) {
			front++;
			rear++;
		}
		else
			rear++;

		q[rear] = data;
	}
}

int delete()
{
	int data;

	if (front == -1)
		printf("Queue is empty\n");
	else {
		data = q[front];
		front++;
		if (front > rear)
			front = rear = -1;
	}

	return data;
}

int main(void)
{
	int data;

	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);

	while (front != -1) {
		data = delete();
		printf("%d\t", data);
	}

	return 0;
}
