#include <stdio.h>

void bubble_sort(int *a, int len)
{
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (*(a + j) > *(a + j + 1)) {
				int temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
}

void print(int *a, int len)
{
	int i = 0;
	while (i < len) {
                printf("%d ", a[i++]);
        }
        printf("\n");
}

int main(void)
{
	int a[10] = {12, 30, 4, 43, 12, 45, 13, 3, 5, 21};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0;

	print(a, len);

	bubble_sort(a, len);

	print(a, len);

	return 0;
}
