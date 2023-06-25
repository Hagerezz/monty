#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer
 * @line_number: integar
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *last;
	(void)line_number;

	if (!first || !first->next)
	{
		return;
	}
	last = first->next;
	while (last->next)
	{
		last = last->next;
	}
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}
