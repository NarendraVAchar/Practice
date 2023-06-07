#include <stdio.h>

#define MAX 5
int s[MAX];
int top = -1;

int isfull(void)
{
	if (top == MAX)
		return 1;

	return 0;
}

int isempty(void)
{
	if (top == -1)
		return 1;

	return 0;
}

void push(int data)
{
	if (!isfull()) {
		top += 1;
		s[top] = data;
	}
	else
		printf("Stack is full....\n");
}

int pop()
{
	int data;
	if (!isempty())
	{
		data = s[top];
		top -= 1;
	}
	else
		printf("Stack is Empty...\n");
	
	return data;
}

int main(void)
{
	int data;
/*
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
*/

	for (int i = 0; i < 5; i++) {
		scanf("%d", &data);
		push(data);
	}
	
	while (!isempty()) {
		data = pop();
		printf("%d \t", data);
	}

	printf("\n");

	return 0;
}
