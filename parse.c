#include "monty.h"
/**
 *parse_line - will devide opcode into intruction and arg
 *@line: the line of str from the monty file
 *
 *Return: nothing
 */
void parse_line(char *line)
{
	char *opname = NULL;
	char *opdata = NULL;

	opname = strtok(line, " \n");
	g.opname = opname;
	if (opname != NULL)
	{	opdata = strtok(NULL, " \n");
		g.data = opdata;
	}
	else
		g.data = NULL;	
}

