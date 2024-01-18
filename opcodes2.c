#include "monty.h"
/**
 *swap - swaps position of 1st 2 nodes
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
    char *c_num1 = malloc(10);
    /*JUst realized i could have swaped their n values and be done with it*/
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        free(c_num1);
        p_exit(two_node_error(line_number), 1);
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
/**
 *add - adds the top 2 nodes and saves it in the 2nd
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        p_exit(two_node_error(line_number), 1);
    }
    pop(stack, line_number);
    (*stack)->n += g.ndata;
    
}
/**
 *sub - subtracts the top 2 nodes and saves it in the 2nd
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        p_exit(two_node_error(line_number), 1);
    }
    pop(stack, line_number);
    (*stack)->n -= g.ndata;
    
}

/**
 *divide - subtracts the top 2 nodes and saves it in the 2nd
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        p_exit(div_error(line_number, 0), 1);
    }
    else if ((*stack)->n == 0)
    {
        delete_all(stack);
        p_exit(div_error(line_number, 1), 1);
    }
    pop(stack, line_number);
    (*stack)->n /= g.ndata;
    
}

/**
 *mul - subtracts the top 2 nodes and saves it in the 2nd
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        p_exit(two_node_error(line_number), 1);
    }
    pop(stack, line_number);
    (*stack)->n *= g.ndata;
    
}

/**
 *mod - subtracts the top 2 nodes and saves it in the 2nd
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
    if ( *stack == NULL || (*stack)->next == NULL)
	{
		delete_all(stack);
        p_exit(two_node_error(line_number), 1);
    }
    pop(stack, line_number);
    (*stack)->n %= g.ndata;
    
}
