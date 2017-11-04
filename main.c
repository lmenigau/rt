/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:24:28 by lmenigau          #+#    #+#             */
/*   Updated: 2017/11/04 21:26:08 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "rt.h"

void		log_and_exit_on_error(void	*ptr)
{
	if (prt == NULL)SDL_LOG_PRIORITY_CRITICAL
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"Couldn't initialize : %s", SDL_GetError());
		exit(1);
	}
}

void		init_sdl(SDL_Renderer *renderer, SDL_Renderer *texture)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"SDL_Error: %s", SDL_GetError());
	}
	window = SDL_CreateWindow("SDL_CreateTexture", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	log_and_exit_on_error(window);
	renderer = SDL_CreateRenderer(window, -1, 0);
	log_and_exit_on_error(renderer);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, 1024, 768);
	log_and_exit_on_error(texture);
}

voi		event_loop()
int main(void)
{

	SDL_Texture *texture;
	SDL_Event event;
	while (1) {
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT)
			break;
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			break;
		r.x=rand();
		r.y=rand();
		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
		for (int i = 10; i < 100; i++)
			SDL_RenderDrawPoint(renderer, 20, i);
		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;

}
