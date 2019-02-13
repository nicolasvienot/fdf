/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 02:16:39 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/12 21:30:52 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key_p_i_o(int keycode, t_win **win)
{
	ft_init_refresh(win);
	if (keycode == TOUCH_P)
		(*win)->proj = 1;
	else if (keycode == TOUCH_I)
		(*win)->proj = 2;
	if ((*win)->proj == 1)
		ft_init_pix_and_pos_orthographic_projection(win);
	else
		ft_init_pix_isometric_projection(win);
	ft_init_xypix(win);
}

void	deal_key_2(int keycode, t_win **win)
{
	if (keycode == PAGE_UP)
		ft_altitude(win, 1);
	if (keycode == PAGE_DOWN)
		ft_altitude(win, 2);
	if (keycode == TOUCH_ESC)
	{
		free_struct(win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == TOUCH_M)
		ft_display_menu(win);
}

int		deal_key(int keycode, t_win **win)
{
	ft_refresh_img(win);
	if (keycode == TOUCH_PLUS)
		(*win)->pix = (*win)->pix * COEF_ZOOM;
	if (keycode == TOUCH_LESS && (*win)->pix > MIN_ZOOM)
		(*win)->pix = (*win)->pix / COEF_ZOOM;
	if (keycode == TOUCH_T)
		(*win)->rota += COEF_ROTA;
	if (keycode == TOUCH_R)
		(*win)->rota -= COEF_ROTA;
	if (keycode == ARROW_DOWN && (*win)->s[(*win)->x_max - 1]->y_pix < IMG_VER_SIZE)
		(*win)->ver += SIZE_MOV;
	if (keycode == ARROW_UP && (*win)->s[(*win)->pos_max - \
		((*win)->x_max - 1)]->y_pix > 0)
		(*win)->ver -= SIZE_MOV;
	if (keycode == ARROW_LEFT && (*win)->s[(*win)->pos_max]->x_pix > 0)
		(*win)->hor -= SIZE_MOV;
	if (keycode == ARROW_RIGHT && (*win)->s[0]->x_pix < IMG_HOR_SIZE)
		(*win)->hor += SIZE_MOV;
	deal_key_2(keycode, win);
	if (keycode == TOUCH_P || keycode == TOUCH_I || keycode == TOUCH_O)
		deal_key_p_i_o(keycode, win);
	ft_init_map(win);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	return (1);
}
