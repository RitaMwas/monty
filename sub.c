#include "monty.h"

/**
 * op_sub - Entry point
 *
 * Description: Subtracts the top element from
 * second top element
 * @stack: pointer to pointer to first element
 * @line_number: line number of the instruction
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	op_pop(stack, line_number);
}
