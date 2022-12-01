#include "main.h"
/**
* main - Function.
*
* Return: 0.
*/

int main(void)
{
	char *buffer = NULL, *token;
	size_t str = 0, len = 0, inputchar;

	while (1)
	{
		if (isatty(0) == 1)
		{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			printf("%s\t$ ", cwd);
		}
		inputchar = getline(&buffer, &len, stdin);
		if (inputchar == EOF)
		{
			printf("\nsee you soon\n");
			break;
		}
		token = strtok(buffer, " \t\n");
		if (!token)
			break;
		if (strcmp(token, "exit") == 0)
		{
			printf("miouhhhfdfdkflmdfk\n");
			free(buffer);
			return (str);
		}
	}
	free(buffer);
	return(0);
}

/**
 * created_fork - Create new proccess.
 * @args: Strings.
 * @env: Environment variables.
 * Return: 0.
 */
/*int created_fork(char **args, char **env)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (0);
	}
	else
		wait(&status);
	return (0);
}*/

