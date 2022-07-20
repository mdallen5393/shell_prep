#include <stdio.h>
#include <unistd.h>

/**
 * main - get parent PID
 * Return: always 0.
 */
int main(void)
{
	pid_t my_pid, my_parent_pid;

	my_pid = getpid();
	my_parent_pid = getppid();

	printf("My PID is %u; my parent's PID is %u.\n", my_pid, my_parent_pid);
	return (0);
}
