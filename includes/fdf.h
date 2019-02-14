/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/14 00:12:17 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define BUFF_SIZE 9999
# define BUF_SIZE 1000

# define PI 3.14
# define THETA (10 * PI / 180)
# define COEF_ZOOM 1.2
# define COEF_ROTA 1
# define SIZE_MOV 10
# define COEF_ALT 1.2
# define COEF_Z 0.2
# define MIN_ZOOM 0.01
# define MAX_ALT 10
# define MIN_ALT -10

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define PURPLE RGB(255, 0, 255)


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
# define TOUCH_M 46
# define TOUCH_STAR 67
# define PAGE_DOWN 121
# define PAGE_UP 116

typedef struct		s_map
{
	float			x;
	float			y;
	float			z;
	float				x_pix;
	float			y_pix;
	float			z_pix;
	float			x_pix_temp;
	int			color;
}					t_map;

typedef struct		s_win
{
	t_map			**s;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_background;
	void			*img_background2;
	void			*img_background3;
	void			*img_background4;
	void			*img_background5;
	void			*img_background6;
	void			*img_background7;
	void			*img_background8;
	void			*img_background9;
	void			*img_background10;
	void			*img_background11;
	void			*img_background12;
	void			*img_background13;
	int				color;
	int				proj;
	int				x_max;
	int				y_max;
	float				z_max;
	float				z_min;
	int				pos_max;
	float			pix;
	float			zix;
	int				hor;
	int				ver;
	int				rota;
	int				start;
	int				sizeline;
	int				x1;
	int				x2;
	int				y1;
	int			y2;
	float			z1;
	float			z2;
	int				aff_x;
	int				aff_y;
	int				menu;
	char			*filename;
	char			*data;
	int				bpp;
	int				endian;
	int 			img;
	float 			z;
}					t_win;

void				ft_usage(void);
int 				ft_parse(t_win **win, char *av);
char				*get_map(char *av);
int					ft_create_isometric_projection_with_z(t_win **win);
int					ft_create_orthographic_projection_with_z(t_win **win);
int					ft_init_map(t_win **win);
int 				ft_init_xypix(t_win **win);
int 				ft_init_pix_and_pos_orthographic_projection(t_win **win);
int 				ft_init_pos_isometric_projection(t_win **win);
int 				ft_init_pix_isometric_projection(t_win **win);
int					ft_print_menu(t_win **win);
void				mlx_put_pixel_to_image(t_win **win, int x, int y, int i);
int					deal_key(int keycode, t_win **win);
int					ft_move_pos(t_win **win);
int					ft_rotate(t_win **win, int i, float a, float b);
int					ft_increase_pix(t_win **win, int pix);
int					ft_get_color(t_win **win);
void				free_struct(t_win **win);
int					ft_create_isometric_projection_with_z(t_win **win);
int					ft_create_orthographic_projection_with_z(t_win **win);
int					ft_init_map(t_win **win);
int					ft_draw(t_win **win);
void				ft_refresh_img(t_win **win);
void				ft_init_img(t_win **win);
void				ft_init_start(t_win **win, char *av1);
void				ft_init_refresh(t_win **win);
int					ft_print_menu_2(t_win **win);
void				ft_refresh_background(t_win **win);
int					altitude_color(t_win **win);
int					ft_altitude(t_win **win, int a);
void				ft_display_menu(t_win **win);
char				*ft_get_file_name(char *av1);
void				ft_anim_background(t_win **win);
void                ft_exit_error(int error);
void                ft_free_n_exit_str(t_win **win, int error);
void                ft_free_n_exit_map(char **map, t_win **win, int error);

#endif
