#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t is_kid = 1;
	int i;

	for (i = 0; i < 6; i++)
	{
		if (is_kid != 0)
		{
			is_kid = fork();
			wait(NULL);
		}
		else
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error\n");
		}
	}

	return (0);
}
