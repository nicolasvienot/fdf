/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/31 20:01:15 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int deal_mouse(int button, int a, int b, t_win *win)
// {
// 	return (1);
// }

// int	deal_expose(t_win *win)
// {
// 	return (1);
// }

int		loop_hook(t_win *win)
{
	mlx_key_hook(win->win_ptr, deal_key, win);
	return (1);
}

int 	main(int ac, char **av)
{
	t_win	*win;
	int	a = 1700;
	int b = 1100;
	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	parse(win, av[1]);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE, "FDF");
	win->start = 0;
	win->proj = 1;
	win->rota = 0;
	win->img_fond = mlx_new_image(win->mlx_ptr, 1700, 1100);
	win->img_fond = mlx_xpm_file_to_image(win->mlx_ptr, "./fdf.xpm", &a, &b);
	win->img_ptr = mlx_new_image(win->mlx_ptr, IMG_HOR_SIZE, IMG_VER_SIZE);
	win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline, &win->endian);
	ft_init_pix_and_pos_orthographic_projection(win);
	win->top = 1;
	ft_init_z_and_zok(win);
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_fond, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 300, 150);
	print_menu(win);
	// mlx_key_hook(win->win_ptr, deal_key, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, deal_key, win);
	// mlx_hook(win->win_ptr, 17, 1l > 17, ft_exit, win);
	// mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	// mlx_expose_hook(win->win_ptr, deal_expose, win);
	// mlx_loop_hook(win->mlx_ptr, loop_hook, win);
	mlx_loop(win->mlx_ptr);
	free_struct(win);
	return (0);
}