/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:33:44 by lmenigau          #+#    #+#             */
/*   Updated: 2017/12/08 03:05:36 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <math.h>
# include "openCL/opencl.h"
# include <SDL.h>
# include <SDL_events.h>
#define WIDTH	1920
#define HEIGHT	1080


typedef	struct		s_vec3
{
	float		x;
	float		y;
	float		z;
}					t_vec3;

typedef	struct		s_mat3
{
	t_vec3		ux;
	t_vec3		uy;
	t_vec3		uz;
}					t_mat3;

typedef	enum	e_objt
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}				t_objt;

typedef	struct		s_obj
{

	t_vec3		pos;
	t_vec3		dir;
	float		value;
	t_objt		type;
}					t_obj;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32				*pixels;
}					t_sdl;

typedef struct		s_rt
{
	t_sdl			sdl;
	t_obj			obj;
}					t_rt;

void		log_error(t_rt *env);
void		init_sdl(char *name, t_rt *env);
void		event_loop(t_rt *rt);
void		sdl_cleanup(t_sdl	*sdl);
void		cleanup(t_rt	*env);
#endif
