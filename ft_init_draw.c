/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:04:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/22 12:37:19 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	**ft_move_pos(t_map **s, int x, int y, int max)
{
	int i;

	i = 0;
	while(i <= max)
	{
		s[i]->x_pix = (s[i]->x_pix + x);
		s[i]->y_pix = (s[i]->y_pix + y);
		i++;
	}
	return (s);
}

t_map	**ft_increase_pix(t_map **s, int pix, int max)
{
	int i;

	i = 0;
	while(i <= max)
	{
		s[i]->x_pix = (s[i]->x_pix + pix);
		s[i]->y_pix = (s[i]->y_pix + pix);
		i++;
	}
	return (s);
}

t_map	**ft_create_isometric_projection(t_map **s, int pix, int max)
{
	int i;

	i = 0;
	while (i <= max)
	{
		s[i]->x_pix = (s[i]->x - s[i]->y) * pix;
		s[i]->y_pix = (s[i]->y + s[i]->x) * (pix / 2);
		i++;
	}
	return (s);
}

t_map	**ft_create_orthographic_projection(t_map **s, int pix, int max)
{
	int i;

	i = 0;
	while (i <= max)
	{
		s[i]->x_pix = (s[i]->x * pix);
		s[i]->y_pix = (s[i]->y * pix);
		i++;
	}
	return (s);
}

int		ft_init_map(t_map **s, t_win *win)
{
	int pix;
	int i;

	pix = 50;
	i = 0;
	// s = ft_ceate_orthographic_projection(s, pix, win->pos_max);
	s = ft_create_isometric_projection(s, pix, win->pos_max);
	s = ft_move_pos(s, 500, 200, win->pos_max);
	// s = ft_increase_pix_vertical(s, 200, win->pos_max);
	while (i < win->pos_max)
	{
		if (s[i]->x == ((win->x_max) - 1) && s[i]->y == ((win->y_max) - 1))
			break ;
		if (s[i]->x == ((win->x_max) - 1))
			ft_draw_line(win, s[i]->x_pix, s[i+(win->x_max)]->x_pix, s[i]->y_pix, s[i+(win->x_max)]->y_pix);
		if (s[i]->y == ((win->y_max) - 1))
			ft_draw_line(win, s[i]->x_pix, s[i+1]->x_pix, s[i]->y_pix, s[i+1]->y_pix);
		if (s[i]->y != ((win->y_max) - 1) && s[i]->x != ((win->x_max) - 1))
		{
			ft_draw_line(win, s[i]->x_pix, s[i+1]->x_pix, s[i]->y_pix, s[i+1]->y_pix);
			ft_draw_line(win, s[i]->x_pix, s[i+(win->x_max)]->x_pix, s[i]->y_pix, s[i+(win->x_max)]->y_pix);
		}
		i++;
	}
	return (0);
}