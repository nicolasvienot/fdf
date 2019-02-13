/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:30:02 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/14 00:20:41 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(t_win **win)
{
	int i;

	i = 0;
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_ptr);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_background2);
	mlx_destroy_window((*win)->mlx_ptr, (*win)->win_ptr);
	while (i <= ((*win)->pos_max))
		free((*win)->s[i++]);
	free((*win)->s);
	free((*win)->filename);
	free(*win);
}

void	get_z(t_win **win)
{
	int i;

	i = 0;
	(*win)->z_min = 0;
	(*win)->z_max = 0;
	while (i < (*win)->pos_max)
	{
		if ((*win)->z_min > (*win)->s[i]->z)
			(*win)->z_min = (*win)->s[i]->z;
		if ((*win)->z_max < (*win)->s[i]->z)
			(*win)->z_max = (*win)->s[i]->z;
		i++;
	}
}

int		altitude_color(t_win **win)
{
	float		delta;
	float		deltab;
	int			g;
	int			color;
	uintmax_t	ret;

	get_z(win);
	delta = (float)(*win)->z - (float)(*win)->z_min;
	deltab = (float)(*win)->z_max - (float)(*win)->z_min;
	if (deltab <= 0.0)
		return (RGB(255, 255, 255));
	delta = (float)delta / deltab;
	g = 255;
	g = (255 + delta * g);
	color = 0xFF;
	ret = RGB(255, g, (int)(color + delta * (255)));
	return (ret);
}

char	*ft_get_file_name(char *av1)
{
	char	*str;

	str = NULL;
	if (ft_is_present(av1, '/') == 1)
	{
		str = ft_strrchr(av1, '/');
		str++;
	}
	else
		str = av1;
	return (ft_strsub(str, 0, ft_strlen(str) - 4));
}

void	ft_display_menu(t_win **win)
{
	if ((*win)->menu == 0)
		(*win)->menu = 1;
	else
		(*win)->menu = 0;
	ft_anim_background(win);
	ft_print_menu(win);
}
