#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/18 02:18:30 by lmenigau          #+#    #+#             *#
#*   Updated: 2017/11/04 19:39:09 by lmenigau         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME	=	rtv1
CC		=	clang
SRC		=	main.c
OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-Weverything -Wall -Wextra -Werror -Iminilibx_macos/ -g -Ofast -march=native
FFLAGS	=	-framework Appkit -framework OpenGl -framework SDL2

.PHONY	:	all clean fclean re lib

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(MLX)
			$(CC) $(CFLAGS) $(FFLAGS) -o $@ $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
