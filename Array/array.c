#include <stdio.h>

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i = 0;

	*(a + 3) = 6;
	*(a + 4) = *(a + 3);

	while (i < 10) {
		printf("%d ", a[i++]);
	}

	printf("\n");

	return 0;
}
