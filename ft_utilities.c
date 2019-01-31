/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:30:02 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/31 17:09:37 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(t_win *win)
{
	int i;

	i = 0;
	while (i <= (win->pos_max + 1))
		free(win->s[i++]);
	free(win->s);
	// free(win->data);
	free(win);
}