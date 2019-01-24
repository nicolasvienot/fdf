/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:04:55 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/24 19:26:50 by nvienot          ###   ########.fr       */
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

int	ft_create_isometric_projection_with_z(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		// if (win->s[i]->zok == 1)
		// {
			if (win->top == 2)
				win->s[i]->z_pix = win->s[i]->z_pix * 2;
			if (win->top == -2)
				win->s[i]->z_pix = win->s[i]->z_pix / 2;
			win->s[i]->x_pix = (win->s[i]->x + win->s[i]->y) * win->pix;
			win->s[i]->y_pix = ((win->s[i]->z_pix) * -2) + (win->s[i]->y - win->s[i]->x) * (win->pix / 2);
		// }
		// else
		// {	win->s[i]->x_pix = (win->s[i]->x - win->s[i]->y) * pix;
		// 	win->s[i]->y_pix = ((win->s[i]->z) * -2)+ (win->s[i]->y + win->s[i]->x) * (pix / 2);
		// }
		i++;
	}
	return (1);
}

int	ft_create_orthographic_projection_with_z(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		if (win->top == 2)
			win->s[i]->z_pix = win->s[i]->z_pix * 1.5;
		if (win->top == -2)
			win->s[i]->z_pix = win->s[i]->z_pix / 1.5;
		if (win->s[i]->z_pix != 0)
		{
			win->s[i]->x_pix = (win->s[i]->x + win->s[i]->z_pix * 0.1) * win->pix;
			win->s[i]->y_pix = (win->s[i]->y + (win->s[i]->z_pix * -0.1 / 2)) * win->pix;
		}
		else
		{
			win->s[i]->x_pix = (win->s[i]->x * win->pix);
			win->s[i]->y_pix = (win->s[i]->y * win->pix);
		}
		i++;
	}
	return (1);
}

int ft_init_pix(t_win *win)
{
	win->pix = 15;
	return (1);
}

int	ft_create_orthographic_projection(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->x_pix = (win->s[i]->x * win->pix);
		win->s[i]->y_pix = (win->s[i]->y * win->pix);
		i++;
	}
	return (1);
}

int ft_init_pix_and_pos_orthographic_projection(t_win *win)
{
	int a;
	int b;

	a = (WIN_HOR_SIZE - (WIN_HOR_SIZE / 10)) / win->x_max;
	b = (WIN_VER_SIZE - (WIN_VER_SIZE / 10)) / win->y_max;
	if (a <= b)
		win->pix = a;
	else
		win->pix = b; 
	win->hor = (WIN_HOR_SIZE - ((win->x_max  - 1) * win->pix)) / 2;
	win->ver = (WIN_VER_SIZE - ((win->y_max - 1) * win->pix)) / 2;
	return (1);
}

int ft_init_pix_isometric_projection(t_win *win)
{
	int a;
	int b;

	a = (WIN_HOR_SIZE - (WIN_HOR_SIZE / 3)) / win->x_max;
	b = (WIN_VER_SIZE - (WIN_HOR_SIZE / 6)) / win->y_max;
	if (a <= b)
		win->pix = a;
	else
		win->pix = b; 
	// win->hor = (WIN_HOR_SIZE - ((win->s[win->pos_max]->x - win->s[0]->x) * win->pix)) / 2;
	// win->ver = WIN_VER_SIZE - ((win->s[win->x_max]->y - win->s[(win->pos_max - win->x_max)]->y) * win->pix) / 2;
	return (1);
}

int	ft_init_pos_isometric_projection(t_win *win)
{
	win->hor = (WIN_HOR_SIZE - (win->s[win->pos_max]->x_pix - win->s[0]->x_pix)) / 2;
	win->ver = (WIN_VER_SIZE - (win->s[(win->pos_max - (win->x_max - 1))]->y_pix) - win->s[(win->x_max - 1)]->y_pix) / 2;
	return (1);
}

// int ft_init_pos(t_win *win)
// {
// 	// win->hor = 750;
// 	// win->ver = 200;
// 	win->hor = 100;
// 	win->ver = 100;
// 	return (1);
// }

int ft_init_top(t_win *win)
{
	win->top = 1;
	return (1);
}

int ft_init_z_and_zok(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		// if (win->s[i]->z != 0)
		// 	win->s[i]->zok = 1;
		// else
		// 	win->s[i]->zok = 0;
		win->s[i]->z_pix = win->s[i]->z;
		i++;
	}
	return (1);
}

int ft_init_xypix(t_win *win)
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
	// ft_create_orthographic_projection(win);
	// ft_create_orthographic_projection_with_z(win);
	if (win->proj == 2)
	{
		ft_create_isometric_projection_with_z(win);
		if (win->start == 0)
			ft_init_pos_isometric_projection(win);
		win->start = 1;
	}
	else
		ft_create_orthographic_projection_with_z(win);

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