/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_proj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:11:02 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/07 19:43:42 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_create_isometric_projection_with_z(t_win *win)
{
	int i;

	i = 0;
	while (i <= win->pos_max)
	{
		win->s[i]->z_pix = win->s[i]->z * win->zix;
		win->s[i]->x_pix = (win->s[i]->x + win->s[i]->y) * win->pix;
		win->s[i]->y_pix = (((win->s[i]->z_pix * COEF_Z) * -2) \
		+ (win->s[i]->y - win->s[i]->x)) * (win->pix / 2);
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
		win->s[i]->z_pix = win->s[i]->z * win->zix;
		if (win->s[i]->z_pix != 0)
		{
			win->s[i]->x_pix = (win->s[i]->x + win->s[i]->z_pix * COEF_Z) * win->pix;
			win->s[i]->y_pix = (win->s[i]->y + (win->s[i]->z_pix * COEF_Z / 2)) * win->pix;
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

int		ft_init_map(t_win *win)
{
	ft_get_color(win);
	if (win->proj == 2)
	{
		ft_create_isometric_projection_with_z(win);
		if (win->start == 0)
			ft_init_pos_isometric_projection(win);
		win->start = 1;
	}
	else
		ft_create_orthographic_projection_with_z(win);
	ft_rotate(win);
	ft_move_pos(win);
	ft_draw(win);
	return (0);
}