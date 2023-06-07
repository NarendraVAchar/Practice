#include <stdio.h>
#include <stdlib.h>

void reverse(int *a, int len)
{
	for (int i = 0; i <= (len/2) ; i++) {
		int temp = *(a + i);
		*(a + i) = *(a + len - i - 1);
		*(a + len - i - 1) = temp;
	}
}

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int len = sizeof(a)/sizeof(a[0]);

	reverse(a, len);

	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
