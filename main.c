/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:24:28 by lmenigau          #+#    #+#             */
/*   Updated: 2017/11/07 05:57:13 by lmenigau         ###   ########.fr       */
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
	sdl->window = SDL_CreateWindow("SDL_CreateTexture", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	log_and_exit_on_error(sdl->window);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, 0);
	log_and_exit_on_error(sdl->renderer);
	sdl->texture = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, 1024, 768);
	log_and_exit_on_error(sdl->texture);
	sdl->pixels = malloc(WIDTH * HEIGHT * sizeof(*sdl->pixels));
}

void	event_loop(t_sdl	*sdl)
{
	SDL_Event event;

	while (42)
	{
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT)
			break;
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			break;
		for (int i = 0; i < HEIGHT; i++)
			for(int j=0; j< WIDTH; j++)
				sdl->pixels[i][j] = 0xFFFF;
		for (int i = 0; i < HEIGHT; i++)
			for(int j=0; j< WIDTH; j++)
				sdl->pixels[i][j] = (int)0xFF000000;
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
