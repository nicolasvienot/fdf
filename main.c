/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/06 20:22:29 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_mouse(int button, int a, int b, t_win *win)
{
	win->aff_x = a;
	win->aff_y = b;
	ft_refresh_img(win);
	ft_refresh_background(win);
	ft_print_menu(win);
	if (button == 5)
		win->pix = win->pix * 1.2;
	if (button == 4)
		win->pix = win->pix / 1.2;
	ft_putnbr(win->pix);
	ft_putchar('\n');
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 300, 150);
	return (1);
}

// int	deal_expose(t_win *win)
// {
// 	return (1);
// }

int		loop_hook(t_win *win)
{
	mlx_key_hook(win->win_ptr, deal_key, win);
	// mlx_hook(win->win_ptr, 17, 1l > 17, ft_exit, win);
	// mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	// mlx_expose_hook(win->win_ptr, deal_expose, win);
	// mlx_loop_hook(win->mlx_ptr, loop_hook, win);
	return (1);
}

int 	main(int ac, char **av)
{
	t_win	*win;

	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	ft_parse(win, av[1]);
	ft_init_start(win);
	ft_init_img(win);
	win->proj = 2;
	ft_init_pix_isometric_projection(win);
	// ft_init_pix_and_pos_orthographic_projection(win);
	ft_init_z_and_zok(win);
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_background, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 300, 150);
	ft_print_menu(win);
	mlx_hook(win->win_ptr, 2, 1L << 0, deal_key, win);
	mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	mlx_loop(win->mlx_ptr);
	free_struct(win);
	return (0);
}