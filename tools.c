#include "monty.h"

/**
 * open_file - function that opens a file
 * @file_name: file name
 * Return: nothing
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - function that read file
 * @fd: pointer
 * Return: nothing
 */

void read_file(FILE *fd)
{
	char *buffer = NULL;
	int line;
	int f = 0;
	size_t len = 0;

	for (line = 1; getline(&buffer, &len, fd) != -1; line++)
	{
		f = parse_line(buffer, line, f);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens
 * @buffer: the buffer
 * @format:  storage format
 * @line_number: line num
 * Return: Returns 1 if queue, 0 if stack
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func - find function 4 opcode
 * @opcode: opcode
 * @value: arg
 * @format:  storage format
 * @ln: line num
 * Return: nothing
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int s;
	int f;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, s = 0; func_list[s].opcode != NULL; s++)
	{
		if (strcmp(opcode, func_list[s].opcode) == 0)
		{
			call_fun(func_list[s].f, opcode, value, ln, format);
			f = 0;
		}
	}
	if (f == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - it calls the function
 * @func: Pointer
 * @op: string for thre opcode
 * @val: string for a numeric value
 * @ln: line num
 * @format: Format specifier
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int f, s;

	f = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			f = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (s = 0; val[s] != '\0'; s++)
		{
			if (isdigit(val[s]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * f);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
