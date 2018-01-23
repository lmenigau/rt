/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 04:20:12 by lmenigau          #+#    #+#             */
/*   Updated: 2018/01/22 21:50:45 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdint.h>
#include	<math.h>
#include	"rt.h"

t_vec2		vec2(t_vec_type x, t_vec_type y)
{
	return ((t_vec2){x, y});
}

t_vec3		vec3(t_vec_type x, t_vec_type y, t_vec_type z)
{
	return ((t_vec3){x, y, z});
}

t_vec4		vec4(t_vec_type w, t_vec_type x, t_vec_type y, t_vec_type z)
{
	return ((t_vec4){w, x, y, z});
}

t_vec_type	dot3(t_vec3 a, t_vec3 b)
{
	return ((t_vec_type)(a.x * b.x + a.y * b.y + a.z * b.z));
}

t_vec3		cross3(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x});
}

t_vec_type	mag3(t_vec3 v)
{
	return ((t_vec_type)sqrt((double)dot3(v, v)));
}

t_vec3		scal3(t_vec3 v, t_vec_type n)
{
	return ((t_vec3){v.x * n, v.y * n, v.z * n});
}

t_vec3		add3(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vec3		sub3(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vec3		norm3(t_vec3 v)
{
	return (scal3(v, 1.0f / mag3(v)));
}

/*t_vec3		rotate_quaternion(t_vec3 target, t_vec3 source)*/
/*{*/
	
/*}*/
