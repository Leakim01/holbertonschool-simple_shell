#include "main.h"
/**
 * exec_cmd - excute cmd
 * @av: array of string pointers containing command line arguments
 * @ev: environment
 *
 * Return: 0
 */
int exec_cmd(char *av[], char *ev[])
{
	const char *path = "/bin/";
	char *cmd;
	pid_t pid;
	int error = 0;
	int have_path = !strstr(av[0], "./") && !strstr(av[0], "/bin/");

	if (!av[0])
		return (-3);

	if (have_path)
	{
			cmd = strdup(path);
			strcat(cmd, av[0]);
			av[0] = strdup(cmd);
			free(cmd);
	}

	pid = fork();
	switch (pid)
	{
		case -1:
			error = 4;
			break;
		case 0:
			if (execve(av[0], av, ev) == -1)
				printf("EXECVE ERROR\n");
			exit(1);
			break;
		case 1:
			error = 0;
			break;
	}
	pid = wait(NULL);
	if (have_path)
		free(av[0]);

	return (error);
}
