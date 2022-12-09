#include "main.h"
/**
 * handle_signal - Crtl+C doesnt leave
 * @signal: int
 *
 * Return: While.
 */
void handle_signal(int signal)
{
	(void) signal;
/*	printf("\n#cisfun$ ");*/
	fflush(stdout);
}


/**
 * main - main function shell
 * @ac: argc
 * @av: argv
 * @ev: environment
 *
 * Return: 0
 */

int main(int ac, char *av[], char *ev[])
{
	char *buffer;
	size_t len = 1024, inputchar;
	int error = 0;

	(void) ac;
	(void) av;
	(void) ev;
	(void) error;

	buffer = malloc(len * sizeof(char));
	if (!buffer)
		return (-1);

	signal(SIGINT, handle_signal);/*handle ctrl+C doesnt quit*/
	while (1)
	{
		inputchar = getline(&buffer, &len, stdin);
		fflush(stdin);

		if (inputchar == (size_t) EOF)
			break;
		error = get_cmd(buffer, len, ev);
		if (error == -1)
		{
			free(buffer);
			exit(0);
		}
		else if (error == -3)
		{
			free(buffer);
			exit(0);
		}
		else if (error == 4)
		{
			free(buffer);
			exit(2);
		}
		/*4EXECER|3NOCMD|2MALLOCER|-1EXIT|0SCCESS|1ENVCMD*/
		/*printf("ERROR : %d\n", error);*/
	}
	free(buffer);
	return (0);
}
