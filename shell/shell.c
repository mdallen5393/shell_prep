#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **av;

char **make_av(char *);
void print_array(char **av);
int execute(char **command);

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
			if (execute(command) == -1)
				break;
		}
	}
	
	free(buffer);
	free(av);

	return (0);
}


int execute(char **command)
{
	pid_t is_kid;
	
	is_kid = fork();

	if (is_kid != 0)
	{
		wait(NULL);
		return(0);
	}
	if (is_kid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("Error: ");
			return (-1);
		}
	}

	return (0);
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

	av = malloc(sizeof(*av) * (numArgs + 2));

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
