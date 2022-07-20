#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **av;

char **make_av(char *);
void print_array(char **av);
void execute(char **command);

int main(void)
{
	char *buffer = NULL;
	char **command;
	size_t bufsize = 0;

	while(1)
	{
		printf("($) ");

		getline(&buffer, &bufsize, stdin);
		
		if (strcmp(buffer, "exit\n") == 0)
			break;
		else
		{
			command = make_av(buffer);
			execute(command);
		}
	}
	
	free(buffer);
	free(av);

	return (0);
}


void execute(char **command)
{
	pid_t is_kid = 
}


char **make_av(char *str)
{
	char *buffer = strdup(str);
	char *argument;
	char prev = '0';
	int i = 0, numArgs = 0;

	while (buffer[i])
	{
		if (buffer[i] == ' ' && prev != ' ')
			numArgs++;
		prev = buffer[i];
		i++;
	}

	av = malloc(sizeof(*av) * (numArgs + 1));

	argument = strtok(buffer, " \n");
	av[0] = argument;
	
	i = 1;
	while (argument != NULL)
	{
		argument = strtok(NULL, " \n");
		av[i] = argument;
		i++;
	}

	av[i] = NULL;
	/*print_array(av);*/

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
}
