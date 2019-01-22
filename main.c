/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/22 18:52:12 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int keycode, t_win *win)
{
	// int x;
	// int y;

	// x = 0;
	if (keycode == ARROW_UP)
	{
	// 	if (win->proj == 1)
			win->x_max = 2;
	// 	else
	// 		win->proj = 1;
	// 	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	// 	while (x < 1000)
	// 	{
	// 		y = 0;
	// 		while (y < 1000)
	// 		{
	// 			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, RGB(255, 0, 0));
	// 			y++;
	// 		}
	// 		x++;
	// 	}
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
	int x = 0;
	int y = 0;
	
	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	parse(win, av[1]);
	win->color = RGB(255, 255, 0);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 1000, "FDP");
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->color);
			y++;
		}
		x++;
	}
	ft_init_map(win);
	// // mlx_key_hook(win->win_ptr, deal_key, win);
	// // mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	// // mlx_expose_hook(win->win_ptr, deal_expose, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}