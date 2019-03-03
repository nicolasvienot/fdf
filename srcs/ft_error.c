/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/18 15:00:27 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_exit(int code)
{
	if (code == -1)
		write(1, "wrong map\n", 10);
	else if (code == -2)
		write(1, "error\n", 6);
	else if (code == -42)
		write(1, "malloc error\n", 13);
	exit(EXIT_FAILURE);
}

void		ft_usage(void)
{
	write(1, "usage: ./fdf file\n", 18);
	exit(EXIT_FAILURE);
}

void		ft_free_n_exit(t_win **win, int code)
{
	free(*win);
	ft_exit(code);
}

void		ft_free_n_exit_map(char **map, t_win **win, int code)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	free(*win);
	ft_exit(code);
}

int			ft_free_n_exit_win(t_win **win)
{
	ft_free_struct(win);
	exit(EXIT_SUCCESS);
	return (1);
}
