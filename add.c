#include "monty.h"

/**
 * add - add the top two element
 * @stack: the stack
 * @line_number: the line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first->next->n = first->next->n + first->n;
	*stack = first->next;
	free(first);
}
