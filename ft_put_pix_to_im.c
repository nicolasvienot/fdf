/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pix_to_im.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nico <Nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:02:49 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/27 01:05:05 by Nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx_put_pixel_to_image(t_win *win, int x, int y)
{
	int		octet;
	int		a;

	octet = win->bpp / 8;
	a = RGB(255, 0, 0);

	if (x >= 0 && y >= 0 && x < WIN_HOR_SIZE && y < WIN_VER_SIZE)
	{
		ft_memcpy(&win->data[octet * x + win->sizeline * y], &a, octet);
	}
}