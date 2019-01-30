/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 02:16:39 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/30 13:09:58 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key_p(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE);
	win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline,
		&win->endian);
	win->start = 0;
	if (win->proj == 1)
		win->proj = 2;
	else
		win->proj = 1;
	if (win->proj == 1)
		ft_init_pix_and_pos_orthographic_projection(win);
	else
		ft_init_pix_isometric_projection(win);
	ft_init_top(win);
	ft_init_z_and_zok(win);
	ft_init_xypix(win);
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	print_menu(win);
	return (1);
}

int	deal_key_o(int keycode, t_win *win)
{
	if (keycode == TOUCH_O)
	{
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE);
		win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline,
			&win->endian);
		win->start = 0;
		if (win->proj == 1)
			ft_init_pix_and_pos_orthographic_projection(win);
		else
			ft_init_pix_isometric_projection(win);
		ft_init_top(win);
		ft_init_z_and_zok(win);
		ft_init_xypix(win);
		ft_init_map(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
		print_menu(win);
	}
	else if (keycode == TOUCH_P)
		deal_key_p(win);
	return (1);
}

int	deal_key_page_up_n_down(int keycode, t_win *win)
{
	if (keycode == PAGE_UP)
	{
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE);
		win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline,
			&win->endian);
		win->top = 2;
		ft_init_map(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
		print_menu(win);
		ft_init_top(win);
	}
	else if (keycode == PAGE_DOWN)
	{
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE);
		win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline,
			&win->endian);
		win->top = -2;
		ft_init_map(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
		print_menu(win);
		ft_init_top(win);
	}
	return (0);
}

int	deal_key_direction(int keycode, t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE);
	win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline,
		&win->endian);
	if (keycode == ARROW_UP)
		win->ver += 10;
	if (keycode == ARROW_DOWN)
		win->ver -= 10;
	if (keycode == ARROW_RIGHT)
		win->hor -= 10;
	if (keycode == ARROW_LEFT)
		win->hor += 10;
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	print_menu(win);
	return (1);
}

int	deal_key(int keycode, t_win *win)
{
	if (keycode == TOUCH_PLUS || keycode == TOUCH_LESS)
	{
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE);
		win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline,
			&win->endian);
		if (keycode == TOUCH_PLUS)
			win->pix += 2;
		if (keycode == TOUCH_LESS)
			if (win->pix > 2)
				win->pix -= 2;
		ft_init_map(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
		print_menu(win);
	}
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		deal_key_direction(keycode, win);
	else if (keycode == PAGE_UP || keycode == PAGE_DOWN)
		deal_key_page_up_n_down(keycode, win);
	else if (keycode == TOUCH_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == TOUCH_P || keycode == TOUCH_O)
		deal_key_o(keycode, win);
	return (1);
}
