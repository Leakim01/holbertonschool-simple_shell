#include "main.h"
#include <signal.h>


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
		/*if (strcmp(buffer, "\n") == 0)
			return (str);*/
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
		/*if (sigterm_handler)
		{
			return (0);
		}*/
		/*not sure if it works*/
		for (str = 0; str < 1024 && token != NULL; str++)
		{
			args[str] = *token;
			token = strtok(NULL, "\t\n\r");
		}
	}
	free(buffer);
	return (0);
}
/*
void sigintHandler(int sig_num)
{
	signal(SIGINT, sigintHandler);
	printf("\n Cannot be terminated using Ctrl+C \n");
	fflush(stdout);
}*/
