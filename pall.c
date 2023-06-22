#include "monty.h"

/**
 * pall - prints al values on the stack from the top of the stack
 * @stack: the stack
 * @line_number: the line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void) line_number;

	while (node)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}
