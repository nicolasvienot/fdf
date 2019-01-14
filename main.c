/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/14 19:53:51 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	int i = 60000;
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, z);
	return (i);
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int x = 0;
	int y = 0;
	int z = 6000;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Nico");
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, z);
			y++;
		}
		x++;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}