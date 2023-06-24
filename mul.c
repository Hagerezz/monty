#include "monty.h"

/**
 * mul - multiplication
 * @stack: double pointer
 * @line_number: integar
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first->next->n = first-> next->n * first->n;
	*stack = first->next;
	free(first);
}
