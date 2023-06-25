#include "monty.h"

/**
 * pstr - prints the string starting at the top
 * @stack: double pointer
 * @line_number: integar
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	char a[256];
	int i = 0;
	stack_t *first = *stack;
	(void) line_number;

	if (!first)
	{
		fprintf(stdout, "\n");
	}
	while (first)
	{
		if (first->n <= 0 || first->n > 127)
			break;
		a[i++] = first->n;
		first = first->next;
	}
	fprintf(stdout, "%s\n", a);
}
