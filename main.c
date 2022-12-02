#include "main.h"
/**
 * main - Function.
 *
 * Return: 0.
 */

int main(void)
{
	char *buffer = NULL, *token;
	size_t str = 0, len = 0;

	while (1)
	{
		if (isatty(0) == 1)
		{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			printf("%s\t$ ", cwd);
		}
		getline(&buffer, &len, stdin);
		if (getline(&buffer, &len, stdin) == EOF)
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
			return (str);
		}
		/*if (strcmp(token, "env") == 0)
		{
			int i = 0;
			while (env[i])
			{
				printf("%s\n", env[i]);
				i++;
			}
			return(0);
		}*/
		if (pathverify(args[0]) == 1)
		{
			args[0] = which(args[0]);
			if (!args[0])
			{
				perror("problem");
				continue;
			}
		}/*fork*/
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
	int status = 0;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error:");
			return (0);
		}
	}
	else
		wait(&status);
	return (0);
}*/
