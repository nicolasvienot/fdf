/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/13 22:15:52 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_print_menu_2(t_win **win)
{
	char *x;
	char *y;

	x = ft_itoa((*win)->aff_x - (WIN_HOR_SIZE - IMG_HOR_SIZE) / 2);
	y = ft_itoa((*win)->aff_y - (WIN_VER_SIZE - IMG_VER_SIZE) / 2);
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 195, 440, PURPLE, "X = ");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 235, 440, PURPLE, x);
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 195, 465, PURPLE, "Y = ");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 235, 465, PURPLE, y);
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1500, 10, PURPLE, \
			"Press M to display");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1500, 30, PURPLE, \
			"or hide the menu");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1500, 60, PURPLE, \
			"Hold * to get");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1500, 80, PURPLE, \
			"the animation");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 950, 970, PURPLE, "MAP NAME :");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1060, 970, PURPLE, \
		(*win)->filename);
	free(x);
	free(y);
	return (1);
}

int			ft_print_menu_1(t_win **win)
{
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1520, 390, PURPLE, "MENU ");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 420, PURPLE,\
			"Parallel projection : P");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 440, PURPLE,\
			"Isometric projection : I");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 460, PURPLE,\
			"Restart : O");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 480, PURPLE,\
			"Increase alt : Page up");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 500, PURPLE,\
			"Decrease alt : Page down");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 520, PURPLE,\
			"Zoom in : + / Scroll");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 540, PURPLE,\
			"Zoom out : - / Scroll");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 560, PURPLE,\
			"Move : Arrow keys");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 580, PURPLE,\
			"Rotate : R & T");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 600, PURPLE, "Quit : Esc");
	return (1);
}

int			ft_print_menu(t_win **win)
{
	if ((*win)->menu == 1)
		ft_print_menu_1(win);
	ft_print_menu_2(win);
	return (1);
}
