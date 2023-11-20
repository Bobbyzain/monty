#include "monty.h"

/**
 *add_a_nodeint_end - add a node at the end of the doubly link list
 *@headL: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_a_nodeint_end(stack_t **headL, const int n)
{
	stack_t *temp, *store;

	if (headL == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*headL == NULL)
	{
		temp->next = *headL;
		temp->prev = NULL;
		*headL = temp;
		return (*headL);
	}
	store = *headL;
	while (store->next)
		store = store->next;
	temp->next = store->next;
	temp->prev = store;
	store->next = temp;
	return (store->next);
}

/**
 *add_a_nodeint - add a node at the begining of the doubly link list
 *@headL: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_a_nodeint(stack_t **headL, const int n)
{
	stack_t *temp;

	if (headL == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*headL == NULL)
	{
		temp->next = *headL;
		temp->prev = NULL;
		*headL = temp;
		return (*headL);
	}
	(*headL)->prev = temp;
	temp->next = (*headL);
	temp->prev = NULL;
	*headL = temp;
	return (*headL);
}

/**
 * free_a_listint - frees the doubly linked list
 *
 * @headL: head of the list
 * Return: no return
 */
void free_a_listint(stack_t *headL)
{
	stack_t *tmp;

	while ((tmp = headL) != NULL)
	{
		headL = headL->next;
		free(tmp);
	}
}
