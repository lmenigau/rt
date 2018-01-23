/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 03:28:36 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/23 00:52:38 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "rt.h"

/*static void			init_keyboard_config(t_context *ctx)*/
/*{*/
	/*ctx->key_functions[SDL_SCANCODE_ESCAPE] = &leave;*/
/*}*/

static t_context	init_context(void)
{
	t_context		ctx;

	if (SDL_Init(SDL_INIT_VIDEO))
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	ctx.cam = (t_cam){(t_vec3){0.0, 0.0, 0.0}	// Position
					, (t_vec3){0.0, 0.0, 0.0}	// Yaw
					, (t_vec3){0.0, 0.0, 0.0}	// Roll
					, (t_vec3){0.0, 0.0, 1.0}	// Pitch
					, FOV_H, FOV_V};			// Fov
	ctx.win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED
			, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	ctx.surface = SDL_GetWindowSurface(ctx.win);
	/*if (!(ctx.key_functions = (t_input_function*)ft_memalloc(SDL_NUM_SCANCODES*/
					/** sizeof(t_input_function))) &&*/
			/*!(ctx.mouse_functions = (t_input_function*)ft_memalloc(5*/
					/** sizeof(t_input_function))))*/
		/*leave(NULL);*/
	ctx.objs = NULL;
	start_input_interface();
	bind_input_code(add_input_code(((t_input_code){0, 0, 0, 0, 0}), SDL_SCANCODE_ESCAPE), &leave);
	/*init_keyboard_config(&ctx);*/
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
		scan_inputs();
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = 1;
			/*if (e.type == SDL_KEYDOWN &&*/
			/*(ctx.key_functions)[SDL_GetScancodeFromKey(e.key.keysym.sym)])*/
			/*(ctx.key_functions)[*/
			/*SDL_GetScancodeFromKey(e.key.keysym.sym)](e);*/
			SDL_UpdateWindowSurface(ctx.win);
		}
	}
	leave(NULL);
}
