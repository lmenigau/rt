/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 03:28:59 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/21 04:14:21 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

NORETURN			leave(char *str)
{
	if (str)
		ft_putstr(str);
	ft_putstr(STR_INFO("Extiting "TITLE"...\n"));
	exit(EXIT_SUCCESS);
}
