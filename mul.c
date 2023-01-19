#include "monty.h"

/**
 * op_mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	op_pop(stack, line_number);
}
