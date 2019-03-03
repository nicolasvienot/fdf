/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:30:02 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/18 17:18:46 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_struct(t_win **win)
{
	int i;

	i = 0;
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_ptr);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back1);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back2);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back3);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back4);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back5);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back6);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back7);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back8);
	mlx_destroy_image((*win)->mlx_ptr, (*win)->img_back9);
	mlx_destroy_window((*win)->mlx_ptr, (*win)->win_ptr);
	while (i <= ((*win)->pos_max))
		free((*win)->s[i++]);
	free((*win)->s);
	free((*win)->filename);
	free(*win);
}

void	ft_get_z(t_win **win)
{
	int i;

	i = 0;
	(*win)->z_min = 0;
	(*win)->z_max = 0;
	while (i < (*win)->pos_max)
	{
		if ((*win)->z_min > (*win)->s[i]->z_pix)
			(*win)->z_min = (*win)->s[i]->z_pix;
		if ((*win)->z_max < (*win)->s[i]->z_pix)
			(*win)->z_max = (*win)->s[i]->z_pix;
		i++;
	}
}

int		ft_altitude_color(t_win **win, int i)
{
	float		delta;
	float		deltab;
	float		r;
	float		b;
	int			ret;

	if ((*win)->choosecolor == 2)
		return ((*win)->s[i]->color);
	delta = (*win)->z - (*win)->z_min;
	deltab = (*win)->z_max - (*win)->z_min;
	if ((*win)->z == (float)(*win)->z_min && (*win)->choosecolor == 0)
		return (GREY);
	delta = delta / deltab;
	r = (delta * 255);
	b = r;
	ret = 256 * 256 * (int)r + 256 * 0 + (int)b;
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
