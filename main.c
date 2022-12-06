#include "main.h"
/**
 * handle_signal - Crtl+C doesnt leave
 * @signal: int
 *
 * Return: While.
 */
void handle_signal(int signal)
{
	(void) signal;
	printf("\n($) ");
	fflush(stdout);
}

/**
 * main - main function shell
 * @ac: argc
 * @av: argv
 * @ev: environment
 *
 * Return: 0
 */

int main(int ac, char *av[], char *ev[])
{
	char *buffer;
	char **args;
	size_t str = 0, len = 1024, inputchar;
	int i = 0, j = 0;

	(void) ac;
	(void) av;
	(void) str;

	buffer = malloc(1024 * sizeof(char));
	if (!buffer)
		return (-1);

	signal(SIGINT, handle_signal);/*handle ctrl+C doest quit*/
	while (1)
	{
		if (isatty(0) == 1)
		{
			char cwd[1024];
			printf("($) ");
			getcwd(cwd, sizeof(cwd));
		}
		inputchar = getline(&buffer, &len, stdin);
		if (inputchar == (size_t) EOF)
		{
			printf("\n");
			exit(0);
		}
		args = get_cmd(buffer);
		if (!args)
			break;
		if (strcmp(buffer, "\n") == 0) /*handle \n - backline*/
		{
			free(buffer);
			buffer = NULL;
			continue;
		}

		if (strcmp(args[0], "exit") == 0) /*handle exit and leave*/
			break;
		if (strcmp(args[0], "env") == 0) /*handle env and print env before leave*/
		{
			for (j = 0; ev[j]; j++)
				printf("%s\n",ev[j]);
			break;
		}
		args = get_cmd(buffer);
		exec_cmd(args, ev);
	}
	free(buffer);
	for (; i <= 1024; i++)
		free(args[i]);
	free(args);
	return (0);
}
