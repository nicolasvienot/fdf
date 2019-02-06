/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_proj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:04:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/06 02:55:39 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_pix_and_pos_orthographic_projection(t_win *win)
{
	int a;
	int b;

	a = (IMG_HOR_SIZE - (IMG_HOR_SIZE / 5)) / win->x_max;
	b = (IMG_VER_SIZE - (IMG_VER_SIZE / 5)) / win->y_max;
	if (a <= b && a > 2)
		win->pix = a;
	if (a >= b && b > 2)
		win->pix = b;
	if (a < 2 && b < 2)
		win->pix = 2;
	win->hor = (IMG_HOR_SIZE - ((win->x_max - 1) * win->pix)) / 2;
	win->ver = (IMG_VER_SIZE - ((win->y_max - 1) * win->pix)) / 2;
	return (1);
}

int		ft_init_pix_isometric_projection(t_win *win)
{
	int a;
	int b;

	a = (IMG_HOR_SIZE - (IMG_HOR_SIZE / 2)) / win->x_max;
	b = (IMG_VER_SIZE - (IMG_HOR_SIZE / 3)) / win->y_max;
	if (a <= b && a > 2)
		win->pix = a;
	if (b <= a && b > 2)
		win->pix = b;
	if (a < 2 && b < 2)
		win->pix = 2;
	return (1);
}

int		ft_init_pos_isometric_projection(t_win *win)
{
	win->hor = (IMG_HOR_SIZE - (win->s[win->pos_max]->x_pix \
		- win->s[0]->x_pix)) / 2;
	win->ver = (IMG_VER_SIZE - (win->s[(win->pos_max \
		- (win->x_max - 1))]->y_pix) \
			- win->s[(win->x_max - 1)]->y_pix) / 2;
	return (1);
}

int		ft_init_z_and_zok(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->z_pix = win->s[i]->z;
		i++;
	}
	return (1);
}

int		ft_init_xypix(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->x_pix = 0;
		win->s[i]->y_pix = 0;
		i++;
	}
	return (1);
}
