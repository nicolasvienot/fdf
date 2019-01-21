/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/21 17:19:04 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int ft_draw_line(t_win *win, int x1, int x2, int y1, int y2)

{
	int x = 0;
	int y = 0;

	win->color = RGB(255, 0, 255);
	if (x1 <= x2 && (x2 - x1) >= abs(y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y1+((y2-y1)*(x-x1))/(x2-x1), win->color);
			x++;
		}
	}
	if (x2 <= x1 && (x1 - x2) >= abs(y1 - y2))
	{
		x = x2;
		while (x <= x1)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y2+((y1-y2)*(x-x2))/(x1-x2), win->color);
			x++;
		}
	}
	if (y2 <= y1 && (y1 - y2) >= abs(x1 - x2))
	{
		y = y2;
		while (y <= y1)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x2+((x1-x2)*(y-y2))/(y1-y2), y, win->color);
			y++;
		}
	}
	if (y1 <= y2 && (y2 - y1) >= abs(x2 - x1))
	{
		y = y1;
		while (y <= y2)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1+((x2-x1)*(y-y1))/(y2-y1), y, win->color);
			y++;
		}
	}
	return (1);
}

t_map	**ft_aug_size_pix(t_map	**s, int pix, int max)
{
	int i;

	i = 0;
	while(i < max)
	{
		s[i]->x = (s[i]->x * pix);
		i++;
	}
	i = 0;
		while(i < max)
	{
		s[i]->y = (s[i]->y * pix);
		i++;
	}
	return (s);
}

t_map	**ft_pos_depart(t_map	**s, int x, int y, int max)
{
	int i;

	i = 0;
	while(i < max)
	{
		s[i]->x = (s[i]->x + x);
		i++;
	}
	i = 0;
		while(i < max)
	{
		s[i]->y = (s[i]->y + y);
		i++;
	}
	return (s);
}

int		ft_create_2d(t_map **s, t_win *win)
{
	int pix;
	int i;
	int max;

	pix = 150;
	i = 0;
	max = (win->x_max * win->y_max) - 1;
	s = ft_aug_size_pix(s, pix, max);
	s = ft_pos_depart(s, 75, 75, max);
	while (i < 15)
	{
		ft_draw_line(win, s[i]->x, s[i+1]->x, s[i]->y, s[i+1]->y);
		i++;
	}
	return(0);
}