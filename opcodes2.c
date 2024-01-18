#include "monty.h"
void swap(stack_t **stack, unsigned int line_number)
{
    char *c_num1 = malloc(10);
    
    pop(stack, line_number);
    sprintf(c_num1, "%d", g.ndata);
    g.data = c_num1;
    pop(stack, line_number);
    
    push(stack, line_number);
    sprintf(c_num1, "%d", g.ndata);
    g.data = c_num1;
    push(stack, line_number);
    
    free(g.data);
    g.data = NULL;
}
void add(stack_t **stack, unsigned int line_number)
{
    stack++;
    line_number++;
}
void nop(stack_t **stack, unsigned int line_number)
{
    stack += 0;
    line_number += 0;
}
