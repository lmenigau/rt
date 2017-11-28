/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:33:44 by lmenigau          #+#    #+#             */
/*   Updated: 2017/11/28 04:31:23 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <SDL2/SDL.h>
# include <math.h>

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
	int				(*pixels)[WIDTH];
}					t_sdl;

void		log_and_exit_on_error(void	*ptr);
void		init_sdl(t_sdl *sdl);
void		event_loop(t_sdl	*sdl);
void		sdl_cleanup(t_sdl	*sdl);
#endif
