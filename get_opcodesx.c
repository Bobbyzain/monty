#include "monty.h"

/**
 * get_opcodesx - selects the correct opcode to perform
 *
 * @opcd: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodesx(char *opcd))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push_L},
		{"pall", _pall_L},
		{"pint", _pint_L},
		{"pop", _pops},
		{"swap", _swap_L},
		{"queue", _queuer},
		{"stack", _stackr},
		{"add", _adds},
		{"nop", _nops},
		{"sub", _subs},
		{"mul", _mul},
		{"div", _divs},
		{"mod", _mods},
		{"pchar", _pchars},
		{"pstr", _pstrs},
		{"rotl", _rots_L},
		{"rotr", _rots_rv},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opcd) == 0)
			break;
	}

	return (instruct[i].f);
}
