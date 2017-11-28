/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 04:20:12 by lmenigau          #+#    #+#             */
/*   Updated: 2017/11/28 05:38:54 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"rt.h"

t_vec3		vec3(float x, float y, float z)
{
	return ((t_vec3){x, y, z})
}

float		dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3		cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x});
}

float		norm(t_vec3 v)
{
	return (sqrt(dot(v, v)));
}

t_vec3		mult(t_vec3 v, float n)
{
	return ((t_vec3){v.x * n, v.y * n, v.z * n});
}

t_vec3		add(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vec3		sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vec3		normalize(t_vec3	v)
{
	return (mult(v, 1f / norm(v));
}
