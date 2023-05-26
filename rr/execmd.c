#include "shell.h"
/**
 * execute_cmd - Execute a command
 * @cmd: Command and arguments array
 * @user: User input string
 * @cmt: copy
 * @counter: Command counter
 * @av0: Name of the program
 */
void execute_cmd(char **cmd, char *user, char *cmt, int counter, char *av0)
{
	if (access(cmd[0], X_OK) == 0)
		create_process(user, cmd, cmt, counter, av0);
	else
		run_cmd(cmd, user, counter, cmd[0], cmd[1], av0);
}
