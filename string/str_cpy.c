#include <stdio.h>

char *str_cpy(char *ptr, char *src)
{
	char *dest = ptr;
	while (*src != '\0') {
		*dest = *src;
		*dest++; *src++;
	}
	*dest = '\0';
}

int main(void)
{
	char str[100];
	char dest[100];

	fgets(str, 100, stdin);

	str_cpy(dest, str);
	printf("%s\n", dest);

	return 0;
}
