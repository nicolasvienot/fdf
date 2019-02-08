/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 02:16:39 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/08 17:04:31 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key_p_i_o(int keycode, t_win *win)
{
	ft_init_refresh(win);
	if (keycode == TOUCH_P)
		win->proj = 1;
	else if (keycode == TOUCH_I)
		win->proj = 2;
	if (win->proj == 1)
		ft_init_pix_and_pos_orthographic_projection(win);
	else
		ft_init_pix_isometric_projection(win);
	ft_init_xypix(win);
}

void	deal_key_2(int keycode, t_win *win)
{
	if (keycode == PAGE_UP)
		ft_altitude(win, 1);
	if (keycode == PAGE_DOWN)
		ft_altitude(win, 2);
	if (keycode == TOUCH_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == TOUCH_M)
		ft_display_menu(win);
}

int		deal_key(int keycode, t_win *win)
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
	deal_key_2(keycode, win);
	if (keycode == TOUCH_P || keycode == TOUCH_I || keycode == TOUCH_O)
		deal_key_p_i_o(keycode, win);
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 300, 150);
	return (1);
}
