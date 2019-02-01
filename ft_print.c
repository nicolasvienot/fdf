/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:29:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/01 16:37:31 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_print_menu(t_win *win)
{
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1520, 380, PURPLE, "MENU ");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 420, PURPLE,\
            "Projection Para : P");
    mlx_string_put(win->mlx_ptr, win->win_ptr, 1450, 440, PURPLE,\
            "Projection Iso : I");
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
    return (0);
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