# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 08:44:16 by mbeilles          #+#    #+#              #
#    Updated: 2018/01/21 03:04:45 by mbeilles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#------------------------------------------------------------------------------#
#                                   Naming                                     #
#==============================================================================#

NAME = rt_v1
NICK = "RT1"

#==============================================================================#
#                                 Compilation                                  #
#==============================================================================#

CC = clang

FLAGS = $(HIDDEN_FLAGS) $(NAZI_FLAG) -fsanitize=address -g3 -O0\

CFLAG = $(FLAGS) -I$(PATH_INC) -I$(PATH_LIB)$(PATH_INC) \
		-isystem $(SDL_HDR_PATH) -isystem $(SDL_IMG_HDR_PATH) \
		-isystem $(XML_HDR_PATH) \

HIDDEN_FLAGS = #-v \

NAZI_FLAG = -Weverything \

#==============================================================================#
#                                   Paths                                      #
#==============================================================================#

PATH_SRC = src/
PATH_INC = includes/
PATH_OBJ = obj/
PATH_LIB = libft/

SDL_LIB_PATH = ~/.brew/Cellar/sdl2/2.0.7/lib/
SDL_HDR_PATH = ~/.brew/Cellar/sdl2/2.0.7/include/SDL2/
SDL_IMG_LIB_PATH = ~/.brew/Cellar/sdl2_image/2.0.2/lib/
SDL_IMG_HDR_PATH = ~/.brew/Cellar/sdl2_image/2.0.2/include/SDL2/
XML_LIB_PATH = ~/.brew/Cellar/libxml2/2.9.7/lib/
XML_HDR_PATH = ~/.brew/Cellar/libxml2/2.9.7/include/libxml2/libxml/

VPATH = $(PATH_SRC):$(PATH_OBJ):$(PATH_INC)

#==============================================================================#
#                                   Various                                    #
#==============================================================================#

SHELL = /bin/sh
MAKE_DEP = 1
INSTALL_BREW = 0
INSTALL_SDL = 0
INSTALL_XML = 0

#==============================================================================#
#                                  Commands                                    #
#==============================================================================#

BREW_INSTALL_CMD = printf $(HD)"Installing Brew\n"$(NRM) \
				   && curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh ;\

SDL_INSTALL_CMD = printf $(HD)"Installing SDL2\n"$(NRM) \
				  && brew install sdl2 \
				  && printf $(HD)"Installing SDL2_Image\n"$(NRM) \
				  && brew install sdl2_image ;\

XML_INSTALL_CMD = printf $(HD)"Installing libxml2\n"$(NRM) \
				  && brew install libxml2 ;\

#==============================================================================#
#                                   Sources                                    #
#==============================================================================#

DEPENDECIES = make -C $(PATH_LIB) $(INSTRUCTION) HIDDEN_FLAGS=$(HIDDEN_FLAGS);\

DEP = -L $(PATH_LIB) -lft													\
	  -L $(SDL_LIB_PATH) -lsdl2												\
	  -L $(SDL_IMG_LIB_PATH) -lsdl2_image									\
	  -L $(XML_LIB_PATH) -lxml2												\

SRC = main.c																\
	  math.c																\
	  utils.c																\

INC = libft.h																\
	  rt.h																	\

#==============================================================================#
#                                    Vpaths                                    #
#==============================================================================#

vpath %.c $(PATH_SRC)
vpath %.o $(PATH_OBJ)
vpath %.h $(PATH_INC)
vpath %.h $(PATH_LIB)$(PATH_INC)

#==============================================================================#
#                             Variables Customizers                            #
#==============================================================================#

SRC_O = $(SRC:.c=.o)
ARG_O = $(addprefix $(PATH_OBJ),$(notdir $(SRC:.c=.o)))

#==============================================================================#
#                                   Strings                                    #
#==============================================================================#

PROJECT_COLOR = "\033[38;2;254;128;25m"
PROJECT_COLOR_ALT = "\033[38;2;254;128;25m"
PRIMARY_COLOR = "\033[38;2;93;188;210m"
PRIMARY_COLOR_ALT = "\033[38;2;38;106;150m"
SUCCESS_COLOR = "\033[38;2;141;143;38m"
SUCCESS_COLOR_ALT = "\033[38;2;39;174;96m"
ERROR_COLOR = "\033[38;2;231;76;60m"
BOLD = "\033[1m"

