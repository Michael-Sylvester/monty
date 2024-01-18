#include "monty.h"
void swap(stack_t **stack, unsigned int line_number)
{
    char *c_num1 = malloc(10);
    
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        free(c_num1);
        p_exit(swap_error(line_number), 1);
    }
    pop(stack, line_number);
    sprintf(c_num1, "%d", g.ndata);
    g.data = c_num1;
    pop(stack, line_number);
    
    push(stack, line_number);
    free(g.data);
    c_num1 = malloc(10);
    sprintf(c_num1, "%d", g.ndata);
    g.data = c_num1;
    push(stack, line_number);
    free(c_num1);
    
}
void add(stack_t **stack, unsigned int line_number)
{
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        p_exit(add_error(line_number), 1);
    }
    pop(stack, line_number);
    (*stack)->n += g.ndata;
    
}
void nop(stack_t **stack, unsigned int line_number)
{
    stack += 0;
    line_number += 0;
}
