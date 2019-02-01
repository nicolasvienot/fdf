/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 02:16:39 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/01 16:38:15 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	deal_key_rotate(int keycode, t_win *win)
{
	ft_refresh_img(win);
	if (keycode == TOUCH_T)
		win->rota += 1;
	if (keycode == TOUCH_R)
		win->rota -= 1;
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 300, 150);
	return (1);
}

static int	deal_key_o_and_p(int keycode, t_win *win)
{
	ft_refresh_img(win);
	ft_init_refresh(win);
	if (keycode == TOUCH_O)
	{
		if (win->proj == 1)
			ft_init_pix_and_pos_orthographic_projection(win);
		else
			ft_init_pix_isometric_projection(win);
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
	ft_init_z_and_zok(win);
	ft_init_xypix(win);
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 300, 150);
	return (1);
}

static int	deal_key_page_up_n_down(int keycode, t_win *win)
{
	if (keycode == PAGE_UP)
	{
		ft_refresh_img(win);
		win->top = 2;
		ft_init_map(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->img_ptr, 300, 150);
		win->top = 1;
	}
	else if (keycode == PAGE_DOWN)
	{
		ft_refresh_img(win);
		win->top = -2;
		ft_init_map(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->img_ptr, 300, 150);
		win->top = 1;
	}
	return (0);
}

static int	deal_key_direction(int keycode, t_win *win)
{
	ft_refresh_img(win);
	if (keycode == ARROW_UP)
		win->ver += 10;
	if (keycode == ARROW_DOWN)
		win->ver -= 10;
	if (keycode == ARROW_RIGHT)
		win->hor -= 10;
	if (keycode == ARROW_LEFT)
		win->hor += 10;
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->img_ptr, 300, 150);
	return (1);
}

int			deal_key(int keycode, t_win *win)
{
	if (keycode == TOUCH_PLUS || keycode == TOUCH_LESS)
	{
		ft_refresh_img(win);
		if (keycode == TOUCH_PLUS)
			win->pix += 2;
		if (keycode == TOUCH_LESS)
			if (win->pix > 4)
				win->pix -= 2;
		ft_init_map(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->img_ptr, 300, 150);
	}
	else if (keycode == TOUCH_R || keycode == TOUCH_T)
		deal_key_rotate(keycode, win);
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		deal_key_direction(keycode, win);
	else if (keycode == PAGE_UP || keycode == PAGE_DOWN)
		deal_key_page_up_n_down(keycode, win);
	else if (keycode == TOUCH_P || keycode == TOUCH_O)
		deal_key_o_and_p(keycode, win);
	else if (keycode == TOUCH_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}
