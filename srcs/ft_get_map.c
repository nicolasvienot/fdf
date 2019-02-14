/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:55:30 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/30 16:25:00 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_number(char *map)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (map && map[i] != '\n')
	{
		while (map && map[i] != '\n' && !ft_isdigit(map[i]))
			i++;
		if (ft_isdigit(map[i]))
			count++;
		while (map && map[i] != '\n' && map[i] != ' ')
			i++;
	}
	return (count);
}

static int	count_nl(char *map)
{
	int i;
	int nl;
	int len;

	i = 0;
	nl = 1;
	len = count_number(map);
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
			i++;
		i++;
		if (map[i] && map[i + 1])
		{
			if (len == count_number(map + i))
				nl++;
			else
				return (nl);
		}
	}
	return (nl);
}

static int	check_error(char *map, int i)
{
	int len;

	while (map[i])
	{
		if (!(map[i] == ',' || map[i] == '-' || map[i] == '\n' \
				|| map[i] == ' ' || map[i] == 'x'))
			if (!ft_ishexa(map[i]))
				return (0);
		i++;
	}
	i = 0;
	len = count_number(map);
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
			i++;
		i++;
		if (map[i] && map[i + 1])
		{
			if (len != count_number(map + i))
				return (0);
		}
	}
	return (1);
}

static char	*read_map(int fd, char *map)
{
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) > 0)
	{
		tmp = map;
		if (map == NULL)
			map = ft_strdup(line);
		else
			map = ft_strjoin(map, line);
		if (tmp)
			free(tmp);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(line);
		if (tmp)
			free(tmp);
	}
	close(fd);
	return (map);
}

char		*get_map(char *av, t_win **win)
{
	char	*map;
	int		fd;

	map = NULL;
	if ((fd = open(&av[0], O_RDONLY)) < 0)
		return (NULL);
	map = read_map(fd, map);
	if (!check_error(map, 0))
		return (NULL);
	(*win)->x_max = count_number(map);
	(*win)->y_max = count_nl(map);
	(*win)->pos_max = (((*win)->x_max * (*win)->y_max) - 1);
	return (map);
}
