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

	msg = malloc(msglen + 1);
	sprintf(msg, "L%d: usage: push integer\n", line_number);
	return(msg);
}
/**
 *pint_error - error message for wrong syntax pint
 *@line_number: the line the error was found on
 *
 *Return: the error message
 */
char *pint_error(int line_number)
{
	char *msg = NULL;
	int msglen = strlen("L: can't pint, stack empty\n");

	msg = malloc(msglen + 1);
	sprintf(msg, "L%d: can't pint, stack empty\n", line_number);
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

	msg = malloc(msglen + 1);
	sprintf(msg, "L%d: can't pop an empty stack\n", line_number);
	return(msg);
}

