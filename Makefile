# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:52:13 by nvienot           #+#    #+#              #
#    Updated: 2019/01/10 17:59:15 by nvienot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = 	main.c \
		ft_error.c \
		ft_transform.c \
		ft_solver.c \
		ft_map.c \
		ft_utility.c

OBJ = $(SRC:.c=.o)
INCLUDES = -I libft/libft.h -I fillit.h
LIBS = -L libft/ -lft
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@gcc -o $(NAME) $(OBJ) $(LIBS)
	@echo "\033[32;1;3;4mFillit is ready!\033[0m"
	@echo "\033[32;1;3;4mGood job mate, you did it! Enjoy.\033[0m"

$(OBJ): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@ 

clean:
	@rm -f $(OBJ)
	@make -C Libft/ clean
	@echo "\033[35;1;4;3mAll object files have been sucessfully removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C Libft/ fclean
	@echo "\033[31;1;3;4mThe files fillit and libft.a have been successfully removed.\033[0m"
	@echo "\033[31;1;3;4mWell done!\033[0m"

re: fclean all
