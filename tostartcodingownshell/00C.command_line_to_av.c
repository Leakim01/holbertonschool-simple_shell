#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Write a function that splits a string and returns an array of each word of the string.
 *
 * Return: 0
 */
int main(void)
{
	size_t len = 1024;
	char *buffer = malloc(1024);
	char *token;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("line: %s", buffer);
	}

	token = strtok(buffer, " ");
	while (token != NULL)
	{
		printf("buffer strtok: %s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
