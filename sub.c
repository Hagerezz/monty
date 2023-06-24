#include "monty.h"
/**
 * sub - substract the top element from the second
 * @stack: double pointer
 * @line_number: integar
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first->next->n = first->next->n - first->n;
	*stack = first->next;
	free(first);
}
