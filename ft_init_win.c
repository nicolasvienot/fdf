/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:46:19 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/08 15:18:37 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_start(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_HOR_SIZE, \
		WIN_VER_SIZE, "FDF");
	win->start = 0;
	win->proj = 1;
	win->rota = 0;
	win->aff_x = 0;
	win->aff_y = 0;
	win->zix = 1;
}

void	ft_init_refresh(t_win *win)
{
	win->start = 0;
	win->rota = 0;
	win->aff_x = 0;
	win->aff_y = 0;
	win->zix = 1;
}
