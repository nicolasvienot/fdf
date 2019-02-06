/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/06 17:12:44 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_draw_line_2(t_win *win, int i)
{
	int y;

	y = 0;
	if (win->y2 <= win->y1 && (win->y1 - win->y2) >= abs(win->x1 - win->x2))
	{
		y = win->y2;
		while (y <= win->y1)
		{
			mlx_put_pixel_to_image(win, win->x2 + ((win->x1 - win->x2) \
				* (y - win->y2)) / (win->y1 - win->y2), y, i);
			y++;
		}
	}
	if (win->y1 <= win->y2 && (win->y2 - win->y1) >= abs(win->x2 - win->x1))
	{
		y = win->y1;
		while (y <= win->y2)
		{
			mlx_put_pixel_to_image(win, win->x1 + ((win->x2 - win->x1) \
				* (y - win->y1)) / (win->y2 - win->y1), y, i);
			y++;
		}
	}
	return (1);
}

static int	ft_draw_line_1(t_win *win, int i)
{
	int x;

	x = 0;
	if (win->x1 <= win->x2 && (win->x2 - win->x1) >= abs(win->y2 - win->y1))
	{
		x = win->x1;
		while (x <= win->x2)
		{
			mlx_put_pixel_to_image(win, x, win->y1 + ((win->y2 - win->y1) \
				* (x - win->x1)) / (win->x2 - win->x1), i);
			x++;
		}
	}
	if (win->x2 <= win->x1 && (win->x1 - win->x2) >= abs(win->y1 - win->y2))
	{
		x = win->x2;
		while (x <= win->x1)
		{
			mlx_put_pixel_to_image(win, x, win->y2 + ((win->y1 - win->y2) \
				* (x - win->x2)) / (win->x1 - win->x2), i);
			x++;
		}
	}
	return (1);
}

static int	ft_draw_line(t_win *win, int i)
{
	win->x1 = win->s[i]->x_pix;
	win->y1 = win->s[i]->y_pix;
	if (win->s[i]->x == ((win->x_max) - 1))
	{
		win->x2 = win->s[i + (win->x_max)]->x_pix;
		win->y2 = win->s[i + (win->x_max)]->y_pix;
	}
	if (win->s[i]->y == ((win->y_max) - 1))
	{
		win->x2 = win->s[i + 1]->x_pix;
		win->y2 = win->s[i + 1]->y_pix;
	}
	ft_draw_line_1(win, i);
	ft_draw_line_2(win, i);
	return (1);
}

int			ft_draw(t_win *win)
{
	int i;

	i = 0;
	while (i < win->pos_max && win->s[i]->x <= ((win->x_max) - 1) && win->s[i]->y <= ((win->y_max) - 1))
	{	
		if (win->s[i]->x == ((win->x_max) - 1))
			ft_draw_line(win, i);
		if (win->s[i]->y == ((win->y_max) - 1))
			ft_draw_line(win, i);
		if (win->s[i]->y != ((win->y_max) - 1) && win->s[i]->x != ((win->x_max) - 1))
		{
			win->x2 = win->s[i + (win->x_max)]->x_pix;
			win->y2 = win->s[i + (win->x_max)]->y_pix;
			ft_draw_line(win, i);
			win->x2 = win->s[i + 1]->x_pix;
			win->y2 = win->s[i + 1]->y_pix;
			ft_draw_line(win, i);
		}
		i++;
	}
	return (1);
}
