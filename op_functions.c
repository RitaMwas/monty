#include "monty"

/**
 * op_pchar - Entry point
 *
 * Description: Prints the char at the top of the stack
 * @stack: pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprinf(stderr, "L%u: Can't pchar, stack empty\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * op_pstr - Entry point
 *
 * Description: Prints the string starting at the top of the stack
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *arr = *stack;

	while (arr && (arr->n > 0 && arr->n < 128))
	{
		printf("%c", arr->n);
		arr = arr->next;
	}

	printf("\n");
	(void)line_number;
}
