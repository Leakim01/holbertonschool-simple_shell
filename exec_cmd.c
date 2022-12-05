#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/wait.h>

int exec_cmd (char *av[], char *ev[])
{
	const char *path = "/bin/";
	char *cmd;
	pid_t pid;

	if (!argv[0])
		return (1);

	cmd = malloc(sizeof(char) * 1024);
	if (!cmd)
		return (1);

	strcpy(cmd, path);
	strcat(cmd, argv[0]);
	argv[0] = strdup(cmd);

	free(cmd);

	pid = fork();
	switch (pid)
	{
		case -1:
			printf("Fork Error\n");
			break;
		case 0:
			if (execve(argv[0], argv, env) == -1)
				printf("Execut Error\n");
			break;
		case 1:
			printf("END\n");
			break;
	}
	pid = wait(NULL);
	free(cmd);
	return (0);
}
