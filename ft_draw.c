/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/31 21:12:02 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_draw_line_2(t_win *win, int x1, int x2, int y1, int y2)
{
	int y;

	y = 0;
	if (y2 <= y1 && (y1 - y2) >= abs(x1 - x2))
	{
		y = y2;
		while (y <= y1)
		{
			mlx_put_pixel_to_image(win, x2 + ((x1 - x2) \
				* (y - y2)) / (y1 - y2), y);
			y++;
		}
	}
	if (y1 <= y2 && (y2 - y1) >= abs(x2 - x1))
	{
		y = y1;
		while (y <= y2)
		{
			mlx_put_pixel_to_image(win, x1 + ((x2 - x1) \
				* (y - y1)) / (y2 - y1), y);
			y++;
		}
	}
	return (1);
}

int		ft_draw_line_1(t_win *win, int x1, int x2, int y1, int y2)
{
	int x;

	x = 0;
	if (x1 <= x2 && (x2 - x1) >= abs(y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			mlx_put_pixel_to_image(win, x, y1 + ((y2 - y1) \
				* (x - x1)) / (x2 - x1));
			x++;
		}
	}
	if (x2 <= x1 && (x1 - x2) >= abs(y1 - y2))
	{
		x = x2;
		while (x <= x1)
		{
			mlx_put_pixel_to_image(win, x, y2 + ((y1 - y2) \
				* (x - x2)) / (x1 - x2));
			x++;
		}
	}
	return (1);
}

int		ft_draw_line(t_win *win, int x1, int x2, int y1, int y2)
{
	ft_draw_line_1(win, x1, x2, y1, y2);
	ft_draw_line_2(win, x1, x2, y1, y2);
	return (1);
}

int		ft_draw(t_win *win)
{
	int i;

	i = 0;
	while (i < win->pos_max)
	{
		if (win->s[i]->x == ((win->x_max) - 1) \
			&& win->s[i]->y == ((win->y_max) - 1))
			break ;
		if (win->s[i]->x == ((win->x_max) - 1))
			ft_draw_line(win, win->s[i]->x_pix, win->s[i \
				+ (win->x_max)]->x_pix, win->s[i]->y_pix, \
					win->s[i + (win->x_max)]->y_pix);
		if (win->s[i]->y == ((win->y_max) - 1))
			ft_draw_line(win, win->s[i]->x_pix, win->s[i + 1]->x_pix, \
				win->s[i]->y_pix, win->s[i + 1]->y_pix);
		if (win->s[i]->y != ((win->y_max) - 1) \
			&& win->s[i]->x != ((win->x_max) - 1))
		{
			ft_draw_line(win, win->s[i]->x_pix, \
				win->s[i + (win->x_max)]->x_pix, win->s[i]->y_pix, \
					win->s[i + (win->x_max)]->y_pix);
			ft_draw_line(win, win->s[i]->x_pix, win->s[i + 1]->x_pix, \
				win->s[i]->y_pix, win->s[i + 1]->y_pix);
		}
		i++;
	}
	return (1);
}
