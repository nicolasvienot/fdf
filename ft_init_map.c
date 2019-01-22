/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:04:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/22 21:07:05 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_move_pos(t_win *win)
{
	int i;

	i = 0;
	while(i <= win->pos_max)
	{
		win->s[i]->x_pix = (win->s[i]->x_pix + win->hor);
		win->s[i]->y_pix = (win->s[i]->y_pix + win->ver);
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

int	ft_create_isometric_projection_with_z(t_win *win, int pix)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		if (win->s[i]->zok == 1)
			win->s[i]->z += win->top;
		win->s[i]->x_pix = (win->s[i]->x - win->s[i]->y) * pix;
		win->s[i]->y_pix = ((win->s[i]->z) * -2)+ (win->s[i]->y + win->s[i]->x) * (pix / 2);
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

int ft_init_pix(t_win *win)
{
	win->pix = 15;
	return (1);
}

int ft_init_pos(t_win *win)
{
	win->hor = 750;
	win->ver = 200;
	return (1);
}

int ft_init_top(t_win *win)
{
	win->top = 0;
	return (1);
}

int ft_init_zok(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		if (win->s[i]->z != 0)
			win->s[i]->zok = 1;
		else
			win->s[i]->zok = 0;
		i++;
	}
	return (1);
}

int		ft_init_map(t_win *win)
{
	int i;

	i = 0;
	// if (proj == 1)
	// {
	// 	s = ft_create_orthographic_projection(s, pix, win->pos_max);
	// 	s = ft_move_pos(s, 100, 100, win->pos_max);
	// 	// s = ft_increase_pix(s, 10, win->pos_max);
	// }
	// else
	// {
	// 	s = ft_create_isometric_projection(s, pix, win->pos_max);
	// 	s = ft_move_pos(s, 500, 200, win->pos_max);
	// 	// s = ft_increase_pix(s, 200, win->pos_max);
	// }
	
	ft_create_isometric_projection_with_z(win, win->pix);
	ft_move_pos(win);

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