#include <stdio.h>
#include <pthread.h>

void *fun(void *vargp)
{
	printf("Child Process\n");

	return NULL;
}

int main(void)
{
	pthread_t id;

	pthread_create(&id, NULL, fun, NULL);

	pthread_join(id, NULL);
	printf("Parent Process\n");


	return 0;
}
