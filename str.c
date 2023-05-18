#include "shell.h"
/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * exe_c - execute two commads
 * @cpy: commant to be executed
 * @dpt: directory of the path
 * @cnt: number of commands
 * @var: command name
 * @err: error_message
 * @name: name of execution
 *
 * Return: 0:
 */

int exe_c(char cpy[], char *dpth, int cnt, char *var, char err, name)
{
	int x = 0, a = 0, b = 0, xcode, status = 0;
	char *cmdpath. *exec1, *exec2;
	char *cmdpart[], **arg = NULL, args = NULL;
	pid_t pid, wpid;

	split(copy, cmdpart, "|");
	a = _strlen(dpt[0]);
	b = _strlen(dpt[1]);
	exec1 = _calloc(a, sizeof(char));
	exec2 = _calloc(b, sizeof(char));
	_strcpy(exec1, cmdpart[0]);
	_strcpy(exec2, cmdpart[1]);

	x = 

