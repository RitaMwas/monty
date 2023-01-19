#include "monty.h"

/*
 * pall - Entry point
 *
 * Description: Prints out all the values of the stack
 * @stack: Address of the stack to print
 * @line_numebr: Line number of the opcode being executed
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int counter = 0;
	(void) line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		counter++;
		tmp = tmp->next;
	}
}
