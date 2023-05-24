#include "shell.h"
/**
 * shortcut_cmd -  Signal Handler for Ctrl+C
 * @num: Reset handler to catch SIGINT next time.
 * Return: 0
 */
void shortcut_cmd(int num)
{
	(void)num;
	signal(SIGINT, shortcut_cmd);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
