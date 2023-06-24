#include "monty.h"

/**
 * swap - to extchange between two elements
 * @stack: stack number
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second;
	stack_t *third;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*stack = second;
}
