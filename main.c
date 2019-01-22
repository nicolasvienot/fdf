/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/22 12:31:03 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	deal_key(int keycode, t_win *win)
// {
// 	return (1);
// }

// int deal_mouse(int button, int a, int b, t_win *win)
// {
// 	return (1);
// }

// int	deal_expose(t_win *win)
// {
// 	return (1);
// }

int ft_draw(t_win *win)
{
	int i = 0;
	int j = 0;
	int k = 1;
	// int x1;
	// int y1;
	// int x2;
	// int y2;
	int *tab[10];

	while(i <= 9)
	{
		tab[i] = (int*)malloc(sizeof(int) * 3);
		i++;
	}
	i = 0;
	j = 0;
	while (i <= 9)
	{
		tab[i][j] = k;
		i++;
		k++;
	}
	j++;
	i = 0;
	k = 100;
	while (i <= 9)
	{
		if (k == 550)
			k = 100;
		tab[i][j] = k;
		k = k + 150;
		i++;
	}
	j++;
	i = 0;
	k = 100;
	while (i <= 9)
	{
		if (i == 3)
			k = 250;
		if (i == 6)
			k = 400;
		tab[i][j] = k;
		i++;
	}
	i = 0;
	j = 0;
	while (i <= 9)
	{
		j = 0;
		while (j <= 2)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	i = 0;
	while (i <= 8)
	{
		if (i == 2 || i == 5)
			i++;
		ft_draw_line(win, tab[i][1], tab[i+1][1], tab[i][2], tab[i+1][2]);
		i++;
	}
	i = 0;
		while (i <= 5)
	{
		ft_draw_line(win, tab[i][1], tab[i+3][1], tab[i][2], tab[i+3][2]);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_map	**s;
	t_win	*win;
	int x = 0;
	int y = 0;
	
	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	s = parse(win, av[1]);
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
	ft_init_map(s, win);
	// mlx_key_hook(win->win_ptr, deal_key, win);
	// mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	// mlx_expose_hook(win->win_ptr, deal_expose, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}