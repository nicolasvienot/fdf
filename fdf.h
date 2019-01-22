/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/22 20:31:00 by nvienot          ###   ########.fr       */
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

# define TOUCH_ESC 53
# define ARROW_LEFT 123
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define TOUCH_O 31
# define TOUCH_PLUS 69
# define TOUCH_LESS 78
# define TOUCH_P 35
# define TOUCH_I 34
# define TOUCH_R 15
# define TOUCH_T 17
# define PAGE_DOWN 121
# define PAGE_UP 116

typedef struct		s_map
{
	int				x;
	int				y;
	int				x_pix;
	int				y_pix;
	int				z;
	int				color;
}					t_map;

typedef struct		s_win
{
	t_map			**s;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				color;
	int				proj;
	int				x_max;
	int				y_max;
	int				pos_max;
	int				pix;
	int				hor;
	int				ver;
}					t_win;


void				ft_usage(void);
void				ft_exit_error(void);
int 				parse(t_win *win, char *av);
char				*get_map(char *av);
int 				ft_draw_line(t_win *win, int x1, int x2, int y1, int y2);
int					ft_init_map(t_win *win);
int 				ft_init_pix(t_win *win);
int 				ft_init_pos(t_win *win);

#endif
