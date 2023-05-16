#include "shell.h"
/**
 * _calloc - function used to allocate memory for arrays, using malloc
 * @num: number of elements
 * @size: Bytes of elements
 *
 * Return: 0 if NULL or 0 else pointer to the memory
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

	if(ptr)
	{
		str = (char *)ptr;
		for (i = 0; i < range; i++)
			str[i] = 0;
		return (ptr);
	}
	else
	{
		return (NULL);
	}
}

/**
 * _realloc - function that reallocate memory block
 * @ptr: pointer to previously allocated memory
 * @old_size: size of ptr
 * @new_size: new size
 *
 * Return: NULL or ptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		ptr = malloc(new_size);

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}
