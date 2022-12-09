#include "main.h"
/**
 * inner_cmd - excute cmd
 * @cmd: command string
 * @ev: environment
 *
 * Return: 0
 */

int inner_cmd(const char *cmd, char *ev[])
{
	int j = 0;

	if (cmd == NULL)
	{
		return (-3);
	}
	if (strcmp(cmd, "exit") == 0) /*exit*/
	{
		return (-1);
	}
	else if (strcmp(cmd, "help") == 0) /*help*/
		printf("This is a help, watch the man page - man ./man_1_simple_shell");
	else if (strcmp(cmd, "env") == 0) /*print environment*/
	{
		for (j = 0; ev[j] != NULL; j++)
			printf("%s\n", ev[j]);
		return (-2);
	}

	return (0);
}
