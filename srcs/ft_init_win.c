/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:46:19 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/18 14:33:57 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_start(t_win **win, char *av1)
{
	(*win)->mlx_ptr = mlx_init();
	(*win)->win_ptr = mlx_new_window((*win)->mlx_ptr, WIN_HOR_SIZE, \
		WIN_VER_SIZE, "FDF");
	if (!((*win)->filename = ft_get_file_name(av1)))
		ft_exit(-42);
	(*win)->start = 0;
	(*win)->proj = 1;
	(*win)->rota = 0;
	(*win)->aff_x = 0;
	(*win)->aff_y = 0;
	(*win)->zix = 1;
	(*win)->menu = 0;
	(*win)->img = 0;
	(*win)->choosecolor = 0;
	ft_init_pix_and_pos_orthographic_projection(win);
	ft_get_color(win);
}

void	ft_init_refresh(t_win **win)
{
	(*win)->start = 0;
	(*win)->rota = 0;
	(*win)->aff_x = 0;
	(*win)->aff_y = 0;
	(*win)->zix = 1;
}
