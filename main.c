#include "monty.h"
global_t g;

/**
 *main - Controles all functions calls for interpreter
 *@argv: argument vector
 *@argc: argument count
 *Return: exit success
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[9];
	char line[250];
	int linecount = 0;
	stack_t *head = NULL;
	FILE *file = NULL;

	if (argc != 2)
		p_exit("USAGE: monty file\n", 0);
	initialise_globals();
	file = open_file(argv[1]);
	initialise(opcodes);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		linecount++;
		parse_line(line);
		execute_opcode(linecount, opcodes, &head);
	}
	delete_all(&head);
	fclose(file);
	return (0);
}


/**
 *open_file - Printd exit message to std err and exits
 *@filepath: path to the file to be opened
 *Return: the opened file
 */
FILE *open_file(char *filepath)
{
	int path_len = strlen(filepath);
	int msg_len = strlen("Error: Can't open file ");
	char *error_msg = malloc(msg_len + path_len + 2);
	FILE *file = fopen(filepath, "r");

	if (file == NULL)
	{
		if (error_msg == NULL)
			p_exit("Error: malloc failed", 0);
		strcpy(error_msg, "Error: Can't open file ");
		strcat(error_msg, filepath);
		strcat(error_msg, "\n");
		p_exit(error_msg, 1);
	}
	free(error_msg);
	return (file);
}

void initialise_globals()
{
	g.data = NULL;
	g.opname = NULL;
}

/**
 *initialise - create tstacke functions for eacstack of tstacke opcodes
 *@opcodes: double pointer to array in main
 *Return: notstacking
 */
void initialise(instruction_t *opcodes)
{
	int idx = 0;
	const int no_of_opcodes = 9;
	char *oplist[9] = {"push", "pall", "pint", "pop", "swap", "add", 
	"nop", "sub", "div"};
	void (*opfuncs[9])(stack_t **stack, unsigned int line_number) = {push, 
	pall, pint, pop, swap, add, nop, sub, divide};
	/* 9 opcodes so far */
	for (idx = 0; idx < no_of_opcodes; idx++)
	{
		opcodes[idx].opcode = oplist[idx];
		opcodes[idx].f = opfuncs[idx];
	}
}

/**
 *execute_opcode - will devide opcode into intruction and arg
 *@linecount: the position the opcode was in the file
 *@opcodes: array of all opcode names and functions
 *@stack: double array to head of stack
 *Return: nothing
 */
void execute_opcode(int linecount, instruction_t *opcodes, stack_t **stack)
{
	int idx = 0;
	const int no_of_opcodes = 9;

	if (g.opname != NULL)
	{
		while (idx < no_of_opcodes)
		{
			if (strcmp(g.opname, opcodes[idx].opcode) == 0)
			{
				opcodes[idx].f(stack, linecount);
				break;
			}
			idx++;
		}
		if (idx >= no_of_opcodes)
		{
			delete_all(stack);
			p_exit(instruct_error_msg(linecount), 1);
		}
			
	}
}
