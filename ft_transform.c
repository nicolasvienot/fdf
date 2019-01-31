/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:29:59 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/31 20:28:15 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_move_pos(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->x_pix = (win->s[i]->x_pix + win->hor);
		win->s[i]->y_pix = (win->s[i]->y_pix + win->ver);
		i++;
	}
	return (1);
}

int		ft_rotate(t_win *win)
{
	int i;
	int a;
	int b;

	if (win->proj == 1)
	{
		a = (win->s[win->x_max - 1]->x_pix - win->s[0]->x_pix) / 2;
		b = (win->s[(win->pos_max - win->x_max - 1)]->y_pix \
		- win->s[0]->y_pix) / 2;
	}
	else
	{
		a = ((win->s[win->pos_max]->x_pix - win->s[0]->x_pix) / 2);
		b = win->s[0]->y;
	}
	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->xpix2 = win->s[i]->x_pix;
		win->s[i]->x_pix = a + (win->s[i]->x_pix - a) * cos(THETA * win->rota) \
		- (win->s[i]->y_pix - b) * sin(THETA * win->rota);
		win->s[i]->y_pix = b + (win->s[i]->xpix2 - a) * sin(THETA * win->rota) \
		+ (win->s[i]->y_pix - b) * cos(THETA * win->rota);
		i++;
	}
	return (1);
}

// int		ft_increase_pix(t_win *win, int pix)
// {
// 	int i;

// 	i = 0;
// 	while (i <= win->pos_max)
// 	{
// 		win->s[i]->x_pix = (win->s[i]->x_pix + pix);
// 		win->s[i]->y_pix = (win->s[i]->y_pix + pix);
// 		win->s[i]->z_pix = (win->s[i]->z_pix + pix);
// 		i++;
// 	}
// 	return (1);
// }

int		ft_get_color(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		if (win->s[i]->color == 0)
			win->s[i]->color = RGB(255, 0, 255);
		i++;
	}
	return (1);
}

