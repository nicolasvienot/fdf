/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:57:44 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/18 14:33:57 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_struct(t_win **win, int k, int y, int i)
{
	if (!((*win)->s[i] = (t_map*)malloc(sizeof(t_map))))
		return (0);
	(*win)->s[i]->x = k;
	(*win)->s[i]->y = y;
	(*win)->s[i]->color = 0;
	return (0);
}

static int	map_to_struct(char **map, t_win **win, int i, int y)
{
	int	x;
	int k;

	while (map[y] && !(x = 0))
	{
		k = 0;
		while (map[y][x])
		{
			init_struct(win, k, y, i);
			(*win)->s[i]->z = ft_atoi(&map[y][x]);
			while (map[y][x] == ' ' && map[y][x])
				x++;
			while (map[y][x] != ' ' && map[y][x])
			{
				if (map[y][x] == ',')
					(*win)->s[i]->color = ft_atoi_base(&map[y][x + 3], 16);
				x++;
			}
			i++;
			if (k++ && map[y][x + 1] == '\0')
				break ;
		}
		y++;
	}
	return (1);
}

int			ft_parse(t_win **win, char *av)
{
	char	**map;
	char	*str;
	int		i;

	i = 0;
	(*win)->y_max = 0;
	if ((str = get_map(&av[0], win)) == NULL)
		ft_free_n_exit(win, -2);
	if (!(map = ft_strsplit(str, '\n')))
		ft_free_n_exit(win, -42);
	free(str);
	if (!((*win)->s = (t_map**)malloc(sizeof(t_map*) * ((*win)->pos_max + 1))))
		ft_free_n_exit_map(map, win, -42);
	if (!map_to_struct(map, win, 0, 0))
		ft_free_n_exit_map(map, win, -2);
	while (map[i])
		free(map[i++]);
	free(map);
	return (1);
}
