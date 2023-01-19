#include "monty.h"

/**
 * op_pop - Entry point
 *
 * Description: Removes the top element of the stack
 * @stack: pointer to the pointer to the first element
 * @line_number: line number of instruction
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	if (*stack)
		(*stack)->prev = NULL;
}
