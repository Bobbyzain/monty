#include "monty.h"

/**
 * _mods - computes the rest of the div. of the 2nd element
 * by the top element
 * @headL: the head of the linked list
 * @line_num: line number;
 * Return: no return
 * info: Result stored in 2nd value node from the top
 * and top value removed.
 */

void _mods(stack_t **headL, unsigned int line_num)
{
	int m = 0;
	stack_t *store = NULL;

	store = *headL;

	for (; store != NULL; store = store->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	if ((*headL)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	store = (*headL)->next;
	store->n %= (*headL)->n;
	_pops(headL, line_num);
}
/**
 * _pstrs - to print the str of the stack
 *
 * @headL: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _pstrs(stack_t **headL, unsigned int line_num)
{
	stack_t *store;
	(void)line_num;

	store = *headL;

	while (store && store->n > 0 && store->n < 128)
	{
		printf("%c", store->n);
		store = store->next;
	}

	printf("\n");
}
/**
 * _pchars - print the char value of the first element
 *
 * @headL: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _pchars(stack_t **headL, unsigned int line_num)
{
	if (headL == NULL || *headL == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	if ((*headL)->n < 0 || (*headL)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*headL)->n);
}
