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
	printf("\n($)");
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
	int error;

	(void) ac;
	(void) av;
	(void) ev;

	buffer = malloc(len * sizeof(char));
	if (!buffer)
		return (-1);

	signal(SIGINT, handle_signal);/*handle ctrl+C doest quit*/
	while (1)
	{
		printf("($)");
		if (isatty(0) == 1)
		{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
		}
		inputchar = getline(&buffer, &len, stdin);
		if (inputchar == (size_t) EOF)
		{
			printf("\n");
			break;
		}
		error = get_cmd(buffer, len, ev);
		/*  ERROR GET CMD
		 * -4 EXECUTION ERROR
		 * -3 NO CMD
		 * -2 MALLOC ERROR
		 * -1 EXIT
		 * 0 SUCCESS
		 * 1 ENV CMD
		 */
		printf("ERROR : %d\n", error);
	}

	free(buffer);
	return (0);
}
