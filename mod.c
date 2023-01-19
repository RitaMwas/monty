#include "monty.h"

/**
 * op_mod - Entry point
 *
 * Description: computes the rest of the division of the second top element
 * by the top element
 * @stack: pointer to the pointer to the first element
 * @line_number: line number of the instruction
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	op_pop(stack, line_number);
}
