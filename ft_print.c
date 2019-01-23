/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/23 13:51:44 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			print_menu(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 20, 0xD3D3DA, "MENU ");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 105, 0xD3D3DA,\
	// 		"Projection Para : P");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 145, 0xD3D3DA,\
	// 		"Projection Iso : I");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 50, 0xD3D3DA,\
			"Start : O");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 80, 0xD3D3DA,\
			"More alt : Page up");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 110, 0xD3D3DA,\
			"Less alt : Page down");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 140, 0xD3D3DA,\
			"Zoom up : +");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 170, 0xD3D3DA,\
			"Zoom down : -");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 200, 0xD3D3DA,\
			"Deplacement : Arrow keys");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 600, 0xD3D3DA,\
	// 		"Rotation : R & T");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1250, 230, 0xD3D3DA, "Quit : Esc");
	return (0);
}