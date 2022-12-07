#include "main.h"

int get_cmd (char *str, size_t size, char *ev[])
{
	char **args;
	char *token;

	int i = 0, j = 0, error;

	(void) ev;
	(void) i;

	args = malloc(size * sizeof(char *));
	if (!args)
		return (-2);

	token = strtok(str, " \n\t\r");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n\t\r");
	}

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(token);
		exit (0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		free(args);
		free(token);
		for (j = 0; ev[j] != NULL; j++)
			printf("%s\n",ev[j]);
		return(0);
	}

	error = exec_cmd(args, ev);

	free(args);
	free(token);
	return (error);
}

