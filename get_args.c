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
	printf("%s\n", args[0]);
	if (strcmp(args[0], "exit") == 0) /*exit*/
	{
		free(args);
		free(token);
		return (-1);
	}
	if (strcmp(args[0], "help") == 0) /*help*/
		printf("This is a help, watch the man page - man ./man_1_simple_shell");
	else if (strcmp(args[0], "env") == 0) /*print environment*/
	{
		free(args);
		free(token);
		for (j = 0; ev[j] != NULL; j++)
			printf("%s\n", ev[j]);
		return (0);
	}
	error = exec_cmd(args, ev);
	free(args);
	free(token);
	return (error);
}

