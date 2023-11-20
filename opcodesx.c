#include "monty.h"
/**
 * _push_L - pushes an element to the stack
 *
 * @headL: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _push_L(stack_t **headL, unsigned int line_num)
{
	int n, y;

	if (!glo_var.arg)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	for (y = 0; glo_var.arg[y] != '\0'; y++)
	{
		if (!isdigit(glo_var.arg[y]) && glo_var.arg[y] != '-')
		{
			dprintf(2, "L%u: ", line_num);
			dprintf(2, "usage: push integer\n");
			free_glo_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glo_var.arg);

	if (glo_var.lifo == 1)
		add_a_nodeint(headL, n);
	else
		add_a_nodeint_end(headL, n);
}

/**
 * _pall_L - prints all values on the stack
 *
 * @headL: head of the linked list
 * @line_num: line numbers
 * Return: no return
 */
void _pall_L(stack_t **headL, unsigned int line_num)
{
	stack_t *store;
	(void)line_num;

	store = *headL;

	while (store)
	{
		printf("%d\n", store->n);
		store = store->next;
	}
}


/**
 * _pint_L - prints the value at the stack top
 *
 * @headL: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _pint_L(stack_t **headL, unsigned int line_num)
{
	(void)line_num;

	if (*headL == NULL)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "can't pint, stack empty\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*headL)->n);
}

/**
 * _pops - to remove the top element of the stack
 *
 * @headL: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _pops(stack_t **headL, unsigned int line_num)
{
	stack_t *store;

	if (headL == NULL || *headL == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	store = *headL;
	*headL = (*headL)->next;
	free(store);
}


/**
 * _swap_L - swaps the top two elements of the stack
 *
 * @headL: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _swap_L(stack_t **headL, unsigned int line_num)
{
	int m = 0;
	stack_t *store = NULL;

	store = *headL;

	for (; store != NULL; store = store->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	store = *headL;
	*headL = (*headL)->next;
	store->next = (*headL)->next;
	store->prev = *headL;
	(*headL)->next = store;
	(*headL)->prev = NULL;
}
