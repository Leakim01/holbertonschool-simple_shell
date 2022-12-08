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
	pid_t pid;
	int error = 0;

	if (!av[0])
		return (-3);
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
	return (error);
}
