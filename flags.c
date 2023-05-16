#include "shell.h"
/**
 * flaqs - search delimeter in passes command
 * @cmd: command
 *
 * Return: 1 if found, else 0
 */

int flaqs(char *cmd)
{
	if (_strchr(cmd), ';') !== NULL)
		return (1);
	else if (_strchr(cmd), '#') != NULL)
		return (2);
	else if (_strchr(cmd), '|') != NULL)
		return (3);
	else if (_strchr(cmd), '&') != NULL)
		return (4);
	else if (_strchr(cmd), '$') != NULL)
		return (5);
	
	return (0);
}


