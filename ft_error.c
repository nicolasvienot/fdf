/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:48:56 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/08 15:18:12 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_usage(void)
{
	write(1, "usage: ./fillit file\n", 21);
	exit(EXIT_FAILURE);
}
