#include "monty.h"

/**
 * op_push - Entry point
 *
 * Description: Adds an element to the top of a stack
 * @stack: Address of the stack element to be added
 * @line_number: The line of the opcode being executed
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new;

	if (is_valid_int(op.arg) == 0)
	{
		fprint(stderr, "L%u: usage: push integer\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}
	num = atoi(op.arg);

	/* add num to beginning of stack */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_op();
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
