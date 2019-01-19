/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/17 18:38:48 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int ft_draw_line(t_win *win, int x1, int x2, int y1, int y2)

{
	int x = 0;
	int y = 0;

	win->z = RGB(255, 0, 255);
	if (x1 <= x2 && (x2 - x1) >= abs(y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y1+((y2-y1)*(x-x1))/(x2-x1), win->z);
			x++;
		}
	}
	if (x2 <= x1 && (x1 - x2) >= abs(y1 - y2))
	{
		x = x2;
		while (x <= x1)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y2+((y1-y2)*(x-x2))/(x1-x2), win->z);
			x++;
		}
	}
	if (y2 <= y1 && (y1 - y2) >= abs(x1 - x2))
	{
		y = y2;
		while (y <= y1)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x2+((x1-x2)*(y-y2))/(y1-y2), y, win->z);
			y++;
		}
	}
	if (y1 <= y2 && (y2 - y1) >= abs(x2 - x1))
	{
		y = y1;
		while (y <= y2)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1+((x2-x1)*(y-y1))/(y2-y1), y, win->z);
			y++;
		}
	}
	return (1);
}