#include "monty.h"

/**
 * op_pint - Entry point
 *
 * Description: Prints the alue at the top of the stack
 * @stack: pointer to the pointer to the first element
 * @line_number: line number of the instruction
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
