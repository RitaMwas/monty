#include "monty.h"

/*
 * op_pall - Entry point
 *
 * Description: Prints out all the values of the stack
 *
 * @stack: Address of the stack to print
 * @line_numebr: Line number of the opcode being executed
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *arr = *stack;

	while (arr)
	{
		printf("%d\n", arr->n);
		arr = arr->next;
	}

	(void)line_number;
}
