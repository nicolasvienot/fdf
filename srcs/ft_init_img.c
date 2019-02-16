/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:02:49 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/16 17:26:41 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_refresh_img(t_win **win)
{
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_ptr);
	(*win)->img_ptr = mlx_new_image((*win)->mlx_ptr, \
		IMG_HOR_SIZE, IMG_VER_SIZE);
}

void			ft_anim_background(t_win **win)
{
	if ((*win)->img == 0)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back1, 0, 0);
	if ((*win)->img == 1)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back2, 0, 0);
	if ((*win)->img == 2)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back3, 0, 0);
	if ((*win)->img == 3)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back4, 0, 0);
	if ((*win)->img == 4)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back5, 0, 0);
	if ((*win)->img == 5)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back6, 0, 0);
	if ((*win)->img == 6)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back7, 0, 0);
	if ((*win)->img == 7)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back8, 0, 0);
	if ((*win)->img == 8)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_back9, 0, 0);
}

static void		ft_fill_imgs(t_win **win, int a, int b)
{
	(*win)->img_back1 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf.xpm", &a, &b);
	(*win)->img_back2 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf2.xpm", &a, &b);
	(*win)->img_back3 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf3.xpm", &a, &b);
	(*win)->img_back4 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf4.xpm", &a, &b);
	(*win)->img_back5 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf5.xpm", &a, &b);
	(*win)->img_back6 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf6.xpm", &a, &b);
	(*win)->img_back7 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf7.xpm", &a, &b);
	(*win)->img_back8 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf8.xpm", &a, &b);
	(*win)->img_back9 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf9.xpm", &a, &b);
	(*win)->data = mlx_get_data_addr((*win)->img_ptr, &(*win)->bpp, \
		&(*win)->sizeline, &(*win)->endian);
}

void			ft_new_imgs(t_win **win)
{
	int		a;
	int		b;

	a = WIN_HOR_SIZE;
	b = WIN_VER_SIZE;
	(*win)->img_back1 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back2 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back3 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back4 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back5 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back6 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back7 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back8 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_back9 = mlx_new_image((*win)->mlx_ptr, a, b);
	(*win)->img_ptr = mlx_new_image((*win)->mlx_ptr, \
		IMG_HOR_SIZE, IMG_VER_SIZE);
	ft_fill_imgs(win, a, b);
}

void			mlx_put_pixel_to_image(t_win **win, int x, int y, int i)
{
	int		octet;
	int		a;

	octet = (*win)->bpp / 8;
	a = ft_altitude_color(win, i);
	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
	{
		ft_memcpy(&(*win)->data[octet * x + (*win)->sizeline * y], &a, octet);
	}
}
