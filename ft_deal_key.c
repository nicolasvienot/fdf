/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 02:16:39 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/07 20:10:53 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key_2(int keycode, t_win *win)
{
	ft_init_refresh(win);
	if (keycode == TOUCH_O)
	{
		if (win->proj == 1)
			ft_init_pix_and_pos_orthographic_projection(win);
		else
			ft_init_pix_isometric_projection(win);
		ft_init_xypix(win);
	}
	else if (keycode == TOUCH_P)
	{
		if (win->proj == 1)
			win->proj = 2;
		else
			win->proj = 1;
		if (win->proj == 1)
			ft_init_pix_and_pos_orthographic_projection(win);
		else
			ft_init_pix_isometric_projection(win);
	}
	ft_init_xypix(win);
	return (1);
}

int	deal_key(int keycode, t_win *win)
{
	ft_refresh_img(win);
	if (keycode == TOUCH_PLUS)
		win->pix = win->pix * COEF_ZOOM;
	if (keycode == TOUCH_LESS)
		win->pix = win->pix / COEF_ZOOM;
	if (keycode == TOUCH_T)
		win->rota += 1;
	if (keycode == TOUCH_R)
		win->rota -= 1;
	if (keycode == ARROW_UP)
		win->ver += SIZE_MOV;
	if (keycode == ARROW_DOWN)
		win->ver -= SIZE_MOV;
	if (keycode == ARROW_RIGHT)
		win->hor -= SIZE_MOV;
	if (keycode == ARROW_LEFT)
		win->hor += SIZE_MOV;
	if (keycode == PAGE_UP)
		ft_altitude(win, 1);
	if (keycode == PAGE_DOWN)
		ft_altitude(win, 2);
	if (keycode == TOUCH_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == TOUCH_P || keycode == TOUCH_O)
		deal_key_2(keycode, win);
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 300, 150);
	return (1);
}
