#include "monty.h"

/**
 * main - read the line
 * @argc: integer
 * @argv: pointer to an array
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	unsigned int count = 0;
	FILE *fp;
	char line[1024];
	size_t len = 1024;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, len, fp) != NULL)
	{
		count++;
		execute(&stack, line, count, fp);
	}
	free(stack);
	fclose(fp);
	return (0);
}
/**
 * execute - execute the code
 * @stack: double pointer
 * @line: pointer
 * @count: counter
 * @fp: file
 * Return: 1 (success);
 */

int execute(stack_t **stack, char *line, unsigned int count, FILE *fp)
{
    unsigned int i = 0;
	char *opcode = strtok(line, " \n\t");
    /*char *args  = strtok(NULL, " \n\t");*/

	if (opcode && opcode[0] == '#')
		return (0);
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{	opcodes[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (opcode && opcodes[i].opcode == NULL)
	{
        fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
		fclose(fp);
		free(line);
		free(stack);
		exit(EXIT_FAILURE); }
	return (1);
}