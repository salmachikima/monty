#include "monty.h"

/**
 * print_char - function that prints the ascii value
 * @line_number: the same line number
 * @stack: Pointer as mentionned earlier
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		string_err(10, line_number);
	printf("%c\n", asci);
}

/**
 * print_str - function that prints a str
 * @stack: that pointer again
 * @ln: that line number
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;
	int asci;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		asci = tmp->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - it Rotates the 1st node to the bottom
 * @ln: Interger line number
 * @stack: Pointer as mentioned earlier
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - function that Rotates the last node to the top
 * @ln: Interger as mentionned earlier
 * @stack: Pointer as mentioned earlier
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
