#include "main.h"

/**
 * func - Entry point...
 * Description: 'the program desc'
 * Return: Always 0 (Success)
 * @a: int parmameter
 * @b: int parmameter
 */

char **get_cmd (char *str)
{
	char *strcpy = strdup(str);
	char *ptr;
	int i = 0;
	char **list = malloc(sizeof(char *) * 1024);
	if (!list)
		return (NULL);

	ptr = strtok(strcpy, " \n\t\r");

	for (; ptr != NULL; i++)
	{
		list[i] = malloc(sizeof(char) * 1024);
		if (!list[i])
			return (NULL);
		list[i] = strdup(ptr);
		ptr = strtok(NULL, " \n\t\r");
	}

	free(ptr);
	free(strcpy);
	return (list);
}
