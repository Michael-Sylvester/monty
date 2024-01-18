#include "monty.h"

/**
 *push - place a new node at head of the stack
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		delete_all(stack);
		p_exit("Error: malloc failed", 0);
	}
		

	if (g.data != NULL)
		temp->n = atoi(g.data);
	else
	{
		delete_all(stack);
		p_exit(push_error(line_number), 1);
	}
	temp->next = *stack;
	temp->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = temp;
	*stack = temp;

}

/**
 *pall - print all nodes in stack
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

    if (*stack == NULL)
		return;

    printf("%d\n", (*stack)->n);
    temp = (*stack)->next;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
	line_number++;
}

/**
 *pint - print top element
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	char temp[10];

	if (*stack == NULL)
	{
		delete_all(stack);
		p_exit(pint_error(line_number), 1);
	}
	sprintf(temp, "%d", (*stack)->n);
	strcpy(g.data, temp);
	printf("%s\n", g.data);
	line_number++;
}

/**
 *pop - removes the top node of stack
 *@stack: pointer to head  of  stack
 *@line_number: position in file
 *Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		delete_all(stack);
		p_exit(pop_error(line_number), 1);
	}
	g.ndata = (*stack)->n;

	*stack = temp->next;
	free(temp);
	line_number++;
}
