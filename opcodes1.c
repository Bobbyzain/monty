#include "monty.h"

/**
 * _adds - to add the two values at the top of a stack_t linked list.
 * @headL: head of the linked list
 * @line_num: the line number
 * Description: Result stored in the 2nd value node
 * from the top and the top value is removed.
 */
void _adds(stack_t **headL, unsigned int line_num)
{
	int m = 0;
	stack_t *store = NULL;

	store = *headL;

	for (; store != NULL; store = store->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	store = (*headL)->next;
	store->n += (*headL)->n;
	_pops(headL, line_num);
}

/**
 * _nops - does not do anything
 * @headL: the head of the linked list
 * @line_num: the line number
 */
void _nops(stack_t **headL, unsigned int line_num)
{
	(void)headL;
	(void)line_num;
}
/**
 * _subs - Subtracts 2nd value from the top
 * of stack_t linked list by top value.
 * @head: the head node
 * @line_num: the line number
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */

void _subs(stack_t **head, unsigned int line_num)
{
	int m = 0;
	stack_t *cur_rent;

	cur_rent = *head;

	for (; cur_rent != NULL; cur_rent = cur_rent->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	cur_rent = (*head)->next;
	cur_rent->n -= (*head)->n;
	_pops(head, line_num);
}

/**
 *_divs -Divides 2nd value from the top of stack_t linkedlist by the top value.
 * @headL: head of the linked list
 * @line_num: line number;
 * Return: no return
 */

void _divs(stack_t **headL, unsigned int line_num)
{
	int m = 0;
	stack_t *store = NULL;

	store = *headL;

	for (; store != NULL; store = store->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
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
	store->n /= (*headL)->n;
	_pops(headL, line_num);
}

/**
 *_mul - to multiply d 2nd value from the top of linked list by top value.
 * @head: the head node
 * @line_num: the line number
 * info: Result is stored in the 2nd value node
 * from the top and top value removed.
 */

void _mul(stack_t **head, unsigned int line_num)
{
	int m = 0;
	stack_t *cur_rent;

	cur_rent = *head;

	for (; cur_rent != NULL; cur_rent = cur_rent->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	cur_rent = (*head)->next;
	cur_rent->n *= (*head)->n;
	_pops(head, line_num);
}
