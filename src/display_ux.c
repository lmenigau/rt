/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:00:40 by lmenigau          #+#    #+#             */
/*   Updated: 2018/01/25 07:41:55 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "intersect.h"

void	display_ux(t_context *ctx)
{
	float	x, y,ratio, scale;
	t_vec3	dir;

	y = 0;
	ratio = WIDTH / (float)HEIGHT;
	scale = tanf((float)M_PI / 8);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH )
		{
			dir.x = (2 * ((x + 0.5f) / WIDTH) - 1) * ratio * scale;
			dir.y = (1 - 2 * (y + 0.5f) / HEIGHT) * scale;
			dir.z = -1;
			x++;
		}
		y++;
	}
}
