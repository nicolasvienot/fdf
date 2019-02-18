/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 02:16:39 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/18 14:33:23 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	deal_key_p_i_o(int keycode, t_win **win)
{
	ft_init_refresh(win);
	if (keycode == TOUCH_P)
		(*win)->proj = 1;
	else if (keycode == TOUCH_I)
		(*win)->proj = 2;
	else if (keycode == TOUCH_O)
		(*win)->img = 0;
	if ((*win)->proj == 1)
		ft_init_pix_and_pos_orthographic_projection(win);
	else
		ft_init_pix_isometric_projection(win);
	ft_anim_background(win);
	ft_print_menu(win);
	ft_init_xypix(win);
}

static void	deal_key_2(int keycode, t_win **win)
{
	(keycode == TOUCH_ESC) ? ft_free_n_exit_win(win) : 0;
	if (keycode == PAGE_UP)
		ft_altitude(win, 1);
	else if (keycode == PAGE_DOWN)
		ft_altitude(win, 2);
	else if (keycode == TOUCH_M)
		ft_display_menu(win);
	else if (keycode == TOUCH_C)
	{
		if ((*win)->choosecolor == 2)
			(*win)->choosecolor = 0;
		else
			(*win)->choosecolor = (*win)->choosecolor + 1;
		ft_anim_background(win);
		ft_print_menu(win);
	}
	else if (keycode == TOUCH_STAR)
	{
		if ((*win)->img == 8)
			(*win)->img = 0;
		else
			(*win)->img = (*win)->img + 1;
		ft_anim_background(win);
		ft_print_menu(win);
	}
}

static void	deal_key_1(int keycode, t_win **win)
{
	if (keycode == TOUCH_PLUS && (*win)->pix < MAX_ZOOM)
		(*win)->pix = (*win)->pix * COEF_ZOOM;
	else if (keycode == TOUCH_LESS && (*win)->pix > MIN_ZOOM)
		(*win)->pix = (*win)->pix / COEF_ZOOM;
	else if (keycode == TOUCH_T)
		(*win)->rota += COEF_ROTA;
	else if (keycode == TOUCH_R)
		(*win)->rota -= COEF_ROTA;
	else if (keycode == ARROW_DOWN && (*win)->s[(*win)->x_max - 1]->y_pix
		< IMG_VER_SIZE)
		(*win)->ver += SIZE_MOV;
	else if (keycode == ARROW_UP && (*win)->s[(*win)->pos_max
		- ((*win)->x_max - 1)]->y_pix > 0)
		(*win)->ver -= SIZE_MOV;
	else if (keycode == ARROW_LEFT && (*win)->s[(*win)->pos_max]->x_pix > 0)
		(*win)->hor -= SIZE_MOV;
	else if (keycode == ARROW_RIGHT && (*win)->s[0]->x_pix < IMG_HOR_SIZE)
		(*win)->hor += SIZE_MOV;
}

static int	tab_init(int keycode)
{
	int		tab[17];

	tab[0] = 8;
	tab[1] = 15;
	tab[2] = 17;
	tab[3] = 31;
	tab[4] = 34;
	tab[5] = 35;
	tab[6] = 46;
	tab[7] = 53;
	tab[8] = 67;
	tab[9] = 69;
	tab[10] = 78;
	tab[11] = 116;
	tab[12] = 121;
	tab[13] = 123;
	tab[14] = 124;
	tab[15] = 125;
	tab[16] = 126;
	return (ft_data_in_tab(tab, keycode, 17));
}

int			deal_key(int keycode, t_win **win)
{
	if (!tab_init(keycode))
		return (0);
	if (keycode == TOUCH_M || keycode == TOUCH_STAR)
	{
		deal_key_2(keycode, win);
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr,
		(*win)->img_ptr, 300, 150);
		return (1);
	}
	ft_refresh_img(win);
	if (keycode == TOUCH_PLUS || keycode == TOUCH_LESS || keycode == TOUCH_T
		|| keycode == TOUCH_R || keycode == ARROW_RIGHT || keycode == ARROW_LEFT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		deal_key_1(keycode, win);
	else if (keycode == PAGE_UP || keycode == PAGE_DOWN || keycode == TOUCH_ESC
		|| keycode == TOUCH_C)
		deal_key_2(keycode, win);
	else if (keycode == TOUCH_P || keycode == TOUCH_I || keycode == TOUCH_O)
		deal_key_p_i_o(keycode, win);
	ft_create_proj(win);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr,
		(*win)->img_ptr, 300, 150);
	return (1);
}
