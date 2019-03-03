# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:52:13 by nvienot           #+#    #+#              #
#    Updated: 2019/02/18 14:57:25 by nvienot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	srcs/main.c srcs/ft_draw_line.c srcs/ft_draw_proj.c srcs/ft_parse.c \
			srcs/ft_init_proj.c srcs/ft_get_map.c srcs/ft_error.c \
			srcs/ft_print.c srcs/ft_init_img.c srcs/ft_deal_key.c \
			srcs/ft_transform.c srcs/ft_utilities.c srcs/ft_create_proj.c \
			srcs/ft_init_win.c

CC		=	gcc

INC.	=	-I libft/ -I includes/ -I mlx/

FLAGS	= 	-O2 -Wall -Werror -Wextra

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

$(NAME)	:	$(OBJS) Makefile includes/fdf.h
			make -C libft/
			echo "$(_RED)Libft ! $(_GREEN)OK$(_END)"
			make -C mlx/
			$(CC) -o $(NAME) $(OBJS) $(LIB) $(F.WORK)
			
			echo "$(_RED)    ______ ______ ______    _        ______                   _          _ 	"
			echo "$(_RED)    |  ___||  _  \|  ___|  (_)       | ___ \                 | |        | | 	"
			echo "$(_BLUE)    | |_   | | | || |_      _  ___   | |_/ /  ___   __ _   __| | _   _  | | 	"
			echo "$(_PURPLE)    |  _|  | | | ||  _|    | |/ __|  |    /  / _ \ / _  | / _  || | | | | | "
			echo "$(_CYAN)    | |    | |/ / | |      | |\__ \  | |\ \ |  __/| (_| || (_| || |_| | |_|	"
			echo "$(_GREEN)    \_|    |___/  \_|      |_||___/  \_| \_| \___| \__,_| \__,_| \__, | (_)	"
			echo "$(_YELLOW)                                                                  __/ |		"
			echo "$(_WHITE)    $(_RED)By $(_PURPLE)auguyon $(_BLUE)&& $(_CYAN)nvienot $(_GREEN)2019 $(_YELLOW)!$(_WHITE)!$(_END)		  	         |___/"
			echo "\n"

$(OBJS)	: 	%.o: %.c
			$(CC) $(FLAGS) $(INC.) -c $< -o $@

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