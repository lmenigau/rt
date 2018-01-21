/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles </var/mail/mbeilles>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 00:54:33 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/21 03:03:03 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

NORETURN			leave(char *str)
{
	if (str)
		ft_putstr(str);
	ft_putstr(STR_INFO("leave"));
	exit(EXIT_SUCCESS);
}
