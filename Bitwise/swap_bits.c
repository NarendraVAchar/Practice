#include <stdio.h>

int main(void)
{
	int num = 0xA, p = 1, q = 2;

	if (((num >> p) & 1) ^ ((num >> q) & 1))
	{
		num ^= (1 << p);
		num ^= (1 << q);
	}

	printf("Swap: %d\n", num);

	return 0;
}
