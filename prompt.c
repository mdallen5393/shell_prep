#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	while(1)
	{
		printf("($) ");

		getline(&buffer, &bufsize, stdin);
		
		if (strcmp(buffer, "exit") == 0)
			return (0);
		
		printf("%s", buffer);
	}

	return (0);
}
