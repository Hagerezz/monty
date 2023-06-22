#include "monty.h"

/**
 * pop - pop to exit element from stack
 * @stack : stack_t
 * @line_number : number of lines in stacl
 * Return : stack node and empty stck
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *node = *stack;

	*stack = node->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(node);
}
