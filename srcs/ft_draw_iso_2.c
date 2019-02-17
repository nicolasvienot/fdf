/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_iso_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:03:22 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/17 18:03:33 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line_2_1(t_win **win, int i)
{
	int y;

	if ((*win)->y1 <= (*win)->y2 && ((*win)->y2 - (*win)->y1)
		>= abs((*win)->x2 - (*win)->x1))
	{
		y = (*win)->y1;
		while (y <= (*win)->y2 && ((*win)->y2 - (*win)->y1) != 0)
		{
			(*win)->z = (*win)->z2 + (y - (*win)->y2)
				* ((*win)->z1 - (*win)->z2) / ((*win)->y1 - (*win)->y2);
			mlx_put_pixel_to_image(win, (*win)->x1 + (((*win)->x2 - (*win)->x1)
				* (y - (*win)->y1)) / ((*win)->y2 - (*win)->y1), y, i);
			y++;
		}
	}
}

int			ft_draw_line_2(t_win **win, int i)
{
	int y;

	if ((*win)->y2 <= (*win)->y1 && ((*win)->y1 - (*win)->y2)
		>= abs((*win)->x1 - (*win)->x2))
	{
		y = (*win)->y2;
		while (y <= (*win)->y1 && ((*win)->y1 - (*win)->y2) != 0)
		{
			(*win)->z = (*win)->z2 + (y - (*win)->y2)
				* ((*win)->z1 - (*win)->z2) / ((*win)->y1 - (*win)->y2);
			mlx_put_pixel_to_image(win, (*win)->x2 + (((*win)->x1 - (*win)->x2)
				* (y - (*win)->y2)) / ((*win)->y1 - (*win)->y2), y, i);
			y++;
		}
	}
	ft_draw_line_2_1(win, i);
	return (1);
}

static void	ft_draw_line_1_1(t_win **win, int i)
{
	int x;

	if ((*win)->x2 <= (*win)->x1 && ((*win)->x1 - (*win)->x2)
		>= abs((*win)->y1 - (*win)->y2))
	{
		x = (*win)->x2;
		while (x < (*win)->x1 && ((*win)->x1 - (*win)->x2) != 0)
		{
			(*win)->z = (*win)->z2 + (x - (*win)->x2)
				* ((*win)->z1 - (*win)->z2) / ((*win)->x1 - (*win)->x2);
			if (((*win)->x1 - (*win)->x2) > 0)
				mlx_put_pixel_to_image(win, x, (*win)->y2 + (((*win)->y1
					- (*win)->y2) * (x - (*win)->x2)) / ((*win)->x1
						- (*win)->x2), i);
			x++;
		}
	}
}

int			ft_draw_line_1(t_win **win, int i)
{
	int x;

	if ((*win)->x1 <= (*win)->x2 && ((*win)->x2 - (*win)->x1)
		>= abs((*win)->y2 - (*win)->y1))
	{
		x = (*win)->x1;
		while (x <= (*win)->x2 && ((*win)->x2 - (*win)->x1) != 0)
		{
			(*win)->z = (*win)->z2 + (x - (*win)->x2)
				* ((*win)->z1 - (*win)->z2) / ((*win)->x1 - (*win)->x2);
			mlx_put_pixel_to_image(win, x, (*win)->y1 + (((*win)->y2
				- (*win)->y1)
				* (x - (*win)->x1)) / ((*win)->x2 - (*win)->x1), i);
			x++;
		}
	}
	ft_draw_line_1_1(win, i);
	return (1);
}
