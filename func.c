#include "shell.h"

/**
 * _strlen - return lent of a string
 * @s: string to check
 *
 * Return: the lenght of the string
 */

int _strlen(char *s)
{
	int a = 0;

	while (s[a] != '\0')
	{
		a++;
	}

	return (a);
}

/**
 * _strcmp - compare two string
 * @s1: string to be compared
 * @s2: string to be compared
 *
 * Return: -1 if s1 > s2 else 0 if s1 == s2 and 1 if s2 > s1
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _atoi - convert string to integers
 * @s: string to be converted
 *
 * Return: int converted form string
 */

int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}
/**
 * _itoa - prints integeratoi reverse
 * @value: int number
 * @str: string value
 * @base: number base
 * Return: 0
 */
void _itoa(int value, char *str, int base)
{
	static const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int i = 0;

	if (value < 0 && base == 10)
	{
		*str++ = '-';
		value = -value;
	}

	do {
		str[i++] = charset[value % base];
		value /= base;
	} while (value != 0);

	str[i] = '\0';

	rev_string(str);
}

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	char tmp;
	int i, len, len1;

	len = 0;
	len1 = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	len1 = len - 1;

	for (i = 0; i < len / 2; i++)
	{
		tmp = s[i];
		s[i] = s[len1];
		s[len1--] = tmp;
	}
}
