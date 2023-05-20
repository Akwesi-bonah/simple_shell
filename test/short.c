#include "shell.h"
/**
 * shortcut - When Ctrl+C is pressed, SIGINT signal is generated
 * @num: Reset handler to catch SIGINT next time.
 * Return: 0
 */

void shortcut(int num)
{
	(void)num;

	signal(SIGINT, shortcut);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
