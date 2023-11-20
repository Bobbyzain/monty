#ifndef MONTY_H
#define MONTY_H


#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

/* INCLUDED HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* DATA TYPES */
/* Data Structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct vari_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through our program
 */
typedef struct vari_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  vari_t;
extern vari_t vari;

/**
 * struct globally - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globally
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} globally_t;

extern globally_t glo_var;


/* PROTOTYPES */
/* opcodes1.c */
void _adds(stack_t **headL, unsigned int line_num);
void _nops(stack_t **headL, unsigned int line_num);
void _subs(stack_t **head, unsigned int line_num);
void _divs(stack_t **headL, unsigned int line_num);
void _mul(stack_t **head, unsigned int line_num);

/* opcodes2.c */
void _pstrs(stack_t **headL, unsigned int line_num);
void _mods(stack_t **headL, unsigned int line_num);
void _pchars(stack_t **headL, unsigned int line_num);

/* opcodes3.c */
void _rots_rv(stack_t **headL, unsigned int line_num);
void _rots_L(stack_t **headL, unsigned int line_num);

/* opcodesx.c */
void _swap_L(stack_t **headL, unsigned int line_num);
void _pops(stack_t **headL, unsigned int line_num);
void _pint_L(stack_t **headL, unsigned int line_num);
void _pall_L(stack_t **headL, unsigned int line_num);
void _push_L(stack_t **headL, unsigned int line_num);

/* queuer_and_stackr */
void _queuer(stack_t **headL, unsigned int line_num);
void _stackr(stack_t **headL, unsigned int line_num);

/* my_mallocs.c */
int _strcmp(char *string1, char *string2);
int _sch_char(char *str, char c);
char *_strtoker(char *str, char *delim);

/* main.c */
int main(int argc, char *argv[]);
FILE *checks_input(int argc, char *argv[]);
void free_glo_var(void);
void start_glo_var(FILE *fd);

/* doubly_linked_lists_funcs.c */
void free_a_listint(stack_t *headL);
stack_t *add_a_nodeint(stack_t **headL, const int n);
stack_t *add_a_nodeint_end(stack_t **headL, const int n);

void (*get_opcodesx(char *opcd))(stack_t **stack, unsigned int line_number);
void (*f)(stack_t **stack, unsigned int line_number);
#endif
