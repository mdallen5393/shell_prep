#include "main.h"

char *_getenv(const char *name);
void printenv(void);

int main(int ac, char **av, char **env)
{
	/*printenv();*/
	printf("%p\n", environ[0]);
	printf("%p\n", env[0]);
	printf("%s\n", _getenv("PATH"));
	return (0);
}

void printenv(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

char *_getenv(const char *name)
{
	unsigned int i = 0;
	int diff;
	int varlen = _strlen(name);

	while (environ[i])
	{
		diff = _strncmp(environ[i], name, varlen);
		if (diff == 0)
			return (environ[i] + varlen + 1);
		i++;
	}
	return (NULL);
}
