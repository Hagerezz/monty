#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @ stack: double pointer
 * @line_number: integar
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *last;
	(void)line_number;

	while (first->next != NULL)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *stack;
	*stack = first;
}
