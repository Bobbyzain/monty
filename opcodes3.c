#include "monty.h"

/**
 * _rots_L - rotates 1st element to the bottom and 2nd to the top
 * @headL: linked list head
 * @line_num: line nummber
 */
void _rots_L(stack_t **headL, unsigned int line_num)
{
	stack_t *store1 = NULL;
	stack_t *store2 = NULL;
	(void)line_num;

	if (*headL == NULL)
		return;

	if ((*headL)->next == NULL)
		return;

	store1 = (*headL)->next;
	store2 = *headL;

	for (; store2->next != NULL; store2 = store2->next)
		;

	store1->prev = NULL;
	store2->next = *headL;
	(*headL)->next = NULL;
	(*headL)->prev = store2;
	*headL = store1;
}

/**
 * _rots_rv - reverse stack
 * @headL: linked list head
 * @line_num: line number
 */
void _rots_rv(stack_t **headL, unsigned int line_num)
{
	stack_t *store = NULL;
	(void)line_num;

	if (*headL == NULL)
		return;

	if ((*headL)->next == NULL)
		return;

	store = *headL;

	for (; store->next != NULL; store = store->next)
		;

	store->prev->next = NULL;
	store->next = *headL;
	store->prev = NULL;
	(*headL)->prev = store;
	*headL = store;
}

