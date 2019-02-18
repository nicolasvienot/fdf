/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/18 14:33:01 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_exit(int error)
{
	if (error == 0)
		exit(EXIT_SUCCESS);
	else if (error == -1)
		write(1, "wrong map\n", 10);
	else if (error == -2)
		write(1, "error\n", 6);
	else if (error == -42)
		write(1, "malloc error\n", 13);
	exit(EXIT_FAILURE);
}

void		ft_usage(void)
{
	write(1, "usage: ./fdf file\n", 18);
	exit(EXIT_FAILURE);
}

void		ft_free_n_exit(t_win **win, int error)
{
	free(*win);
	ft_exit(error);
}

void		ft_free_n_exit_map(char **map, t_win **win, int error)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	free(*win);
	ft_exit(error);
}

int		ft_free_n_exit_win(t_win **win)
{
	ft_free_struct(win);
	ft_exit(0);
	return (0);
}
