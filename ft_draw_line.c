/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nico <Nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:11:27 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/27 00:59:44 by Nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_draw_line(t_win *win, int x1, int x2, int y1, int y2)
{
	int x = 0;
	int y = 0;

	if (x1 <= x2 && (x2 - x1) >= abs(y2 - y1))
	{
		x = x1;
		while (x <= x2)
		{
			mlx_put_pixel_to_image(win, x, y1+((y2-y1)*(x-x1))/(x2-x1));
			x++;
		}
	}
	if (x2 <= x1 && (x1 - x2) >= abs(y1 - y2))
	{
		x = x2;
		while (x <= x1)
		{
			mlx_put_pixel_to_image(win, x, y2+((y1-y2)*(x-x2))/(x1-x2));
			x++;
		}
	}
	if (y2 <= y1 && (y1 - y2) >= abs(x1 - x2))
	{
		y = y2;
		while (y <= y1)
		{
			mlx_put_pixel_to_image(win, x2+((x1-x2)*(y-y2))/(y1-y2), y);
			y++;
		}
	}
	if (y1 <= y2 && (y2 - y1) >= abs(x2 - x1))
	{
		y = y1;
		while (y <= y2)
		{
			mlx_put_pixel_to_image(win, x1+((x2-x1)*(y-y1))/(y2-y1), y);
			y++;
		}
	}
	return (1);
}
