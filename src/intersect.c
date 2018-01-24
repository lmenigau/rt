/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:38:09 by lmenigau          #+#    #+#             */
/*   Updated: 2018/01/24 05:18:47 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"rt.h"

typedef struct		s_ray
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			t;
}					t_ray;

typedef struct		s_sphere
{
	t_vec3			pos;
	t_vec_type		radius;
	t_vec_type		radius2;
}					t_sphere;

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
			q = - 0.5 * (b + sqrt(discr));
		else
			q = - 0.5 * (b - sqrt(discr));
		*x0 = q / a;
		*x1 = c / q;
	}
	if (*x0 > *x1)
		ft_swap(x0, x1);
	return (1);
}

int			intersect(t_ray ray, t_sphere sphere)
{
	float	a, b, c, x0, x1;
	t_vec3 	l;

	l = sub3(ray.pos, sphere.pos);
	a = dot3(ray.dir, ray.dir);
	b = 2 * dot3(ray.dir, l);
	c = dot3(l, l) - sphere.radius2;
	quad_solver(a, b, c, &x0, &x1);
	printf("%f, %f\n", x0, x1);
}

int		main()
{
	t_ray 		ray;
	t_sphere 	sphere;
	intersect(ray, sphere);
}
