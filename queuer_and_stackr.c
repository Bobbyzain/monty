#include "monty.h"

/**
 * _queuer - sets format of data to queue(FIFO/LILO)
 * @headL: head of linked list
 * @line_num: line number
 */
void _queuer(stack_t **headL, unsigned int line_num)
{
	(void)headL;
	(void)line_num;

	glo_var.lifo = 0;
}

/**
 * _stackr - sets format of data to stack (LIFO/FILO)
 * @headL: the linked list head
 * @line_num: the line number
 */
void _stackr(stack_t **headL, unsigned int line_num)
{
	(void)headL;
	(void)line_num;

	glo_var.lifo = 1;
}
