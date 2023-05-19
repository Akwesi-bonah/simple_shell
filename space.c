#include "shell.h"
/**
 * split_space - remoce each space
 * @argv: array to save
 * @line2: name of file command complete
 * Return: 0
 */
void _split_space(char *argv[], char line2[])
{
        char *ptr;
        int i = 0;

        ptr = strtok(line2, " ");
	while (ptr)
        {
                argv[i] = ptr;
                ptr = strtok(NULL, " ");
                i++;
        }
        argv[i] = NULL;
}
/**
 * split - cut each delimiter
 * @line2: command
 * @scmd: array save cut
 * @c: delimiter
 * Return: 0
 */
void _split(char line2[], char *scmd[], char c[])
{
	char *ptr;
        int i = 0;

        ptr = strtok(line2, c);
        while (ptr)
        {
                scmd[i] = ptr;
                ptr = strtok(NULL, c);
                i++;
        }
}
