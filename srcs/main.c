/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:24:28 by lmenigau          #+#    #+#             */
/*   Updated: 2017/11/28 18:52:38 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		log_and_exit_on_error(void	*ptr)
{
	if (ptr == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"Couldn't initialize : %s", SDL_GetError());
		exit(1);
	}
}

void		init_sdl(t_sdl *sdl)
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"SDL_Error: %s", SDL_GetError());
	}
	sdl->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	log_and_exit_on_error(sdl->window);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, 0);
	log_and_exit_on_error(sdl->renderer);
	sdl->texture = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_TARGET, 1024, 768);
	log_and_exit_on_error(sdl->texture);
	sdl->pixels = malloc(WIDTH * HEIGHT * 4);
}

void	event_loop(t_sdl	*sdl)
{
	int			i;
	SDL_Event	event;

	i = -1;
	while (42)
	{
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT)
			break;
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			break;
		while (++i < (HEIGHT - 1) * WIDTH)
				sdl->pixels[i] = 0xFFFFFF;
		SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, WIDTH * 4);
		SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
		SDL_RenderPresent(sdl->renderer);
	}
}

void sdl_cleanup(t_sdl	*sdl)
{
	SDL_DestroyTexture(sdl->texture);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}

int main(void)
{
	t_sdl	sdl;

	init_sdl(&sdl);
	event_loop(&sdl);
	return (0);

}
