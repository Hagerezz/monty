#include "monty.h"

/**
 * mod - modules
 * @stack: double pointer
 * @line_number: integar
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (first->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	first->next->n = first->next->n % first->n;
	*stack = first->next;
	free(first);
}
