#include "monty.h"

/**
 * push - push the element to the stack
 * @stack: the stack
 * @line_number: the line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, i = 1;
	char *arg = strtok(NULL, " \n\t\r");
	stack_t *new_node;

	if (!arg || (!isdigit(*arg) && *arg != '-' && *arg != '+'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (arg[i] != '\0')
	{
		if (arg[i] > '9' || arg[i] < '0')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	new_node->n = n;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
