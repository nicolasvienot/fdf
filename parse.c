/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:57:44 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/19 11:57:47 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_error()
{
	ft_putendl("error");
	return (0);
}

static int	count_number(char *map)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (map[i])
	{
		if (ft_isdigit(map[i]))
			count++;
		while (ft_isdigit(map[i]) && map[i])
			i++;
		while (!ft_isdigit(map[i]) && map[i])
			i++;
	}
	return (count);
}

static int	map_to_tab_int(t_map *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	s->y_max = 0;
	while (s->map[s->y_max])
		s->y_max++;
	s->x_max = count_number(s->map[0]);
	if (!(s->tab = (int**)malloc(sizeof(int*) * s->y_max)))
			return (0);
	while (s->map[i] && !(j = 0))
	{
		if (!(s->tab[i] = (int*)malloc(sizeof(int*) * s->x_max)))
			return (0);
		k = 0;
		while (s->map[i][j])
		{
			s->tab[i][k++] = ft_atoi(&s->map[i][j]);
			while (((s->map[i][j] >= '0' && s->map[i][j] <= '9') || s->map[i][j] == '-') && s->map[i][j])
				j++;
			while (s->map[i][j] == ' ' && s->map[i][j])
				j++;
		}
		i++;
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

static int	check_error_map(char *line, int len)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '-' && line[i] != '\n' && line[i] != ' ' && (line[i] <= '0' && line[i] >= '9'))
			return (0);
		i++;
	}
	return (1);
}

static char	*get_map(char *av)
{
	char	*str;
	char	*line;
	int		len;
	int		fd;

	line = NULL;
	str = NULL;
	if ((fd = open(&av[0], O_RDONLY)) < 0)
			return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		if (str == NULL)
			len = ft_strlen(line);
		if (!check_error_map(line, len))
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

int		main(int ac, char **av)
{
	t_map	*s;
	char	*str;
	int 	i;

	i = 0;
	if (ac != 2)
		return (print_error());
	if ((str = get_map(av[1])) == 0)
		return (print_error());
	if (!(s = (t_map*)malloc(sizeof(t_map))))
		return (print_error());
	s->map = ft_strsplit(str, '\n');
	free(str);
	if (!map_to_tab_int(s))
		return (0);
	while (s->map[i])
		free(s->map[i++])
	free(map);
}