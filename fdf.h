/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/01/31 20:52:47 by nvienot          ###   ########.fr       */
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

# define PI 3.14
# define THETA (10 * PI / 180)

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# define BLUE 255
# define GREEN 65280
# define RED 16711680


# define WIN_HOR_SIZE 1700
# define WIN_VER_SIZE 1100
# define IMG_HOR_SIZE 1100
# define IMG_VER_SIZE 800

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
	int				z;
	int				x_pix;
	int				y_pix;
	float			z_pix;
	int				xpix2;
	int				color;
	int				zok;
}					t_map;

typedef struct		s_win
{
	t_map			**s;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_fond;
	int				color;
	int				proj;
	int				x_max;
	int				y_max;
	int				pos_max;
	int				pix;
	int				hor;
	int				ver;
	int				top;
	int				rota;
	int				start;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_win;


void				ft_usage(void);
void				ft_exit_error(void);
int 				parse(t_win *win, char *av);
char				*get_map(char *av);
int					ft_create_isometric_projection_with_z(t_win *win);
int					ft_create_orthographic_projection_with_z(t_win *win);
int 				ft_draw_line(t_win *win, int x1, int x2, int y1, int y2);
int					ft_init_map(t_win *win);
int 				ft_init_z_and_zok(t_win *win);
int 				ft_init_xypix(t_win *win);
int 				ft_init_pix_and_pos_orthographic_projection(t_win *win);
int 				ft_init_pos_isometric_projection(t_win *win);
int 				ft_init_pix_isometric_projection(t_win *win);
int					print_menu(t_win *win);
void				mlx_put_pixel_to_image(t_win *win, int x, int y);
int					deal_key(int keycode, t_win *win);
int					ft_move_pos(t_win *win);
int					ft_rotate(t_win *win);
int					ft_increase_pix(t_win *win, int pix);
int					ft_get_color(t_win *win);
void				free_struct(t_win *win);
int					ft_create_isometric_projection_with_z(t_win *win);
int					ft_create_orthographic_projection_with_z(t_win *win);
int					ft_init_map(t_win *win);
int					ft_draw(t_win *win);


#endif
