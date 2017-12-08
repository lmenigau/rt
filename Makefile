NAME= rtv1
SRC= srcs/main.c

HDRS= includes/rt.h

OBJ= $(SRC:.c=.o)
HDR_PATH = ./libft/includes/
SDL_HEADER := $(shell sdl2-config --cflags)
SDL_LIB := $(shell sdl2-config --libs)
CC= gcc
IFLAGS := -I./includes -I$(HDR_PATH) $(SDL_HEADER) 
CC_FLAGS = $(IFLAGS) -v -Winline -march=native -Ofast -Wall -Wextra  #-g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt
LIBFT_PATH=./libft/
FLAGS= -L$(LIBFT_PATH) -lft -framework OpenGL -framework AppKit $(SDL_LIB)

all: submodule $(NAME)

submodule:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME)

%.o : %.c $(HDRS)
	$(CC) $(CC_FLAGS) -c $< -c -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
