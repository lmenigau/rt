/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:12:40 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 01:01:59 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_INTERFACE_H
# define INPUT_INTERFACE_H

# include <stdint.h>
# include "SDL.h"
# include "libft.h"

# define INPUT_BLOCK	(sizeof(t_input_function) * 320)

/*
** v2 should include faster finding of bind
*/

typedef void			(*t_input_function)(SDL_Event);

typedef struct			s_input_code
{
	uint64_t			code_1;
	uint64_t			code_2;
	uint64_t			code_3;
	uint64_t			code_4;
	uint64_t			code_5;
}						t_input_code;

typedef struct			s_input
{
	t_input_code		code;
	t_input_function	function;
	struct s_input		*next;
}						t_input;

typedef struct			s_input_interface
{
	t_input				*inputs;
	t_mem_block			*memblock;
	uint32_t			input_number;
	t_input_code		actual_inputs;
}						t_input_interface;

t_input_interface		*get_inputs(void);

void					bind_input_code(t_input_code c, t_input_function *f);
void					unbind_input_code(t_input_code c);

uint32_t				start_input_interface(void);
void					scan_inputs(void);

t_input_code			add_input_code(t_input_code, uint32_t scan_code);
t_input_code			del_input_code(t_input_code, uint32_t scan_code);
t_input_code			toggle_input_code(t_input_code, uint32_t scan_code);

#endif
