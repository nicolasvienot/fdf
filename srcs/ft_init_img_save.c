/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:02:49 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/13 19:12:15 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_refresh_img(t_win **win)
{
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_ptr);
	(*win)->img_ptr = mlx_new_image((*win)->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
}

void		ft_refresh_background(t_win **win)
{
	if ((*win)->proj == 1)
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_background, 0, 0);
	else
		mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
			(*win)->img_background2, 0, 0);
	
}

void		ft_anim_background(t_win **win)
{
		if ((*win)->i == 0)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 1)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background2, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 2)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background2);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background3, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 3)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background4, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 4)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background5, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 5)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background6, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 6)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background7, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 7)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background8, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 8)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background9, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 9)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background10, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 10)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background11, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 11)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background12, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
		if ((*win)->i == 12)
		{
			// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
				(*win)->img_background13, 0, 0);
			ft_print_menu(win);
			mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
		}
	// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background2, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background2);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background3, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background3);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background4, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background4);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background5, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background6, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background7, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background8, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background9, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background10, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background11, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background12, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background13, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);	
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	// 	(*win)->img_background, 0, 0);
	// ft_print_menu(win);
	// mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);	
}

// void		ft_anim_background2(t_win **win)
// {
// 	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
// 		(*win)->img_background2, 0, 0);
// 	ft_print_menu(win);
// 	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
// 	sleep(1);
// 	ft_anim_background3(win);
// }

// void		ft_anim_background3(t_win **win)
// {
// 	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
// 		(*win)->img_background3, 0, 0);
// 	ft_print_menu(win);
// 	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, (*win)->img_ptr, 300, 150);
// 	sleep(1);
// }

void		ft_init_img(t_win **win)
{
	int	a;
	int b;

	a = 1700;
	b = 1100;
	(*win)->img_background = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf.xpm", &a, &b);
	(*win)->img_background2 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background2 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf2.xpm", &a, &b);
	(*win)->img_background3 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background3 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf3.xpm", &a, &b);
	(*win)->img_background4 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background4 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf4.xpm", &a, &b);
	(*win)->img_background5 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background5 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf5.xpm", &a, &b);
	(*win)->img_background6 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background6 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf6.xpm", &a, &b);
	(*win)->img_background7 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background7 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf7.xpm", &a, &b);
	(*win)->img_background8 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background8 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf8.xpm", &a, &b);
	(*win)->img_background9 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background9 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf9.xpm", &a, &b);
	(*win)->img_background10 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background10 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf10.xpm", &a, &b);
	(*win)->img_background11 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background11 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf11.xpm", &a, &b);
	(*win)->img_background12 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background12 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf12.xpm", &a, &b);
	(*win)->img_background13 = mlx_new_image((*win)->mlx_ptr, 1700, 1100);
	(*win)->img_background13 = mlx_xpm_file_to_image((*win)->mlx_ptr, \
		"imgs/fdf13.xpm", &a, &b);
	(*win)->img_ptr = mlx_new_image((*win)->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	(*win)->data = mlx_get_data_addr((*win)->img_ptr, &(*win)->bpp, \
		&(*win)->sizeline, &(*win)->endian);
	ft_init_xypix(win);
}

void		mlx_put_pixel_to_image(t_win **win, int x, int y, int i)
{
	int		octet;
	int		a;

	octet = (*win)->bpp / 8;
	a = (*win)->s[i]->color;
	if (x >= 0 && y >= 0 && x < IMG_HOR_SIZE && y < IMG_VER_SIZE)
	{
		ft_memcpy(&(*win)->data[octet * x + (*win)->sizeline * y], &a, octet);
	}
}