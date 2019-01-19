/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/17 17:46:13 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_draw_line(t_win *win)

{
	win->z = RGB(255, 0, 255);
	int x = 0;
	int y = 0;
	int x1 = 100;
	int x2 = 300;
	int y1 = 300;
	int y2 = 100;
		// CAS 1
	// int x1 = 100;
	// int x2 = 300;
	// int y1 = 300;
	// int y2 = 100;
	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y1+((y2-y1)*(x-x1))/(x2-x1), win->z);
		x++;
	}
		// CAS 2
	// int x1 = 300;
	// int x2 = 100;
	// int y1 = 100;
	// int y2 = 300;
				// x = x2;
				// while (x <= x1)
				// {
				// 	mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y2+((y1-y2)*(x-x2))/(x1-x2), win->z);
				// 	x++;
				// }
		// CAS 3
	// int x1 = 100;
	// int x2 = 150;
	// int y1 = 300;
	// int y2 = 100;
	// y = y2;
	// while (y <= y1)
	// {
	// 	mlx_pixel_put(win->mlx_ptr, win->win_ptr, x2+((x1-x2)*(y-y2))/(y1-y2), y, win->z);
	// 	y++;
	// }
		// CAS 4
	// int x1 = 100;
	// int x2 = 150;
	// int y1 = 100;
	// int y2 = 300;
	// y = y1;
	// while (y <= y2)
	// {
	// 	mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1+((x2-x1)*(y-y1))/(y2-y1), y, win->z);
	// 	y++;
	// }
	win->z = RGB(0, 0, 255);
	

	return (1);
}