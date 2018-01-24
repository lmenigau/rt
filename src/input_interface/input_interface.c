/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 01:03:06 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 08:42:59 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_input_interface			*get_inputs(void)
{
	static t_input_interface	inputs = (t_input_interface){NULL, 0, 0
		, (t_input_code){0, 0, 0, 0, 0}};

	return(&inputs);
}

uint32_t					start_input_interface(void)
{
	t_input_interface		*i;

	i = get_inputs();
	if (!(i->memblock = create_mem_block(INPUT_BLOCK)))
		return (1);
	return (0);
}

void						scan_inputs(SDL_Event e)
{
	int						j;
	t_input_interface		*i;
	t_input					*input;

	i = get_inputs();
	if (e.type == SDL_KEYDOWN)
	{
		printf(STR_INFO(C_LGR"Key "C_BLU"▼ "C_MGR"["C_LGR" %s "C_MGR"]-%i\n")
				, SDL_GetKeyName(e.key.keysym.sym), e.key.keysym.scancode);
		i->actual_inputs = add_input_code(i->actual_inputs
				, e.key.keysym.scancode);
	}
	if (e.type == SDL_KEYUP)
	{
		printf(STR_INFO(C_LGR"Key "C_RED"▲ "C_MGR"["C_LGR" %s "C_MGR "]-%i\n")
				, SDL_GetKeyName(e.key.keysym.sym), e.key.keysym.scancode);
		i->actual_inputs = del_input_code(i->actual_inputs
				, e.key.keysym.scancode);
	}
	input = i->inputs;
	j = 0;
	while (input)
	{
		printf("---------------------------------\n");
		printf("CMP %04lli%04llx%04llx%04llx%04llx\n", input->code.code_1, input->code.code_2, input->code.code_3, input->code.code_4, input->code.code_5);
		printf("CMP %04lli%04llx%04llx%04llx%04llx\n", i->actual_inputs.code_1, i->actual_inputs.code_2, i->actual_inputs.code_3, i->actual_inputs.code_4, i->actual_inputs.code_5);
		if (!memcmp(&(input->code), &(i->actual_inputs), sizeof(t_input_code)))
			(input->function)(e);
		input = input->next;
	}
}
