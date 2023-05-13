#include "shell.h"

int exit_shell(char *line, char *line2, int on, char **args, char *name)
{
        int i, sts;
	int digit = 1;

        if (args[1] == NULL)
        {
                free(line);
                free(line2);
                free(args);
                exit(EXIT_SUCCESS);
        }

        for (i = 0; args[1][i] != '\0'; i++)
        {
                digit = _isdigit(args[1][i]);
                if (digit == 0)
                {
                        break;
                }
        }

        sts = digit ? _atoi(args[1]) : 2;

        if (sts < 0 || sts + 1 > 0 && sts != 2)
        {
                print_error(on, args[0], args[1], name);

                return (2);
        }

        free(line);
        free(args);
        exit(sts);

	if (args[1] == NULL)
	{
		free(line);
		free(line2);
		free(args);
		exit(EXIT_SUCCESS);
	}


}

/**
 * _isdigit - check if a character is between 0 - 9
 *
 * @c: character to check
 * Return: 1 if  then character is  a number else 0
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
