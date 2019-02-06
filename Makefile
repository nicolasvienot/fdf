# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:52:13 by nvienot           #+#    #+#              #
#    Updated: 2019/02/06 17:55:31 by nvienot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	main.c ft_draw.c ft_parse.c ft_init_proj.c ft_get_map.c \
			ft_error.c ft_print.c ft_init_img.c ft_deal_key.c \
			ft_transform.c ft_utilities.c ft_create_proj.c \
			ft_init_win.c

CC		=	gcc

CFLAGS	= 	-Wall -Werror -Wextra

OBJS	=	$(SRCS:.c=.o)

F.WORK	=	-lmlx -L mlx -framework OpenGL -framework Appkit

LIB		=	libft/libft.a

RM		=	rm -rf

.SILENT	:

.PHONY	: 	all clean fclean re

#Colors
_BLACK=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

_END=\x1b[0m

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft/
			echo "$(_RED)Libft ! $(_GREEN)OK$(_END)"
			make -C mlx/
			@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(F.WORK) -o $(NAME)
			
			echo "\n"
			echo "$(_RED)    ______ ______ ______    _        ______                   _          _ 	"
			echo "$(_RED)    |  ___||  _  \|  ___|  (_)       | ___ \                 | |        | | 	"
			echo "$(_BLUE)    | |_   | | | || |_      _  ___   | |_/ /  ___   __ _   __| | _   _  | | 	"
			echo "$(_PURPLE)    |  _|  | | | ||  _|    | |/ __|  |    /  / _ \ / _  | / _  || | | | | | "
			echo "$(_CYAN)    | |    | |/ / | |      | |\__ \  | |\ \ |  __/| (_| || (_| || |_| | |_|	"
			echo "$(_GREEN)    \_|    |___/  \_|      |_||___/  \_| \_| \___| \__,_| \__,_| \__, | (_)	"
			echo "$(_YELLOW)                                                                  __/ |		"
			echo "$(_WHITE)    $(_RED)By $(_PURPLE)auguyon $(_BLUE)&& $(_CYAN)nvienot $(_GREEN)2019 $(_YELLOW)!$(_WHITE)!$(_END)		  	         |___/"
			echo "\n"


		echo "$(_RED)d88888b d8888b. d88888b      d888888b .d8888.      d8888b. d88888b  .d8b.  d8888b. db    db 	"
		echo "$(_BLUE)88'     88   8D 88'             88'   88'  YP      88   8D 88'     d8'  8b 88   8D  8b  d8' 	"
		echo "$(_PURPLE)88ooo   88   88 88ooo           88     8bo.        88oobY' 88ooooo 88ooo88 88   88   8bd8'  "
		echo "$(_CYAN)88~~~   88   88 88~~~           88       Y8b.      88 8b   88~~~~~ 88~~~88 88   88    88    	"
		echo "$(_GREEN)88      88  .8D 88             .88.   db   8D      88  88. 88.     88   88 88  .8D    88    	"
		echo "$(_YELLOW)YP      Y8888D' YP           Y888888P  8888Y'      88   YD Y88888P YP   YP Y8888D'    YP    "

clean	:
			@$(RM) $(OBJS)
			make clean -C libft/
			make clean -C mlx/

			echo "$(_RED)Clean ! $(_GREEN)OK$(_END)"

fclean	:	clean
			@$(RM) $(NAME)
			make fclean -C libft/

			echo "$(_RED)Fclean ! $(_GREEN)OK$(_END)"

re		:	fclean all
			make re -C libft/
			make re -C mlx/

recl	:	all clean
			make recl -C libft/