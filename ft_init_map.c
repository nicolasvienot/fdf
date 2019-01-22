/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:04:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/22 12:37:19 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_move_pos(t_win *win, int x, int y)
{
	int i;

	i = 0;
	while(i <= win->pos_max)
	{
		win->s[i]->x_pix = (win->s[i]->x_pix + x);
		win->s[i]->y_pix = (win->s[i]->y_pix + y);
		i++;
	}
	return (1);
}

int	ft_increase_pix(t_win *win, int pix)
{
	int i;

	i = 0;
	while(i <= win->pos_max)
	{
		win->s[i]->x_pix = (win->s[i]->x_pix + pix);
		win->s[i]->y_pix = (win->s[i]->y_pix + pix);
		i++;
	}
	return (1);
}

int	ft_create_isometric_projection(t_win *win, int pix)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->x_pix = (win->s[i]->x - win->s[i]->y) * pix;
		win->s[i]->y_pix = (win->s[i]->y + win->s[i]->x) * (pix / 2);
		i++;
	}
	return (1);
}

int	ft_create_orthographic_projection(t_win *win, int pix)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->x_pix = (win->s[i]->x * pix);
		win->s[i]->y_pix = (win->s[i]->y * pix);
		i++;
	}
	return (1);
}

int		ft_init_map(t_win *win)
{
	int pix;
	int i;

	pix = 50;
	i = 0;
	//ft_ceate_orthographic_projection(win, pix);
	ft_create_isometric_projection(win, pix);
	ft_move_pos(win, 500, 200);
	// //ft_increase_pix_vertical(win, 200);
	while (i < win->pos_max)
	{
		if (win->s[i]->x == ((win->x_max) - 1) && win->s[i]->y == ((win->y_max) - 1))
			break ;
		if (win->s[i]->x == ((win->x_max) - 1))
			ft_draw_line(win, win->s[i]->x_pix, win->s[i+(win->x_max)]->x_pix, win->s[i]->y_pix, win->s[i+(win->x_max)]->y_pix);
		if (win->s[i]->y == ((win->y_max) - 1))
			ft_draw_line(win, win->s[i]->x_pix, win->s[i + 1]->x_pix, win->s[i]->y_pix, win->s[i+1]->y_pix);
		if (win->s[i]->y != ((win->y_max) - 1) && win->s[i]->x != ((win->x_max) - 1))
		{
			ft_draw_line(win, win->s[i]->x_pix, win->s[i+(win->x_max)]->x_pix, win->s[i]->y_pix, win->s[i+(win->x_max)]->y_pix);
			ft_draw_line(win, win->s[i]->x_pix, win->s[i+1]->x_pix, win->s[i]->y_pix, win->s[i+1]->y_pix);
		}
		i++;
	}
	return (0);
}