/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:29:59 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/18 17:31:50 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_pos(t_win **win)
{
	int		i;

	i = 0;
	while (i <= (*win)->pos_max)
	{
		(*win)->s[i]->x_pix = ((*win)->s[i]->x_pix + (*win)->hor);
		(*win)->s[i]->y_pix = ((*win)->s[i]->y_pix + (*win)->ver);
		i++;
	}
}

void	ft_rotate_2(t_win **win, int i, float a, float b)
{
	float	theta;

	theta = 10 * PI / 180;
	while (i <= (*win)->pos_max)
	{
		(*win)->s[i]->x_pix_temp = (*win)->s[i]->x_pix;
		(*win)->s[i]->x_pix = a + ((*win)->s[i]->x_pix - a) \
			* cos(theta * (*win)->rota) - ((*win)->s[i]->y_pix - b) \
				* sin(theta * (*win)->rota);
		(*win)->s[i]->y_pix = b + ((*win)->s[i]->x_pix_temp - a) \
			* sin(theta * (*win)->rota) + ((*win)->s[i]->y_pix - b) \
				* cos(theta * (*win)->rota);
		i++;
	}
}

void	ft_rotate(t_win **win, int i, float a, float b)
{
	if ((*win)->rota >= 36 || (*win)->rota <= -36)
		(*win)->rota = 0;
	if ((*win)->proj == 1 && (*win)->pos_max > 0)
	{
		if ((*win)->x_max > 1 && (*win)->y_max > 1)
		{
			a = ((*win)->s[(*win)->x_max - 1]->x_pix - (*win)->s[0]->x_pix) / 2;
			b = ((*win)->s[(*win)->pos_max - (*win)->x_max - 1]->y_pix \
				- (*win)->s[0]->y_pix) / 2;
		}
	}
	else if ((*win)->proj == 2 && (*win)->pos_max > 0)
	{
		if ((*win)->x_max > 1 && (*win)->y_max > 1)
		{
			a = (((*win)->s[(*win)->pos_max]->x_pix - (*win)->s[0]->x_pix) / 2);
			b = (*win)->s[0]->y;
		}
	}
	ft_rotate_2(win, i, a, b);
}

void	ft_get_color(t_win **win)
{
	int i;

	i = 0;
	while (i <= (*win)->pos_max)
	{
		if ((*win)->s[i]->color == 0)
			(*win)->s[i]->color = WHITE;
		i++;
	}
}

void	ft_altitude(t_win **win, int a)
{
	if (a == 1)
	{
		if ((*win)->zix <= -0.05)
			(*win)->zix = (*win)->zix / COEF_ALT;
		else if ((*win)->zix > -0.05 && (*win)->zix < 0)
			(*win)->zix = 0.01;
		else if ((*win)->zix > 0 && (*win)->zix < 0.05)
			(*win)->zix = 0.05;
		else if ((*win)->zix >= 0.05 && (*win)->zix < MAX_ALT)
			(*win)->zix = (*win)->zix * COEF_ALT;
	}
	if (a == 2)
	{
		if ((*win)->zix >= 0.05)
			(*win)->zix = (*win)->zix / COEF_ALT;
		else if ((*win)->zix < 0.05 && (*win)->zix > 0.01)
			(*win)->zix = 0.01;
		else if ((*win)->zix <= 0.01 && (*win)->zix > -0.05)
			(*win)->zix = -0.05;
		else if ((*win)->zix <= -0.05 && (*win)->zix > MIN_ALT)
			(*win)->zix = (*win)->zix * COEF_ALT;
	}
}
