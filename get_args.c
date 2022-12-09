#include "main.h"
/**
 * get_cmd - get command
 * @str: string pointer
 * @size: size
 * @ev: environment
 *
 * Return: Error
 */
int get_cmd(char *str, size_t size, char *ev[])
{
	char **args;
	char *token;
	int i = 0, error;

	args = malloc(size * sizeof(char *));
	if (!args)
		return (-2);
	token = strtok(str, " \n\t\r");
	while (token != NULL)
	{
		if (strlen(token) == 0)
			continue;
		args[i++] = token;
		token = strtok(NULL, " \n\t\r");
	}
	args[i] = NULL;

	error = inner_cmd(args[0], ev);
	if (error != 0)
	{
		free(args);
		if (error > -3)
			free(token);
		return (error);
	}

	error = exec_cmd(args, ev);
	free(args);
	free(token);
	return (error);
}

