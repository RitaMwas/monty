#include "monty.h"

/**
 * push - Entry point
 *
 * Description: Adds an element to the top of a stack
 * @stack: Address of the stack element to be added
 * @line_number: The line of the opcode being executed
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int m = 0;

	for (m = 0; push_data[m] != '\0'; m++)
	{
		if (isdigit(push_data[m]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "ERROR: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(push_data);
	new_node->prev = NULL;
	new_node->next = NULL;

	/* In case head is an empty list */
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	/* If head is not an empty list */
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
