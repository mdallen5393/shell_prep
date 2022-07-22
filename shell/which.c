#include "main.h"

int main(int ac, char **av)
{
	printf("'%s' is located in the folder: ", av[1]);
	printf("%s", _which(av[1]));
	printf("\n");
}


char *_which(char *exec)
{
	char *executable;
	char *path, *curr;
	list_t *path_list;
	int i = 0;
	char *final_path;
	struct stat st;
	
	executable = strcpycat("/", exec);
	path = _getenv("PATH");
	path_list = make_env(path);
	while (path_list)
	{
		curr = strcpycat(path_list->str, executable);
		if (stat(curr, &st) == 0)
			return (curr);
		path_list = path_list->next;
	}

	return (NULL);
}
/*
char *_stat(char *filename)
{
	unsigned int i;
	struct stat st;

	i = 0;
	while (filename)
	{
		if (stat(filename, &st) == 0)
			return (filename);
	}
	return (NULL);
}
*/
list_t *make_env(char *str)
{
	list_t *env;
	list_t *head = env;
	list_t *new;

	char *buffer = strdup(str);
	char *nodeStr;
	int i = 0, numNodes = 0;
	
	nodeStr = strtok(buffer, ":");

	new = malloc(sizeof(list_t));
	if (!new)
	{
		printf("Error\n");
		return (NULL);
	}
	
	new->str = nodeStr;
	new->next = NULL;

	while (nodeStr != NULL)
	{
		nodeStr = strtok(NULL, ":");
		add_node_end(&head, nodeStr);
		i++;
	}
	return (head);
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
