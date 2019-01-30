/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/30 16:25:35 by nvienot          ###   ########.fr       */
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

void	free_struct(t_win *win)
{
	int i;

	i = 0;
	while (i <= (win->pos_max + 1))
		free(win->s[i++]);
	free(win->s);
	// free(win->data);
	free(win);
}

int		loop_hook(t_win *win)
{
	mlx_key_hook(win->win_ptr, deal_key, win);
	return (1);
}

int		ft_exit(t_win *win)
{
	win->color=2;
	exit(0);
}

int 	main(int ac, char **av)
{
	t_win	*win;
	
	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	parse(win, av[1]);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE, "FDF");
	win->start = 0;
	win->proj = 1;
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE);
	win->data = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->sizeline, &win->endian);
	ft_init_pix_and_pos_orthographic_projection(win);
	ft_init_top(win);
	ft_init_z_and_zok(win);
	ft_init_map(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
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