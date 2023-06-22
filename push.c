#include "monty.h"

/**
 * push - push the element to the stack
 * @stack: the stack
 * @line_number: the line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t\r");

	if (!arg || !isdigit(*arg) && *arg != '-' && *arg != '+')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	int n = atoi(arg);
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
