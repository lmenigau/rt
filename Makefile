NAME= rtv1
SRC= srcs/main.c

HDRS= includes/rt.h

OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -v -Winline -march=native -Ofast  -Weverything -Wall -Werror -Wextra  #-g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt
LIBFT_PATH=./libft/
SDL_LIB_PATH= ~/.brew/Cellar/sdl2/2.0.7/lib
SDL_HDR_PATH= ~/.brew/Cellar/sdl2/2.0.7/include/SDL2/
FLAGS= -L$(LIBFT_PATH) -lft -I$(HDR_PATH) -I./includes  -isystem $(SDL_HDR_PATH) -framework OpenGL -framework AppKit -L $(SDL_LIB_PATH) -lSDL2

all: submodule $(NAME)

submodule:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME)
%.o : %.c $(HDRS)
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -isystem $(SDL_HDR_PATH) -I./includes -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
