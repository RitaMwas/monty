#include "monty.h"

/**
 * op_div - Entry point
 *
 * Description: Divides the second top element by
 * the top element
 * @stack: stack head
 * @line_number: line number of instruction
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	op_pop(stack, line_number);
}
