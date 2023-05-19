#include "shell.h"
/**
 * scmd - execute two command
 * @c: command complete
 * @d: directory path
 * @cnt: number of commands
 * @v: command
 * @err: error of the command
 * @name: name of the exe
 * Return: 0
 */

int scmd(char c[], char *d[], int cnt, char *v, char *err, char *name)
{
        int x = 0, a = 0, b = 0, ex = 0, status = 0;
        char *dpcmd, *e1, *e2;
        char *pp[2], **args1 = NULL, **args2 = NULL;
        pid_t p2, wp;
        (void)wp;

        _split(c, pp, ";");
        a = _strlen(pp[0]), b = _strlen(pp[1]);
        e1 = _calloc(a, sizeof(char)), e2 = _calloc(b, sizeof(char));

        _strcpy(e1, pp[0]), _strcpy(e2, pp[1]);
        x = (count(e1, ' ')) + 2, args1 = _calloc(x, sizeof(char *));
        _split_space(args1, e1), dpcmd = check_path(d, args1[0]);
        if (dpcmd == NULL)
                print_error(cnt, v, err, name);
        else
                p2 = fork();
        if (!p2)
        {
                if (execve(dpcmd, args1, environ) == -1)
                {
                        print_error(cnt, v, err, name);
                        return (0);
                }
                exit(EXIT_FAILURE);
        }
	else if (p2 < 0)
        {
                print_error(cnt, v, err, name);
                return (0);
        }
        else
        {
                do {
                        wp = waitpid(p2, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        x = (count(e2, ' ')) + 2;
        args2 = _calloc(x, sizeof(char *));
        _split_space(args2, e2), dpcmd = check_path(d, args2[0]);
        if (dpcmd == NULL)
                print_error(cnt, v, err, name);
        else
                ex = execve(dpcmd, args2, environ);
        return (ex);
}
