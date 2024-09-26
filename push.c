#include "monty.h"
/**
 * f_push - function that add a node to the stack
 * @head: head
 * @counter: line of the number
 * Return: nothing
*/
void f_push(stack_t **head, unsigned int counter)
{
	int s;
	int r = 0;
	int f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			r++;
		for (; bus.arg[r] != '\0'; r++)
		{
			if (bus.arg[r] > 57 || bus.arg[r] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	s = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
