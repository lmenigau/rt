/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:01:56 by lmenigau          #+#    #+#             */
/*   Updated: 2018/01/25 07:02:56 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

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


#endif
