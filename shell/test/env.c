#include "main.h"

char **a = {"TEST=hello", "STUFF=yaaaay", "TRASH=your mom"};

int main(int ac, char **av, char **env)
{
	int i = 0;
	char *name = "TESTYBOIII";
	char *value = "hi guyz";
	
	printf("----\n");
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	printf("----\n");
	
	_setenv(name, value, 0);
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	printf("----\n");
	
	_setenv(name, "hello", 0);
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	printf("----\n");

	_unsetenv(name);
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	printf("----\n");

	return (0);
}


int *envloc(const char *name)
{
	unsigned int i = 0;
	int diff;
	int varlen = _strlen(name);

	while (a[i])
	{
		diff = _strncmp(a[i], name, varlen);
		if (diff == 0)
			return (i);
		i++;
	}
	return (-1);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	int i, len = 0;
	int loc = envloc(name);
	char **new_a;
	
	name = strcpycat(name, "=");
	name = strcpycat(name, value);
	
	if (loc != -1)
	{
		if (overwrite == 0)
			return (0);
		a[loc] = name;
		return (0);
	}

	while (a[len])
		len++;

	new_a = malloc(sizeof(*new_a) * (len + 1));
	if (!new_a)
		return (-1);

	for (i = 0; i < len; i++)
		new_a[i] = a[i];

	new_a[i] = name;

	free(a);
	a = new_a;

	return (0);
}

int _unsetenv(const char *name)
{
	int loc = envloc(name);
	int i, j; len = 0;
	char **new_a;

	while (a[len])
		len++;

	if (loc != -1)
	{
		free(a[loc]);
		new_a = malloc(sizeof(*new_a) * (len - 1));
		
		j = 0;
		for (i = 0; i < len; i++)
		{
			if (i != loc)
			{
				new_a[i] = a[j];
				j++;
			}
		}
		
		free(a);
		a = new_a;
	}

	return (0);
}