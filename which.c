#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;
char **av;
/*environ->PATH*/
char **make_av(char *str);
char *_stat(char **av);

int main(void)
{
	char *path = environ->PATH;
	char **pathtok = make_av(path);
	char *command = "ls";
	int i = 0;
	char *final_path;

	command = strcat("/", command);

	/*["/usr/bin", "/usr", "/bin", NULL]*/

	while (pathtok[i])
	{
		pathtok[i] = strcat(pathtok[i], command);
		i++;
	}

	final_path = _stat(pathtok);

	if (final_path)
	{
		printf("%s\n", final_path);
		return (0);
	}

	/*["/usr/bin/ls", "/usr/ls", "/bin/ls", NULL]*/

	return (-1);
}

char *_stat(char **av)
{
	unsigned int i;
	struct stat st;

	i = 0;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
			return (av[i]);
		i++;
	}
	return (NULL);
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











[ "USER=root", "LOGNAME=...", ..., "PATH=usr/bin:/bin:/usr....", ... ]










