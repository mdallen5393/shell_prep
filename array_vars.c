#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **str_tok(char *str)
{
static char **tokens;
	int i = 0;
	char *buffer = strdup(str);
	char *token;
	int len = 0, numTokens = 0;

	while (buffer[len])
	{
		if (buffer[len] == ' ')
			numTokens++;
		len++;
	}

	token = malloc(sizeof(*token) * (numTokens + 1));

	token = strtok(buffer, " ");
	tokens[i] = token;
	i++;
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		tokens[i] = token;
		i++;
	}

	return (tokens);
}


int main(int ac, char **av)
{
	char **array;
	int i = 0;

	array = str_tok("Hello World. You Suck.");

	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
