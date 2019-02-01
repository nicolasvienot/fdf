/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:02:49 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/01 16:38:59 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_refresh_img(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	// win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline, &win->endian);
}

void		ft_init_img(t_win *win)
{
	int	a;
	int b;

	a = 1700;
	b = 1100;
	win->img_fond = mlx_new_image(win->mlx_ptr, 1700, 1100);
	win->img_fond = mlx_xpm_file_to_image(win->mlx_ptr, "./fdf.xpm", &a, &b);
	win->img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline, &win->endian);
}

void		mlx_put_pixel_to_image(t_win *win, int x, int y)
{
	int		octet;
	int		a;

	octet = win->bpp / 8;
	a = RGB(255, 0, 255);

	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
	{
		ft_memcpy(&win->data[octet * x + win->sizeline * y], &a, octet);
	}
}
