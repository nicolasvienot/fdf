/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/23 18:17:27 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int keycode, t_win *win)
{
	if (keycode == ARROW_UP)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->ver += 10;
		ft_init_map(win);
		print_menu(win);
	}
	if (keycode == ARROW_DOWN)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->ver -= 10;
		ft_init_map(win);
		print_menu(win);
	}
	if (keycode == ARROW_RIGHT)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->hor -= 10;
		ft_init_map(win);
		print_menu(win);
	}
	if (keycode == ARROW_LEFT)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->hor += 10;
		ft_init_map(win);
		print_menu(win);
	}
	if (keycode == TOUCH_PLUS)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->pix += 3;
		ft_init_map(win);
		print_menu(win);
	}
	if (keycode == TOUCH_LESS)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		if (win->pix > 3)
			win->pix -= 3;
		ft_init_map(win);
		print_menu(win);
	}
	if (keycode == PAGE_UP)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->top = 2;
		ft_init_map(win);
		print_menu(win);
		ft_init_top(win);
	}
	if (keycode == PAGE_DOWN)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->top = -2;
		ft_init_map(win);
		print_menu(win);
		ft_init_top(win);
	}
	if (keycode == TOUCH_O)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		ft_init_pix(win);
		ft_init_pos(win);
		ft_init_top(win);
		ft_init_z_and_zok(win);
		ft_init_xypix(win);
		ft_init_map(win);
		print_menu(win);
	}
	if (keycode == TOUCH_ESC)
	{
		exit(EXIT_SUCCESS);
	}
	return (1);
}

// int deal_mouse(int button, int a, int b, t_win *win)
// {
// 	return (1);
// }

// int	deal_expose(t_win *win)
// {
// 	return (1);
// }

int main(int ac, char **av)
{
	t_win	*win;
	// int x = 0;
	// int y = 0;
	
	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	parse(win, av[1]);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_HOR_SIZE, WIN_VER_SIZE, "FDF");
	ft_init_pos(win);
	ft_init_pix(win);
	// ft_init_pix_orthographic_projection(win);
	ft_init_top(win);
	ft_init_z_and_zok(win);
	ft_init_map(win);
	print_menu(win);
	mlx_key_hook(win->win_ptr, deal_key, win);
	// // mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	// // mlx_expose_hook(win->win_ptr, deal_expose, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}