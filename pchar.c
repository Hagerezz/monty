#include "monty.h"
/**
 * pchar - prints the char at the top
 * @stack: double pointer
 * @line_number: integar
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			fprintf(stdout, "%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}
