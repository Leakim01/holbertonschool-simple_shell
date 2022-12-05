#include "main.h"

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
			printf("\nSee you soon!\n");
			break;
		}
		token = strtok(buffer, " \t\n");
		if (!token)
			break;
		if (strcmp(token, "exit") == 0)
		{
			printf("Goodbye!\n");
			free(buffer);
			return (str);
		}
	}
	free(buffer);
	return (0);
}
