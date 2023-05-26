#include "shell.h"
/**
 * set_env - Set the value of an environment variable
 * @name: Name of the environment variable
 * @value: Value to set
 * Return: 0 on success, -1 on failure
 */

int set_env(const char *name, const char *value)
{
	if (name == NULL || value == NULL)
		return (-1);
	if (setenv(name, value, 1) != 0)
		return (-1);
	return (0);
}
/**
 * unset_env - Unset an environment variable
 * @name: Name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int unset_env(const char *name)
{
	if (name == NULL)
		return (-1);
	if (unsetenv(name) != 0)
		return (-1);
	return (0);
}
