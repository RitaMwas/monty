#include "monty.h"

/**
 * op_add - Entry point
 *
 * Description: Adds the top two elements of the stack
 * @stack: pointer to the pointer to the first element
 * @line_number: line number of the instrucion
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	op_pop(stack, line_number);
}
