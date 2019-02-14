/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/14 00:23:28 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_draw_line_2(t_win **win, int i)
{
	int y;

	if ((*win)->y2 <= (*win)->y1 && ((*win)->y1 - (*win)->y2) >= abs((*win)->x1 - (*win)->x2))
	{
		y = (*win)->y2;
		while (y <= (*win)->y1 && ((*win)->y1 - (*win)->y2) != 0)
		{
			mlx_put_pixel_to_image(win, (*win)->x2 + (((*win)->x1 - (*win)->x2) \
				* (y - (*win)->y2)) / ((*win)->y1 - (*win)->y2), y, i);
			y++;
		}
	}
	if ((*win)->y1 <= (*win)->y2 && ((*win)->y2 - (*win)->y1) >= abs((*win)->x2 - (*win)->x1))
	{
		y = (*win)->y1;
		while (y <= (*win)->y2 && ((*win)->y2 - (*win)->y1) != 0)
		{
			(*win)->z = (*win)->z2 + (y - (*win)->y2) * ((*win)->z1 - (*win)->z2) / ((*win)->y1 - (*win)->y2);
			mlx_put_pixel_to_image(win, (*win)->x1 + (((*win)->x2 - (*win)->x1) \
				* (y - (*win)->y1)) / ((*win)->y2 - (*win)->y1), y, i);
			y++;
		}
	}
	return (1);
}

static int	ft_draw_line_1(t_win **win, int i)
{
	int x;

	if ((*win)->x1 <= (*win)->x2 && ((*win)->x2 - (*win)->x1) >= abs((*win)->y2 - (*win)->y1))
	{
		x = (*win)->x1;
		while (x <= (*win)->x2 && ((*win)->x2 - (*win)->x1) != 0)
		{
			(*win)->z = (*win)->z2 + (x - (*win)->x2) * ((*win)->z1 - (*win)->z2) / ((*win)->x1 - (*win)->x2);
			mlx_put_pixel_to_image(win, x, (*win)->y1 + (((*win)->y2 - (*win)->y1) \
				* (x - (*win)->x1)) / ((*win)->x2 - (*win)->x1), i);
			x++;
		}
	}
	if ((*win)->x2 <= (*win)->x1 && ((*win)->x1 - (*win)->x2) >= abs((*win)->y1 - (*win)->y2))
	{
		x = (*win)->x2;
		while (x < (*win)->x1 && ((*win)->x1 - (*win)->x2) != 0)
		{
			if (((*win)->x1 - (*win)->x2) > 0)
				mlx_put_pixel_to_image(win, x, (*win)->y2 + (((*win)->y1 - (*win)->y2) \
					* (x - (*win)->x2)) / ((*win)->x1 - (*win)->x2), i);
			x++;
		}
	}
	return (1);
}

static int	ft_draw_line(t_win **win, int i)
{
	(*win)->x1 = (*win)->s[i]->x_pix;
	(*win)->y1 = (*win)->s[i]->y_pix;
	(*win)->z1 = (*win)->s[i]->z_pix;
	if ((*win)->s[i]->x == (((*win)->x_max) - 1))
	{
		(*win)->x2 = (*win)->s[i + ((*win)->x_max)]->x_pix;
		(*win)->y2 = (*win)->s[i + ((*win)->x_max)]->y_pix;
		(*win)->z2 = (*win)->s[i + ((*win)->x_max)]->z_pix;
	}
	if ((*win)->s[i]->y == (((*win)->y_max) - 1))
	{
		(*win)->x2 = (*win)->s[i + 1]->x_pix;
		(*win)->y2 = (*win)->s[i + 1]->y_pix;
		(*win)->z2 = (*win)->s[i + 1]->z_pix;
	}
	ft_draw_line_1(win, i);
	ft_draw_line_2(win, i);
	return (1);
}

int			ft_draw(t_win **win)
{
	int i;

	i = 0;
	if ((*win)->pos_max == 0)
		mlx_put_pixel_to_image(win, (*win)->s[i]->x_pix, (*win)->s[i]->y_pix, i);
	while (i < (*win)->pos_max && (*win)->s[i]->x <= (((*win)->x_max) - 1) \
		&& (*win)->s[i]->y <= (((*win)->y_max) - 1))
	{
		if ((*win)->s[i]->x == (((*win)->x_max) - 1))
			ft_draw_line(win, i);
		if ((*win)->s[i]->y == (((*win)->y_max) - 1))
			ft_draw_line(win, i);
		if ((*win)->s[i]->y != (((*win)->y_max) - 1) \
			&& (*win)->s[i]->x != (((*win)->x_max) - 1))
		{
			(*win)->x2 = (*win)->s[i + ((*win)->x_max)]->x_pix;
			(*win)->y2 = (*win)->s[i + ((*win)->x_max)]->y_pix;
			(*win)->z2 = (*win)->s[i + ((*win)->x_max)]->z_pix;
			ft_draw_line(win, i);
			(*win)->x2 = (*win)->s[i + 1]->x_pix;
			(*win)->y2 = (*win)->s[i + 1]->y_pix;
			(*win)->z2 = (*win)->s[i + 1]->z_pix;
			ft_draw_line(win, i);
		}
		i++;
	}
	return (1);
}
