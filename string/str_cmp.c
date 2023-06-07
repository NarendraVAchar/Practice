#include <stdio.h>

int str_cmp(char *s1, char *s2)
{
	while (*s1) {
		if (*s1 != *s2)
			break;

		s1++;
		s2++;
	}

	return *s1 - *s2;
}

int main(void)
{
	char *s1 = "hello";
	char *s2 = "hello";

	if (!str_cmp(s1, s2))
		printf("Equal\n");
	else
		printf("Not Equal\n");

	return 0;
}
