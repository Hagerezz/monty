#include "monty.h"

/**
 * swap - to extchange between two elements
 * @stack : stack number
 * @line_number : line number
 *
 * Return :
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		dprintf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *first = *stack;
	stack_t *second = first->next;
	stack_t *third = second->next;

	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*stack = second;
}
