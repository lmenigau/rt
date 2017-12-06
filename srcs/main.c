/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:24:28 by lmenigau          #+#    #+#             */
/*   Updated: 2017/12/06 14:21:12 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		log_error(t_rt *env)
{
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't initialize : %s", SDL_GetError());
	cleanup(env);
}

void		init_sdl(char *name, t_rt *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		log_error(env);
	if ((env->sdl.window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE)) == NULL)
		log_error(env);
	if ((env->sdl.renderer = SDL_CreateRenderer(env->sdl.window, -1, 0)) == NULL)
		log_error(env);
	if ((env->sdl.texture = SDL_CreateTexture(env->sdl.renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, 1024, 768)) == NULL)
		log_error(env);
	env->sdl.pixels = malloc(WIDTH * HEIGHT * 4);
}

void	event_loop(t_rt *env)
{
	int			i;
	SDL_Event	event;

	i = -1;
	while (42)
	{
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT)
			cleanup(env);
		if(event.type == SDL_KEYDOWN)
		{
			if (EVENT_KEY == SDLK_ESCAPE)
				cleanup(env);
		}
		/*if (envent.type == SDL_KEYUP)
		{
			Pour plus tard si besoin...
		}
		*/
		while (++i < (HEIGHT - 1) * WIDTH)
				env->sdl.pixels[i] = 0xFFFFFF;
		SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.pixels, WIDTH * 4);
		SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
		SDL_RenderPresent(env->sdl.renderer);
	}
}

void cleanup(t_rt	*env)
{
	if (env->sdl.texture != NULL)
		SDL_DestroyTexture(env->sdl.texture);
	if (env->sdl.renderer != NULL)
		SDL_DestroyRenderer(env->sdl.renderer);
	if (env->sdl.window != NULL)
		SDL_DestroyWindow(env->sdl.window);
	SDL_Quit();
	exit(1);
}

int main(void)
{
	t_rt	*env;

	env = (t_rt *)ft_memalloc(sizeof(t_rt));
	init_sdl("Rt_Test", env);
	event_loop(env);
	cleanup(env);
	return (0);
}
