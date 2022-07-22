#include "main.h"

char **av;
char **make_env(char *str);
char *_stat(char **av);
char *_which(char *exec);
void print_array(char **array);

int main(void)
{
	printf("'ls' is located in the folder: ");
	printf("%s", _which("cppw"));
	printf("\n");
}

char *_which(char *exec)
{
	char *executable;
	char *path;
	char **path_array;
	int i = 0;
	char *final_path;

	executable = strcpycat("/", exec);
	path = _getenv("PATH");
	path_array = make_env(path);

	while (path_array[i])
	{
		path_array[i] = strcpycat(path_array[i], executable);
		i++;
	}
	
	final_path = _stat(path_array);
	if (final_path)
		return (final_path);
	
	return (NULL);
}

char *_stat(char **av)
{
	unsigned int i;
	struct stat st;

	i = 0;
	while (av[i])
	{
		if (stat(av[i], &st) == 0)
			return (av[i]);
		i++;
	}
	return (NULL);
}

char **make_env(char *str)
{
	char *buffer = strdup(str);
	char *element;
	int i = 0, numElements = 0;

	while (buffer[i])
	{
		if (buffer[i] == ':')
			numElements++;
		i++;
	}

	av = malloc(sizeof(*av) * (numElements + 2));

	element = strtok(buffer, ":");
	av[0] = element;

	i = 1;
	while (element != NULL)
	{
		element = strtok(NULL, ":");
		av[i] = element;
		i++;
	}

	return (av);
}

void print_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
	if (array[i] == NULL)
		printf("NULL\n");
}
