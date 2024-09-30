#include "monty.h"

/**
 * err - it Prints appropiate error mesgs linked to error code
 * @error_code: error codes are
 * (1) => The user does not give any file or more than one file to the program
 * (2) => The file is not a file that can be opened or red
 * (3) => The file contains an invalid instruction
 * (4) => the program is unable to malloc more memory
 * (5) => the parameter passed to the instruction "push" is not an int
 * (6) => When stack is empty for pint
 * (7) => When stack is empty for pop
 * (8) => When stack is short for operation
 */
void err(int error_code, ...)
{
	char *op;
	va_list ag;
	int lnum;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			lnum = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - it handles more errors
 * @error_code: error codes are
 * (6) => stack is empty for pint
 * (7) => stack is empty for pop
 * (8) => stack is short for operation
 * (9) => Div by 0
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int lnum;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			lnum = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lnum, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - for errors handle
 * @error_code: error codes are
 * (10) ~> num inside the node is outside ASCII bounds
 * (11) ~> empty stack
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int lnum;

	va_start(ag, error_code);
	lnum = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lnum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lnum);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
