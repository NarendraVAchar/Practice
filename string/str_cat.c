#include <stdio.h>
#include <string.h>

void str_cat(char *s1, char *s2)
{
	char *ptr = s1 + strlen(s1);
	while (*s2 != '\0') {
		*ptr++ = *s2++;
	}
	*ptr = '\0';
}	

int main(void)
{
	char s1[100] = "hello"; 
	char s2[100] = " world";

	str_cat(s1, s2);

	printf("%s\n", s1);

	return 0;
}
