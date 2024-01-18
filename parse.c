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

	opname = strtok(line, " \n\t");
	g.opname = opname;
	if (opname != NULL)
	{	opdata = strtok(NULL, " \n\t");
		g.data = opdata;
	}
	else
		g.data = NULL;	
}

void delete_all(stack_t **head)
{
	stack_t *temp = *head;
    stack_t *next = NULL;

	free(g.data);
    if (temp != NULL)
         next = temp->next;
	else
		return;
    while (next != NULL)
    {
        free(temp);
        temp = next;
        next = temp->next;
    }
    free(temp);
}
