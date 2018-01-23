/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 01:03:06 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 02:21:29 by mbeilles         ###   ########.fr       */
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
	t_input_interface		*i;
	t_input					*input;

	i = get_inputs();
	if (e.type == SDL_KEYDOWN)
	{
		printf(STR_INFO(C_LGR "Key " C_BLU "▼ " C_MGR "[" C_LGR " %3i " C_MGR "]\n")
				, SDL_GetScancodeFromKey(e.key.keysym.sym));
		i->actual_inputs = add_input_code(i->actual_inputs
				, SDL_GetScancodeFromKey(e.key.keysym.sym));
	}
	if (e.type == SDL_KEYUP)
	{
		printf(STR_INFO(C_LGR "Key " C_RED "▲ " C_MGR "[" C_LGR " %3i " C_MGR "]\n")
				, SDL_GetScancodeFromKey(e.key.keysym.sym));
		i->actual_inputs = del_input_code(i->actual_inputs
				, SDL_GetScancodeFromKey(e.key.keysym.sym));
	}
	input = i->inputs;
	while (input)
	{
		if (!ft_memcmp(&input->code, &i->actual_inputs, sizeof(t_input_code)))
			(input->function)(e);
		input = input->next;
	}
}
