/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:38:09 by lmenigau          #+#    #+#             */
/*   Updated: 2018/01/24 04:04:42 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"rt.h"

int		quad_solver(float a, float b, float c, float *x0, float *x1)
{
		float	discr;
		float	q;

		discr = b * b - 4 * a * c;
		if (discr < 0)
			return (0);
		else if (discr == 0)
			*x0 = *x1 = - 0.5 * a * b;
		else
		{
			if (b > 0)
				q =  - 0.5 * (b + sqrt(discr));
			else
				q =  - 0.5 * (b - sqrt(discr));
			*x0 = q / a;
			*x1 = c / q;
		}
		if (*x0 > *x1)
			ft_swap(x0, x1);
		return (1);
}

int			intersect()
{
	float	a, b, c, x0, x1;

	a = b = c = x0 = x1 = 0;

	quad_solver(a, b, c, &x0, &x1);
	printf("%f, %f, x0, x1);
}

int		main()
{
	intersect();
}
