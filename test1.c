/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/17 12:27:36 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "fdf.h"
#include <time.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

// void	*mlx_new_image(void *mlx_ptr, int width, int height)
// {

// }

int	deal_key(int keycode, t_win *win)
{
	if (keycode == 12)
	{
		int x = 50;
		int y = 50;
		if (win->z == RGB(255, 0, 0))
			win->z = RGB(0, 255, 0);
		else if (win->z == RGB(0, 255, 0))
			win->z = RGB(0, 0, 255);
		else if (win->z == RGB(0, 0, 255))
			win->z = RGB(255, 0, 0);
		
		while (x < 950)
		{
			y = 50;
			while (y < 450)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->z);
				y++;
			}
			x++;
		}
		// mlx_string_put(win->mlx_ptr, win->win_ptr, 630, 440, 0xD3D3DA, "Tape Q pour changer de couleur");
		// mlx_string_put(win->mlx_ptr, win->win_ptr, 630, 460, 0xD3D3DA, "ou clique sur son petit museau :D");
		// mlx_string_put(win->mlx_ptr, win->win_ptr, 975, 475, 0xD3D3DA, "O");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 5, 0xD3D3DA, "X");
	}
	return (1);
}

int deal_mouse(int button, int a, int b, t_win *win)
{
	int x = 50;
	int y = 50;
	char *c;
	char *d;

	c = ft_itoa(a);
	d = ft_itoa(b);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 30, 0xD3D3DA, "X = ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 40, 30, 0xD3D3DA, c);
		mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 50, 0xD3D3DA, "Y = ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 40, 50, 0xD3D3DA, d);
	if (a > 340 && a < 360 && b > 340 && b < 360)
	{
		if (win->z == RGB(255, 0, 0))
			win->z = RGB(0, 255, 0);
		else if (win->z == RGB(0, 255, 0))
			win->z = RGB(0, 0, 255);
		else if (win->z == RGB(0, 0, 255))
			win->z = RGB(255, 0, 0);
		while (x < 950)
		{
			y = 50;
			while (y < 450)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->z);
				y++;
			}
			x++;
		}
	}
	if (a < 20 && b < 20)
	{
		win->win_ptr = mlx_new_window(win->mlx_ptr, 250, 50, "Nico");
		x = 0;
		while (x < 250)
		{
		y = 0;
		while (y < 50)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->z);
			y++;
		}
		x++;
		}
		mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 5, 0xD3D3DA, "SORRY BRO BYE BYE");
		exit (EXIT_FAILURE);
	}
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 630, 440, 0xD3D3DA, "Tape Q pour changer de couleur");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 630, 460, 0xD3D3DA, "ou clique sur son petit museau :D");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 975, 475, 0xD3D3DA, "O");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 5, 0xD3D3DA, "X");
	return (1);
}

int	deal_expose(t_win *win)
{
	ft_putstr("BITE");
	return (1);
}

int main()
{
	t_win	*win;
	int x = 0;
	int y = 0;
	
	win->z = RGB(255, 0, 0);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 500, "Nico");
	win->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, "chaton.xpm", &x, &y);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	while (x < 950)
	{
		y = 0;
		while (y < 450)
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->z);
			y++;
		}
		x++;
	}
	// win->z = RGB(255, 0, 0);
	// while (x < 1000)
	// {
	// 	y = 240;
	// 	while (y < 500)
	// 	{
	// 		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->z);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// win->img_ptr = mlx_new_image(win->mlx_ptr, 1000, 500);
	// win->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, "chaton.xpm", &x, &y);
	// mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 330, 460, 0xD3D3DA, "Tape Q pour changer de couleur ou clique sur son petit museau :D");
	mlx_key_hook(win->win_ptr, deal_key, win);
	mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	mlx_expose_hook(win->win_ptr, deal_expose, win);
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 330, 460, 0xD3D3DA, "Tape Q pour changer de couleur ou clique sur son petit museau :D");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 630, 460, 0xD3D3DA, "ou clique sur son petit museau :D");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 340, 340, 0xD3D3DA, "O");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 5, 5, 0xD3D3DA, "X");
	mlx_loop(win->mlx_ptr);
	return (0);
}

// unsigned int	mlx_get_color_value(void *mlx_ptls
