#include "monty.h"
/**
 *p_exit - Printd exit message to std err and exits
 *@error_str: the error string to be printed
 *@freecheck: 1 if error_str needs to be freed 0 if not
 *Return: nothing
 */
void p_exit(char *error_str, int freecheck)
{
	if (error_str != NULL)
		fprintf(stderr, "%s", error_str);
	if (freecheck == 1)
		free(error_str);
	exit(EXIT_FAILURE);
}

/**
 *instruct_error_msg - fiting together the error message for each opcode
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *instruct_error_msg(int line_number)
{
	char *msg = NULL;
	int oplen = (g.opname == NULL ? 0 : strlen(g.opname));
	int msglen = strlen("L: unknown instruction ");

	msg = malloc(sizeof(int) + oplen + msglen + 1);
	sprintf(msg, "L%d: unknown instruction %s\n", line_number, g.opname);

	return (msg);
}

/**
 *push_error - error message for wrong syntax push
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *push_error(int line_number)
{
	char *msg = NULL;
	int msglen = strlen("L: usage: push integer\n");

	msg = malloc(msglen + sizeof(int) + 1);
	sprintf(msg, "L%d: usage: push integer\n", line_number);
	return(msg);
}
/**
 *empty_stack_error - error message for wrong syntax pint
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *empty_stack_error(int line_number)
{
	char *msg = NULL;
	int msglen = strlen("L: can't pint, stack empty\n");

	msg = malloc(msglen + sizeof(int) + 1);
	sprintf(msg, "L%d: can't %s, stack empty\n", line_number, g.opname);
	return(msg);
}

/**
 *pop_error - error message for wrong syntax pop
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *pop_error(int line_number)
{
	char *msg = NULL;
	int msglen = strlen("L: can't pop an empty stack\n");

	msg = malloc(msglen + sizeof(int) + 1);
	sprintf(msg, "L%d: can't pop an empty stack\n", line_number);
	return(msg);
}

/**
 *two_node_error - error message for less than 2 nodes in stack
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *two_node_error(int line_number)
{
	char *msg = NULL;
	int msglen = strlen("L: can't swap, stack too short\n");

	msg = malloc(msglen + sizeof(int) + 1);
	sprintf(msg, "L%d: can't %s, stack too short\n", line_number, g.opname);
	return(msg);
}

/**
 *div_error - error message for less than 2 nodes in stack or first node is 0
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *div_error(int line_number, int zero_error)
{
	char *msg = NULL;
	int msglen = strlen("L: can't div, stack too short\n");
		
	msg = malloc(msglen + sizeof(int) + 1);
	if (zero_error == 0)
		sprintf(msg, "L%d: can't %s, stack too short\n", line_number, g.opname);
	else
		sprintf(msg, "L%d: division by zero\n", line_number);
	return(msg);
}

/**
 *out_range_error - error message for less than 2 nodes in stack
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *out_range_error(int line_number)
{
	char *msg = NULL;
	int msglen = strlen("L: can't pchar, value out of range\n");

	msg = malloc(msglen + sizeof(int) + 1);
	sprintf(msg, "L%d: can't %s, value out of range\n", line_number, g.opname);
	return(msg);
}