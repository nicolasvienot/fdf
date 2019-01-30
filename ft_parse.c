/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:57:44 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/25 19:34:06 by nvienot          ###   ########.fr       */
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

static int	init_struct(t_win *win, int k, int y, int i)
{
	if (!(win->s[i] = (t_map*)malloc(sizeof(t_map))))
		return (0);
	win->s[i]->x = k;
	win->s[i]->y = y;
	win->s[i]->color = 0;
	return (0);
}

static int	map_to_struct(char **map, t_win *win, int i, int y)
{
	int	x;
	int k;

	while (map[y] && !(x = 0))
	{
		k = 0;
		while (map[y][x])
		{
			init_struct(win, k, y, i);
			win->s[i]->z = ft_atoi(&map[y][x]);
			while (map[y][x] == ' ' && map[y][x])
				x++;
			while (map[y][x] != ' ' && map[y][x])
			{
				if (map[y][x] == ',')
					win->s[i]->color = ft_atoi_base(&map[y][x + 3], 16);
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

int			parse(t_win *win, char *av)
{
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
	if (!(win->s = (t_map**)malloc(sizeof(t_map*) * (win->pos_max + 1))))
		return (0);
	if (!map_to_struct(map, win, 0, 0))
		return (0);
	while (map[i])
		free(map[i++]);
	free(map);
	return (1);
}
