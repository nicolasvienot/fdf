# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:52:13 by nvienot           #+#    #+#              #
#    Updated: 2019/01/31 19:02:56 by nvienot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	main.c ft_draw_line.c ft_parse.c ft_init_proj.c ft_get_map.c \
			ft_error.c ft_print.c ft_put_pix_to_im.c ft_deal_key.c \
			ft_transform.c ft_utilities.c ft_create_proj.c

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
			echo "$(_RED)    ______ ______ ______    _        ______                   _          _"
			echo "$(_RED)    |  ___||  _  \|  ___|  (_)       | ___ \                 | |        | |"
			echo "$(_BLUE)    | |_   | | | || |_      _  ___   | |_/ /  ___   __ _   __| | _   _  | |"
			echo "$(_PURPLE)    |  _|  | | | ||  _|    | |/ __|  |    /  / _ \ / _  | / _  || | | | | |"
			echo "$(_CYAN)    | |    | |/ / | |      | |\__ \  | |\ \ |  __/| (_| || (_| || |_| | |_|"
			echo "$(_GREEN)    \_|    |___/  \_|      |_||___/  \_| \_| \___| \__,_| \__,_| \__, | (_)"
			echo "$(_YELLOW)                                                                  __/ |"
			echo "$(_WHITE)    $(_RED)By $(_PURPLE)auguyon $(_BLUE)&& $(_CYAN)nvienot $(_GREEN)2019 $(_YELLOW)!$(_WHITE)!$(_END)		  	         |___/"
			echo "\n"
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