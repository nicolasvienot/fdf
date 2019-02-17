/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_para.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/17 17:25:55 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx_put_pixel_to_image(t_win **win, int x, int y, int i)
{
	int		octet;
	int		a;

	octet = (*win)->bpp / 8;
	a = ft_altitude_color(win, i);
	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
	{
		if (!(ft_memcpy(&(*win)->data[octet * x + (*win)->sizeline * y], \
			&a, octet)))
			ft_exit_error(-42);
	}
}

static void	ft_draw_line_para(t_win **win, int i)
{
	(*win)->x1 = (*win)->s[i]->x_pix;
	(*win)->y1 = (*win)->s[i]->y_pix;
	(*win)->z1 = (*win)->s[i]->z_pix;
	if ((*win)->s[i]->x == 0)
	{
		(*win)->x2 = (*win)->s[i - ((*win)->x_max)]->x_pix;
		(*win)->y2 = (*win)->s[i - ((*win)->x_max)]->y_pix;
		(*win)->z2 = (*win)->s[i - ((*win)->x_max)]->z_pix;
	}
	if ((*win)->s[i]->y == 0)
	{
		(*win)->x2 = (*win)->s[i - 1]->x_pix;
		(*win)->y2 = (*win)->s[i - 1]->y_pix;
		(*win)->z2 = (*win)->s[i - 1]->z_pix;
	}
	ft_draw_line_1(win, i);
	ft_draw_line_2(win, i);
}

static void	ft_draw_para_2(t_win **win, int i)
{
	(*win)->x2 = (*win)->s[i - ((*win)->x_max)]->x_pix;
	(*win)->y2 = (*win)->s[i - ((*win)->x_max)]->y_pix;
	(*win)->z2 = (*win)->s[i - ((*win)->x_max)]->z_pix;
	ft_draw_line_para(win, i);
	(*win)->x2 = (*win)->s[i - 1]->x_pix;
	(*win)->y2 = (*win)->s[i - 1]->y_pix;
	(*win)->z2 = (*win)->s[i - 1]->z_pix;
	ft_draw_line_para(win, i);
}

int			ft_draw_para(t_win **win)
{
	int i;

	i = (*win)->pos_max;
	if (i == 0)
		mlx_put_pixel_to_image(win, (*win)->s[i]->x_pix, \
			(*win)->s[i]->y_pix, i);
	while (i > 0 && (*win)->s[i]->x <= (((*win)->x_max) - 1) \
		&& (*win)->s[i]->y <= (((*win)->y_max) - 1))
	{
		if ((*win)->s[i]->x == 0)
			ft_draw_line_para(win, i);
		if ((*win)->s[i]->y == 0)
			ft_draw_line_para(win, i);
		if ((*win)->s[i]->y != 0 && (*win)->s[i]->x != 0)
			ft_draw_para_2(win, i);
		i--;
	}
	return (1);
}
