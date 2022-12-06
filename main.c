#include "main.h"
#include <signal.h>

/**
 * handle_signal - Crtl+C doesnt leave
 * @signal: int
 *
 * Return: While.
 */

void handle_signal(int signal)
{
	(void) signal;
	printf("\n\t($)");
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
	char *buffer = NULL, *token;
	char *args;
	size_t str = 0, len = 1024, inputchar;
	(void) ac;
	(void) av;

	signal(SIGINT, handle_signal);/*handle ctrl+C doest quit*/
	while (1)
	{
		if (isatty(0) == 1) /*$ apparence for every line*/
		{
			char cwd[1024];
			printf("\t($) ");
			args = strtok(cwd, " ");
		}
		inputchar = getline(&buffer, &len, stdin); /*getline*/
		if (inputchar == (size_t) EOF) /*handle ctrl+D - exit*/
		{
			if (buffer)
			{
				free(buffer);
				buffer = NULL;
			}
			exit(0);
		}
		if (strcmp(buffer, "\n") == 0) /*handle \n - backline*/
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		token = strtok(buffer, " \t\n");
		if (!token)
			break;
		if (strcmp(token, "exit") == 0) /*handle exit and leave*/
		{
			free(buffer);
			return (str);/*break;*/
		}
		if (strcmp(token, "env") == 0) /*handle env and print env before leave*/
		{
			int i;
			for (i = 0; ev[i]; i++)
				printf("%s\n", ev[i]);
			return (str);/*break;*/
		}
		/*args = get_cmd(buffer);
		exec_cmd(args, ev);*/
		for (str = 0; str < 1024 && token != NULL; str++)
		{
			args[str] = *token;
			token = strtok(NULL, "\t\n\r");
		}
		/*args[str] == NULL;
		if (!args[0])
		{
			free(args[0]);
			free(buffer);
			return (0);
		}*/
	}
	free(buffer);
	return (0);
}
