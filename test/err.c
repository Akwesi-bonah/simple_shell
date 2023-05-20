#include "shell.h"
/**
 * print_err - print error
 * @num: number of commnads
 * @cmd: commad
 * @type: type of error
 * @name: name of execution
 */
void print_err(int num, char *cmd, char *type, char *name)
{
	char *msg = NULL, *out;
	int msg_len = 0;

	if (strcmp(cmd, "exit") == 0)
		msg = "Illegal number: ";
	else
		msg = "not found";

	msg_len = snprintf(NULL, 0, "%s: %d: %s%s\n", name, num, cmd, msg);
	if (msg_len < 0)
		return;

	out = malloc(sizeof(char) * msg_len);
	if (out == NULL)
		return;
	snprintf(out, msg_len + 1, "%s: %d: %s%s\n", name, num, cmd, msg);
	write(STDERR_FILENO, out, msg_len);

	free(out);
}
