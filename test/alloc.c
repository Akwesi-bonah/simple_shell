#include "shell.h"
/**
 * _calloc - function that allocates memory for array
 * @num: number of element
 * @size: byte of element
 *
 * Return: address of memory
 */

void *_calloc(unsigned int num, unsigned int size)
{
	int i;
	char *str;
	void *ptr = NULL;
	size_t range;

	if (num == 0 || size == 0)
		return (NULL);
	range = num * size;
	ptr = malloc(range);
	if (ptr != NULL)
	{
		str = (char *)ptr;
		for (i = 0; i < range; i++)
			str[i] = 0;
		return (ptr);
	}
	return (ptr);
}
