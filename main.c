#include "main.h"
#include <signal.h>

/**
 * main - Function.
 *
 * Return: 0.
 */

void handle_signal(int signal)
{
	/*char *prompt = {"\nYour lock with ussssss\n"};*/
	(void) signal;
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\n%s\t$ ", cwd);
	fflush(stdout);
	/*write(STDOUT_FILENO, prompt, strlen(prompt));
	exit (0);*/
}

int main(int ac, char *av[], char *ev[])
{
	char *buffer = NULL, *token;
	char *args;
	size_t str = 0, len = 0, inputchar;
	(void) ac;
	(void) av;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(0) == 1)
		{
			char cwd[1024];

			getcwd(cwd, sizeof(cwd));
			printf("%s\t$ ", cwd);
			args = strtok(cwd, " ");
			/*exec_cmd(args, ev);*/
		}
		inputchar = getline(&buffer, &len, stdin);
		if (inputchar == (size_t) EOF)
		{
			if (buffer)
			{
				free(buffer);
				buffer = NULL;
			}
			printf("\nsee you soon2\n");
			exit(0);
		}
		if (strcmp(buffer, "\n") == 0)
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		token = strtok(buffer, " \t\n");
		if (!token)
			break;
		if (strcmp(token, "exit") == 0)
		{
			free(buffer);
			printf("see you soon \n");
			return (str);
		}
		if (strcmp(token, "env") == 0)
		{
			for (int i = 0; ev[i]; i++)
				printf("%s\n", ev[i]);
			return (str);
		}
		/*not sure if it works */
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
