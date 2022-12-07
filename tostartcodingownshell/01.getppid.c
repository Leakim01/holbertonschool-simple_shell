#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t _pid;

	_pid = getppid();
	printf("Parent: %u\n", _pid);
	_pid = getpid();
	printf("Enfant: %u\n", _pid);
	return (0);
}
