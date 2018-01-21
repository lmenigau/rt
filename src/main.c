/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles </var/mail/mbeilles>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 18:07:49 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/21 00:54:56 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "rt.h"

int				main(int c, char **v)
{
	uint32_t	quit;

	if (SDL_Init(SDL_INIT_VIDEO))
		leave(W_FAIL_SDL_INIT, EXIT_FAILURE);
	ft_putstr(W_INFO_COMPLETE);
	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			draw(env);
			if (e.type == SDL_QUIT)
				quit = 1;
			if (e.type == SDL_KEYDOWN &&
	(env->key_functions)[SDL_GetScancodeFromKey(e.key.keysym.sym)])
		(env->key_functions)[SDL_GetScancodeFromKey(e.key.keysym.sym)](e, env);
			SDL_UpdateWindowSurface(env->win);
		}
	}
	leave(W_INFO_EXIT, EXIT_SUCCESS);
	return (0);
}
