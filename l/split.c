#include "shell.h"
#define BUFFER_SIZE 1024
#define SPARE " \t\r\n\a"

/**
 * split_command - split lines into tokens
 * @line: line to be splited
 *
 * Return: array of tokens
 */

char **split_command(char *line)
{
	int buffer_size = BUFFER_SIZE;
	int i = 0;
	char **tokens = malloc(buffer_size);
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, SPARE);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size);
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, SPARE);
	}
	tokens[i] = NULL;
	return (tokens);
}
