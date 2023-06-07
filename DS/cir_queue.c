#include <stdio.h>

#define MAX 5
int front = -1, rear = -1;
int cq[MAX];

void display(void);

int isempty()
{
	if(front == -1 && rear == -1)
		return 1;

	return 0;
}

int isfull()
{
	if (front == (rear + 1) % MAX)
		return 1;
	return 0;
}

void enqueue(int data)
{
	if (isfull())
		printf("Queue is full\n");
	else {
		if (isempty())
			front++;
		rear = (rear + 1) % MAX;

		cq[rear] = data;
	}

	display();
}

void dequeue()
{
	if (isempty())
		printf("Queue is empty\n");
	else {
		front = (front + 1) % MAX;

		if (front == rear) {
			front = rear = -1;
		}
	}

	display();
}

void display(void)
{
	if (isempty())
		printf("Queue is empty\n");
	else {
		for (int i = front; i != (rear + 1) % MAX; i = (i + 1) % MAX)
			printf("%d \t", cq[i]);
	}

	printf("\n");
}

int main(void)
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	dequeue();
	enqueue(40);
	dequeue();
	enqueue(50);
	enqueue(60);
	enqueue(70);
	enqueue(80);

	return 0;
}
