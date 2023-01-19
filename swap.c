#include "monty.h"

/**
 * op_swap - Entry point
 *
 * Description: Swaps the top two elements of the stack
 * @stack: pointer to the pointer to the first element
 * @line_number: line number of the instruction
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
