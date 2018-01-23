/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_binding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:23:40 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 00:56:46 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_interface.h"

void						bind_input_code(t_input_code c
		, t_input_function *f)
{
	t_input					*i;
	t_input					*j;

	i = get_inputs()->inputs;
	while (i)
	{
		if (ft_memcmp(&(i->code), &c, sizeof(c)) == 0)
		{
			i->function = f;
			return ;
		}
		i = i->next;
	}
	if (!i)
		get_inputs()->inputs = (t_input*)push_to_mem_block((get_inputs())->memblock
			, &((t_input){c, f, NULL}), sizeof(t_input));
	else
		i->next = (t_input*)push_to_mem_block((get_inputs())->memblock
			, &((t_input){c, f, NULL}), sizeof(t_input));
	(get_inputs()->input_number)++;
}

void						unbind_input_code(t_input_code c)
{
	t_input					*i;
	t_input					*j;

	i = (get_inputs())->inputs;
	j = NULL;
	while (i)
	{
		if (ft_memcmp(&(i->code), &c, sizeof(c)) == 0)
			j->next = i->next;
		j = i;
		i = i->next;
	}
}
