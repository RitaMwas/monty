#include "monty.h"

op_t op = {NULL, NULL, NULL, NULL};

/**
 * main - Entry point
 *
 * Description: Monty script interpreter
 * @argc: Argument count
 * @argv: Arguments array
 * Return: EXIT_SUCCESS  on success. EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	/* check usage */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open gien file */
	op.input = fopen(argv[1], "r");
	if (op.input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty();

	free_op();
	return (EXIT_SUCCESS);
}
