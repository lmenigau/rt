/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles </var/mail/mbeilles>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 18:07:49 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/21 03:04:28 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "rt.h"

static t_context	init_context(void)
{
	t_context		ctx;
	if (SDL_Init(SDL_INIT_VIDEO))
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	ctx.cam = (t_cam){(t_vec3){0.0, 0.0, 0.0}
					, (t_vec3){0.0, 0.0, 1.0}, FOV_H, FOV_H};
	ctx.win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	ctx.surface = SDL_GetWindowSurface(ctx.win);
	if (!(ctx.key_functions = (t_input_function*)ft_memalloc(285
			* sizeof(t_input_function))) &&
		!(ctx.mouse_functions = (t_input_function*)ft_memalloc(5
			* sizeof(t_input_function))))
		leave(NULL);
	ctx.objs = NULL;
	return (ctx);
}

int					main(int c, char **v)
{
	uint32_t		quit;
	SDL_Event		e;
	t_context		ctx;

	(void)c;
	(void)v;
	quit = 0;
	ctx = init_context();
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = 1;
			/*if (e.type == SDL_KEYDOWN &&*/
	/*(ctx->key_functions)[SDL_GetScancodeFromKey(e.key.keysym.sym)])*/
		/*(ctx->key_functions)[SDL_GetScancodeFromKey(e.key.keysym.sym)](e);*/
			SDL_UpdateWindowSurface(ctx.win);
		}
	}
	leave(NULL);
}
