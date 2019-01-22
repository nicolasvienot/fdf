/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/22 11:12:56 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define BUFF_SIZE 9999
# define BUF_SIZE 1000

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# define BLUE 255
# define GREEN 65280
# define RED 16711680

// typedef struct		s_gnl
// {
// 	char			*tab;
// 	int				fd;
// 	struct s_gnl	*next;
// }					t_gnl;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				color;
	int				x_max;
	int				y_max;
	int				pos_max;
}					t_win;

typedef struct		s_map
{
	int				x;
	int				y;
	int				x_pix;
	int				y_pix;
	int				z;
	int				color;
}					t_map;

t_map				**parse(t_win *win, char *av);
void				ft_usage(void);
int 				ft_draw_line(t_win *win, int x1, int x2, int y1, int y2);
int					ft_create_2d(t_map **s, t_win *win);

#endif