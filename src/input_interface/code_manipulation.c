/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:16:13 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 02:03:35 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_interface.h"

t_input_code		add_input_code(t_input_code code, uint32_t scan_code)
{
	if (scan_code > 64U)
		if (scan_code > 128U)
			if (scan_code > 192U)
				if (scan_code > 256U)
					code.code_5 |= 1 << (scan_code - 256U);
				else
					code.code_4 |= 1 << (scan_code - 192U);
			else
				code.code_3 |= 1 << (scan_code - 128U);
		else
			code.code_2 |= 1 << (scan_code - 64U);
	else
		code.code_1 |= 1 << scan_code;
	return (code);
}

t_input_code		del_input_code(t_input_code code, uint32_t scan_code)
{
	if (scan_code > 64U)
		if (scan_code > 128U)
			if (scan_code > 192U)
				if (scan_code > 256U)
					code.code_5 &= ~(1 << (scan_code - 256U));
				else
					code.code_4 &= ~(1 << (scan_code - 192U));
			else
				code.code_3 &= ~(1 << (scan_code - 128U));
		else
			code.code_2 &= ~(1 << (scan_code - 64U));
	else
		code.code_1 &= ~(1 << scan_code);
	return (code);
}

t_input_code		toggle_input_code(t_input_code code, uint32_t scan_code)
{
	if (scan_code > 64U)
		if (scan_code > 128U)
			if (scan_code > 192U)
				if (scan_code > 256U)
					code.code_5 ^= 1 << (scan_code - 256U);
				else
					code.code_4 ^= 1 << (scan_code - 192U);
			else
				code.code_3 ^= 1 << (scan_code - 128U);
		else
			code.code_2 ^= 1 << (scan_code - 64U);
	else
		code.code_1 ^= 1 << scan_code;
	return (code);
}
