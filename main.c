#include "monty.h"

/**
 *main - Controles all functions calls for interpreter
 *@argv: argument vector
 *@argc: argument count
 *Return: exit success
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[7];
	stack_t *head = NULL;
	FILE *file;
	
	if (argc != 2)
		p_exit("USAGE: monty file\n");
	file = open_file(argv[1]);
	fclose(file);
	return (0);
}

/**
 *p_exit - Printd exit message to std err and exits
 *@error_str: the error string to be printed
 *Return: nothing
 */
void p_exit(char *error_str)
{
	int len = strlen(error_str);

	if (error_str != NULL)
		fprintf(stderr, "%s", error_str);
	exit (EXIT_FAILURE);
}

/**
 *open_file - Printd exit message to std err and exits
 *@filepath: path to the file to be opened
 *@file: the File variable for holding the open file
 *Return: the opened file
 */
FILE *open_file(char *filepath)
{
	char *error_msg = malloc(strlen("Error: Can't open file ") + strlen(filepath) + 2);
	FILE *file = fopen(filepath, "r");

	if (file == NULL)
	{
		if (error_msg == NULL)
			p_exit("Error: malloc failed");
		strcpy(error_msg, "Error: Can't open file ");
		strcat(error_msg, filepath);
		strcat(error_msg, "\n");
		p_exit(error_msg);
	}
	return (file);
}
