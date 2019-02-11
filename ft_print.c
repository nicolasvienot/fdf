/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/11 23:48:40 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_print_menu_2(t_win **win)
{
	char *x;
	char *y;

	x = ft_itoa((*win)->aff_x - (WIN_HOR_SIZE - IMG_HOR_SIZE) / 2);
	y = ft_itoa((*win)->aff_y - (WIN_VER_SIZE - IMG_VER_SIZE) / 2);
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 200, 340, PURPLE, "X = ");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 240, 340, PURPLE, x);
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 200, 360, PURPLE, "Y = ");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 240, 360, PURPLE, y);
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1500, 10, PURPLE, \
			"Press M to display");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1500, 30, PURPLE, \
			"or hide the menu");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 920, 970, PURPLE, "MAP NAME :");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1030, 970, PURPLE, \
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
			"Recenter : O");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 480, PURPLE,\
			"More alt : Page up");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 500, PURPLE,\
			"Less alt : Page down");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 520, PURPLE,\
			"Zoom up : + / Scroll");
	mlx_string_put((*win)->mlx_ptr, (*win)->win_ptr, 1440, 540, PURPLE,\
			"Zoom down : - / Scroll");
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
