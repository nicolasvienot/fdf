/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:44:12 by auguyon           #+#    #+#             */
/*   Updated: 2018/11/28 16:25:14 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fill_line(t_gnl *tmp, char **line)
{
	char *temp;
	char *i;

	if ((i = ft_strchr(tmp->tab, '\n')))
	{
		temp = tmp->tab;
		*line = ft_strsub(temp, 0, i - temp);
		tmp->tab = ft_strdup(i + 1);
		free(temp);
	}
	else
	{
		*line = ft_strdup(tmp->tab);
		ft_strclr(tmp->tab);
	}
}

int				read_fd(const int fd, t_gnl *tmp)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	ret = 1;
	if (tmp->tab == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp->tab = ft_strdup(buf);
	}
	while (!ft_strchr(tmp->tab, '\n') && ret >= 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		temp = tmp->tab;
		if (!(tmp->tab = ft_strjoin(tmp->tab, buf)))
			return (-1);
		free(temp);
		if (ret == 0)
			return (0);
	}
	return (1);
}

static t_gnl	*check_node(t_gnl **lst, int fd)
{
	t_gnl *new;
	t_gnl *node;

	node = *lst;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->tab = NULL;
	new->next = *lst;
	*lst = new;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst = NULL;
	t_gnl			*tmp;
	int				ret;

	if (fd < 0 || !line || read(fd, 0, 0))
		return (-1);
	if (!(tmp = check_node(&lst, fd)))
		return (-1);
	if ((ret = read_fd(fd, tmp)) < 0)
		return (-1);
	fill_line(tmp, line);
	if (ft_strlen(tmp->tab) == 0 && ret == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
