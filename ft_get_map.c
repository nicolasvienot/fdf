/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:55:30 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/22 11:55:34 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		if (!(line[i] == ',' || line[i] == '-' || line[i] == '\n'
				|| line[i] == ' ' || line[i] == 'x'))
			if (!ft_ishexa(line[i]))
				return (0);
		i++;
	}
	return (1);
}

char		*get_map(char *av)
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
