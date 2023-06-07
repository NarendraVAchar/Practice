#include <stdio.h>

int main(void)
{
	int num = 0x1234;

	num = ((num & 0x00FF) << 8) | ((num & 0xFF00) >> 8);
	
	printf("Swap: %d\n", num);
	return 0;
}
