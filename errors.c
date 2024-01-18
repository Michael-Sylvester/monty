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