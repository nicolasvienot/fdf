/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:57:44 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/21 16:00:01 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			print_error()
{
	ft_putendl("error");
	return (0);
}

void		ft_exiterror(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void		ft_usage(void)
{
	ft_putstr("usage: ./fillit file\n");
	exit(EXIT_FAILURE);
}

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

int	map_to_struct(char **map, t_map **s)
{
	int	x;
	int	y;
	int i;
	int k;

	k = 0;
	i = 0;
	y = 0;
	while (map[y] && !(x = 0))
	{
		while (map[y][x])
		{
			if (!(s[i] = (t_map*)malloc(sizeof(t_map*))))
				return (0);
			s[i]->x = k;
			s[i]->y = y;
			s[i]->z = ft_atoi(&map[y][x]);
			s[i]->color = 0;
			while ((ft_isdigit(map[y][x]) || map[y][x] == '-' )
				&& map[y][x])
				x++;
			if (map[y][x] == ',')
			{
				x += 3;
				s[i]->color = ft_atoi_base(&map[y][x], 16);
			}
			while (map[y][x] != ' ' && map[y][x])
				x++;
			while (map[y][x] == ' ' && map[y][x])
				x++;
			i++;
			k++;
		}
		k = 0;
		y++;
	}
	return (1);
}

static void	concat_str(char *line, char **str)
{
	char	*tmp;
	char	*n_str;
	size_t	l_len;
	size_t	s_len;

	s_len = 0;
	tmp = *str;
	if (*str != NULL)
		s_len = ft_strlen(*str);
	l_len = ft_strlen(line);
	if (!(n_str = ft_memalloc((s_len + l_len) + 2)))
		return ;
	if (*str == NULL)
		ft_strcpy(n_str, line);
	else
		ft_strcat((ft_strcpy(n_str, *str)), line);
	n_str[s_len + l_len] = '\n';
	n_str[s_len + l_len + 1] = '\0';
	*str = n_str;
	if (tmp != NULL)
		free(tmp);
	free(line);
}

static int	check_error_map(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ',' || line[i] == '-' || line[i] == '\n' || line[i] == ' '))
			if (!ft_ishexa(line[i]))
				return (0);
		i++;
	}
	ft_putendl("pas derror");
	return (1);
}

static char	*get_map(char *av)
{
	char	*str;
	char	*line;
	int		fd;

	line = NULL;
	str = NULL;
	if ((fd = open(&av[0], O_RDONLY)) < 0)
			return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_error_map(line))
		{
			if (str != NULL)
				free(str);
			free(line);
			return (NULL);
		}
		concat_str(line, &str);
	}
	free(line);
	close(fd);
	return (str);
}

t_map		**parse(t_win *win, char *av)
{
	t_map	**s;
	char 	**map;
	char	*str;
	int		i;

	win->x_max = 0;
	win->y_max = 0;
	i = 0;
	if ((str = get_map(&av[0])) == NULL)
	{
		ft_exiterror();
		return (0);
	}
	map = ft_strsplit(str, '\n');
	free(str);
	while (map[win->y_max])
		win->y_max++;
	win->x_max = count_number(map[0]);
	if (!(s = (t_map**)malloc(sizeof(t_map*) * (win->x_max * win->y_max))))
		return (0);
	if (!map_to_struct(map, s))
		return (0);
	while (map[i])
		free(map[i++]);
	free(map);
	// printf("Valeur de x %d \n",s[2]->x);
	// printf("Valeur de y %d \n",s[2]->y);
	// printf("Valeur de z %d \n",s[2]->z);
	// printf("Valeur de color %d \n",s[2]->color);
	return (s);
}