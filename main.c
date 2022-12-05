#include "main.h"
/**
* main - Function.
*
* Return: 0.
*/

int main(int ac, char *av[], char *ev[])
{
	char *buffer = NULL, *token;
	char *args;
	size_t str = 0, len = 0, inputchar;

	(void) ac;
	(void) av;

	while (1)
	{
		if (isatty(0) == 1)
		{
			char cwd[1024];

			getcwd(cwd, sizeof(cwd));
			args = strtok(cwd, " ");

			exec_cmd(args, ev);
		}
		inputchar = getline(&buffer, &len, stdin);
		if (inputchar == (size_t) EOF)
			break;

		token = strtok(buffer, " \t\n");
		if (!token)
			break;
		if (strcmp(token, "exit") == 0)
		{
			free(buffer);
			return (str);
		}
	}
	free(buffer);
	return (0);
}
