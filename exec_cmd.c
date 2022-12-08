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

	if (!av[0])
		return (-3);

	cmd = malloc(sizeof(char) * 1024);
	if (!cmd)
		return (-2);

	strcpy(cmd, path);
	strcat(cmd, av[0]);
	av[0] = strdup(cmd);
	free(cmd);

	pid = fork();
	switch (pid)
	{
		case -1:
			error = 4;
			break;
		case 0:
			if (execve(av[0], av, ev) == -1)
				printf("Execut Error\n");
			break;
		case 1:
			error = 0;
			break;
	}
	pid = wait(NULL);
	free(av[0]);
	return (error);
}
