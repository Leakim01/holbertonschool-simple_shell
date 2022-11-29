#include <stdio.h>
#include <stdlib.h>
/**
 * main - Write a program that prints all the arguments, without using
 * Return: 0
 */
int main(int i, char **av)
{
	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s ", av[i]);
	}
	printf("\n");
	return (0);
}
