/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/05 19:00:12 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_print_menu_2(t_win *win)
{
	char *x;
	char *y;

	x = ft_itoa(win->aff_x - (WIN_HOR_SIZE - IMG_HOR_SIZE) / 2);
	y = ft_itoa(win->aff_y - (WIN_VER_SIZE - IMG_VER_SIZE) / 2);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1580, 20, PURPLE, "X = ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1620, 20, PURPLE, x);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1580, 40, PURPLE, "Y = ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1620, 40, PURPLE, y);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1390, 60, PURPLE, "Press M to display the menu");
    return (1);
}

int			ft_print_menu_1(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1520, 380, PURPLE, "MENU ");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 420, PURPLE,\
            "Parallel projection : P");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 440, PURPLE,\
            "Isometric projection : I");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 460, PURPLE,\
            "Restart : O");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 480, PURPLE,\
            "Change projection : P");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 500, PURPLE,\
            "More alt : Page up");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 520, PURPLE,\
            "Less alt : Page down");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 540, PURPLE,\
            "Zoom up : +");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 560, PURPLE,\
            "Zoom down : -");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 580, PURPLE,\
            "Move : Arrow keys");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 600, PURPLE,\
            "Rotate : R & T");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 620, PURPLE, "Quit : Esc");
	return (1);
}

int			ft_print_menu(t_win *win)
{
	ft_print_menu_1(win);
	ft_print_menu_2(win);
	return (1);
}
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 20, 0xD3D3DA, "MENU ");
	// // mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 105, 0xD3D3DA,\
	// // 		"Projection Para : P");
	// // mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 145, 0xD3D3DA,\
	// // 		"Projection Iso : I");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 50, 0xD3D3DA,\
	// 		"Restart : O");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 80, 0xD3D3DA,\
	// 		"Change projection : P");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 110, 0xD3D3DA,\
	// 		"More alt : Page up");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 140, 0xD3D3DA,\
	// 		"Less alt : Page down");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 170, 0xD3D3DA,\
	// 		"Zoom up : +");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 200, 0xD3D3DA,\
	// 		"Zoom down : -");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 230, 0xD3D3DA,\
	// 		"Move : Arrow keys");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 260, 0xD3D3DA,\
	// 		"Rotate : R & T");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 290, 0xD3D3DA, "Quit : Esc");
// 	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 290, 0xD3D3DA, " ");
// 	return (0);
// }