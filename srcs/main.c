/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/18 14:27:43 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_mouse(int button, int a, int b, t_win **win)
{
	(*win)->aff_x = a;
	(*win)->aff_y = b;
	ft_refresh_img(win);
	ft_anim_background(win);
	ft_print_menu(win);
	if (button == 5 && (*win)->pix < MAX_ZOOM)
		(*win)->pix = (*win)->pix * COEF_ZOOM;
	if (button == 4 && (*win)->pix > MIN_ZOOM)
		(*win)->pix = (*win)->pix / COEF_ZOOM;
	ft_create_proj(win);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
		(*win)->img_ptr, 300, 150);
	return (1);
}

int		deal_expose(t_win **win)
{
	ft_anim_background(win);
	ft_print_menu(win);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr, \
	(*win)->img_ptr, 300, 150);
	return (1);
}

void	ft_hook(t_win **win)
{
	mlx_hook((*win)->win_ptr, 2, 1L << 0, deal_key, win);
	mlx_mouse_hook((*win)->win_ptr, deal_mouse, win);
	mlx_expose_hook((*win)->win_ptr, deal_expose, win);
	mlx_hook((*win)->win_ptr, 17, 1l > 17, ft_free_n_exit_win, win);
	mlx_loop((*win)->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_win	*win;

	if (ac != 2)
		ft_usage();
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	ft_parse(&win, av[1]);
	ft_init_start(&win, av[1]);
	ft_new_imgs(&win);
	ft_create_proj(&win);
	ft_hook(&win);
	return (0);
}
