/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/16 17:41:05 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		z;
	struct s_win	*next;
}					t_win;

# define BUF_SIZE 1000
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

#endif
