/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/16 17:28:08 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line_iso(t_win **win, int i)
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
}

static void	ft_draw_iso_2(t_win **win, int i)
{
	if ((*win)->s[i]->y != (((*win)->y_max) - 1) \
		&& (*win)->s[i]->x != (((*win)->x_max) - 1))
	{
		(*win)->x2 = (*win)->s[i + ((*win)->x_max)]->x_pix;
		(*win)->y2 = (*win)->s[i + ((*win)->x_max)]->y_pix;
		(*win)->z2 = (*win)->s[i + ((*win)->x_max)]->z_pix;
		ft_draw_line_iso(win, i);
		(*win)->x2 = (*win)->s[i + 1]->x_pix;
		(*win)->y2 = (*win)->s[i + 1]->y_pix;
		(*win)->z2 = (*win)->s[i + 1]->z_pix;
		ft_draw_line_iso(win, i);
	}
}

int			ft_draw_iso(t_win **win)
{
	int i;

	i = 0;
	if ((*win)->pos_max == 0)
		mlx_put_pixel_to_image(win, (*win)->s[i]->x_pix,
			(*win)->s[i]->y_pix, i);
	while (i < (*win)->pos_max && (*win)->s[i]->x <= (((*win)->x_max) - 1) \
		&& (*win)->s[i]->y <= (((*win)->y_max) - 1))
	{
		if ((*win)->s[i]->x == (((*win)->x_max) - 1))
			ft_draw_line_iso(win, i);
		if ((*win)->s[i]->y == (((*win)->y_max) - 1))
			ft_draw_line_iso(win, i);
		ft_draw_iso_2(win, i);
		i++;
	}
	return (1);
}
