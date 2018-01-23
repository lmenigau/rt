/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 01:03:06 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 01:55:57 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_interface.h"

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

void						scan_inputs(void)
{
	SDL_Event				e;
	t_input_interface		*i;
	t_input					*input;

	i = get_inputs();
	if (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
			i->actual_inputs = toggle_input_code(i->actual_inputs
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