KO = $(PRIMARY_COLOR_ALT)"["$(ERROR_COLOR)$(BOLD)" - "$(PRIMARY_COLOR_ALT)"] "
OK = $(PRIMARY_COLOR_ALT)"["$(SUCCESS_COLOR)$(BOLD)" + "$(PRIMARY_COLOR_ALT)"] "
HD = $(PRIMARY_COLOR_ALT)"["$(PROJECT_COLOR)$(NICK)$(PRIMARY_COLOR_ALT)"] "

NRM = "\033[0m"

SUCCESS_HD = $(PRIMARY_COLOR_ALT)"["$(PROJECT_COLOR)"SUCCESS"$(PRIMARY_COLOR_ALT)"] "
FAILURE_HD = $(PRIMARY_COLOR_ALT)"["$(PROJECT_COLOR)"FAILURE"$(PRIMARY_COLOR_ALT)"] "

MAKING_PROGRESS = $(OK)$(SUCCESS_COLOR_ALT)"> Genrating "$(NAME)"...\n"$(NRM)
MAKING_SUCCESS = $(SUCCESS_HD)$(SUCCESS_COLOR)$(NAME)" generated!\n"$(NRM)
MAKING_FAILURE = $(FAILURE_HD)$(ERROR_COLOR)$(NAME)" not generated!\n"$(NRM)

COMPILING_OK = $(HD)$(OK)$(PRIMARY_COLOR)"$@\n"$(NRM)
COMPILING_KO = $(HD)$(KO)$(ERROR_COLOR)"* "$(PRIMARY_COLOR)"$@\n"$(NRM)

CLEANING_OBJS = $(HD)$(OK)$(PROJECT_COLOR)"Files cleaned\n"$(NRM)
CLEANING_BINS = $(HD)$(OK)$(PROJECT_COLOR)"Binary cleaned\n"$(NRM)

#==============================================================================#
#                                    Rules                                     #
#==============================================================================#

$(NAME): $(SRC_O) | $(INC)
	@if [ $(INSTALL_BREW) == 1 ]; then $(BREW_INSTALL_CMD) fi;
	@if [ $(INSTALL_SDL) == 1 ]; then $(SDL_INSTALL_CMD) fi;
	@if [ $(INSTALL_XML) == 1 ]; then $(XML_INSTALL_CMD) fi;
	@$(eval INSTRUCTION := all)
	@if [ $(MAKE_DEP) == 1 ]; then $(DEPENDECIES) fi;
	@printf $(MAKING_PROGRESS)
	@$(CC) -o $(NAME) $(ARG_O) $(DEP) $(CFLAG) $(FLAGS); \
		if [ $$? != 1 ]; then printf $(MAKING_SUCCESS); exit 0; \
		else printf $(MAKING_FAILURE); exit 2; fi

all: $(NAME)

%.o: %.c $(INC) | $(PATH_OBJ)
	@$(CC) -o $(PATH_OBJ)$@ -c $< $(CFLAG) $(FLAGS); \
		if [ $$? != 1 ]; then printf $(COMPILING_OK); exit 0; \
		else printf $(COMPILING_KO); exit 2; fi

clean:
	@$(eval INSTRUCTION := clean)
	@if [ $(MAKE_DEP) == 1 ]; then $(DEPENDECIES) fi;
	@-rm -f $(ARG_O)
	@printf $(CLEANING_OBJS)

fclean:
	@$(eval INSTRUCTION := fclean)
	@if [ $(MAKE_DEP) == 1 ]; then $(DEPENDECIES) fi;
	@-rm -f $(ARG_O)
	@printf $(CLEANING_OBJS)
	@-rm -f $(NAME)
	@printf $(CLEANING_BINS)

install_dependencies: install_brew install_sdl install_xml
	@printf $(SUCCESS_HD)$(SUCCESS_COLOR)"Instalation complete!\n"

install_sdl:
	@$(SDL_INSTALL_CMD)

install_xml:
	@$(XML_INSTALL_CMD)

install_brew:
	@if [ ! -f $(HOME)/.brew ]; then
		$(BREW_INSTALL_CMD); fi

re: fclean all

.PHONY:

$(PATH_OBJ):
	@mkdir $@
