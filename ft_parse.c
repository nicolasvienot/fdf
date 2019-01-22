/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:57:44 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/22 11:18:05 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_number(char *map)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '-')
			i++;
		if (ft_isdigit(map[i]))
			count++;
		while ((ft_ishexa(map[i]) || map[i] == 'x' || map[i] == ',')
				&& map[i])
			i++;
		while (!ft_isdigit(map[i]) && map[i])
			i++;
	}
	return (count);
}

static int	check_error(t_win *win, char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (win->x_max != count_number(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	init_struct(t_map **s, int k, int y, int i)
{
	if (!(s[i] = (t_map*)malloc(sizeof(t_map))))
		return (0);
	s[i]->x = k;
	s[i]->y = y;
	s[i]->color = 0;
	return (0);
}

static int	map_to_struct(char **map, t_map **s, int i, int y)
{
	int	x;
	int k;

	while (map[y] && !(x = 0))
	{
		k = 0;
		while (map[y][x])
		{
			init_struct(s, k, y, i);
			s[i]->z = ft_atoi(&map[y][x]);
			while (map[y][x] == ' ' && map[y][x])
				x++;
			while ((ft_isdigit(map[y][x]) || map[y][x] == '-') && map[y][x])
				x++;
			if (k++ && map[y][x] == ',')
				x += 3;
			if (map[y][x - 3] == ',')
				s[i]->color = ft_atoi_base(&map[y][x], 16);
			while (map[y][x] != ' ' && map[y][x])
				x++;
			i++;
		}
		y++;
	}
	return (1);
}

t_map		**parse(t_win *win, char *av)
{
	t_map	**s;
	char	**map;
	char	*str;
	int		i;

	i = 0;
	win->y_max = 0;
	if ((str = get_map(&av[0])) == NULL)
		ft_exit_error();
	map = ft_strsplit(str, '\n');
	free(str);
	while (map[win->y_max])
		win->y_max++;
	win->x_max = count_number(map[0]);
	if (!check_error(win, map))
		ft_exit_error();
	win->pos_max = ((win->x_max * win->y_max) - 1);
	if (!(s = (t_map**)malloc(sizeof(t_map*) * (win->pos_max + 1))))
		return (0);
	if (!map_to_struct(map, s, 0, 0))
		return (0);
	while (map[i])
		free(map[i++]);
	free(map);
	return (s);
}
