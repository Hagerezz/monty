#include "monty.h"

/**
 * main - read the line
 * @argc: integer
 * @argv: pointer to an array
 */

int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen("argv[1]", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (nread > 0)
	{
		nread = getline(&line, &len, stdin);
		if (nread > 0)
		{
			//operation
		}
	}
}
