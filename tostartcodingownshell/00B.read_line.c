#include <stdio.h>
#include <stdlib.h>
/**
 * main - Write a program that prints "$ ", wait for the user to enter a command
 */
int main (void)
{

	size_t len = 1024;
	char *buffer = malloc(1024);

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("%s", buffer);
	}
	return (0);
}
