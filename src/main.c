/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 03:28:36 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 08:11:20 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <pthread.h>
#include "rt.h"

static void			lol(SDL_Event e)
{
	(void)e;
	printf(STR_INFO("LOL!\n"));
}

static void			lol2(SDL_Event e)
{
	(void)e;
	printf(STR_INFO("LOL2!\n"));
}

static t_context	init_context(void)
{
	t_context		ctx;
	pthread_t		t;

	if (TTF_Init())
		(void)(SDL_Log("Error with TTF: %s", TTF_GetError()), exit(2));
	if (SDL_Init(SDL_INIT_VIDEO))
		(void)(SDL_Log("Error with SDL: %s", SDL_GetError()), exit(2));
	ctx.cam = (t_cam){(t_vec3){0.0, 0.0, 0.0}	// Position
					, (t_vec3){0.0, 0.0, 0.0}	// Yaw
					, (t_vec3){0.0, 0.0, 0.0}	// Roll
					, (t_vec3){0.0, 0.0, 1.0}	// Pitch
					, FOV_H, FOV_V};			// Fov
	ctx.win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED
			, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	ctx.surface = SDL_GetWindowSurface(ctx.win);
	ctx.objs = NULL;
	start_input_interface();
	bind_input_code(add_input_code(add_input_code((
		(t_input_code){0, 0, 0, 0, 0}), SDL_SCANCODE_ESCAPE)
									, SDL_SCANCODE_LCTRL), &leave);
	bind_input_code(add_input_code((
		(t_input_code){0, 0, 0, 0, 0}), SDL_SCANCODE_A), &lol2);
	bind_input_code(add_input_code((
		(t_input_code){0, 0, 0, 0, 0}), SDL_SCANCODE_ESCAPE), &lol);
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
			scan_inputs(e);
			display_ux(&ctx);
			if (e.type == SDL_QUIT)
				quit = 1;
			SDL_UpdateWindowSurface(ctx.win);
		}
	}
	leave(NULL);
}
