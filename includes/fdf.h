/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:41:57 by nvienot           #+#    #+#             */
/*   Updated: 2019/02/18 14:47:10 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define BUFF_SIZE 9999
# define BUF_SIZE 1000

# define PI 3.14
# define COEF_ZOOM 1.2
# define COEF_ROTA 1
# define SIZE_MOV 15
# define COEF_ALT 1.2
# define COEF_Z 0.2
# define MIN_ZOOM 0.01
# define MAX_ZOOM 150
# define MAX_ALT 15
# define MIN_ALT -15

# define BLACK 0
# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define PURPLE 16711935
# define WHITE 16777215
# define GREY 6908265

# define WIN_HOR_SIZE 1700
# define WIN_VER_SIZE 1100
# define IMG_HOR_SIZE 1100
# define IMG_VER_SIZE 800

# define TOUCH_ESC 53
# define ARROW_LEFT 123
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define TOUCH_PLUS 69
# define TOUCH_LESS 78
# define TOUCH_O 31
# define TOUCH_P 35
# define TOUCH_I 34
# define TOUCH_R 15
# define TOUCH_T 17
# define TOUCH_M 46
# define TOUCH_C 8
# define TOUCH_STAR 67
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
	int				x_pix_temp;
	int				color;
}					t_map;

typedef struct		s_win
{
	t_map			**s;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_back1;
	void			*img_back2;
	void			*img_back3;
	void			*img_back4;
	void			*img_back5;
	void			*img_back6;
	void			*img_back7;
	void			*img_back8;
	void			*img_back9;
	char			*filename;
	char			*data;
	int				choosecolor;
	int				rota;
	int				start;
	int				proj;
	int				menu;
	int				img;
	int				x_max;
	int				y_max;
	float			z_min;
	float			z_max;
	int				pos_max;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	float			z;
	float			z1;
	float			z2;
	int				aff_x;
	int				aff_y;
	float			pix;
	float			zix;
	int				hor;
	int				ver;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_win;

void				ft_usage(void);
int					ft_parse(t_win **win, char *av);
char				*get_map(char *av, t_win **win);
void				ft_create_proj(t_win **win);
void				ft_init_xypix(t_win **win);
void				ft_init_pix_and_pos_orthographic_projection(t_win **win);
void				ft_init_pos_isometric_projection(t_win **win);
void				ft_init_pix_isometric_projection(t_win **win);
int					ft_print_menu(t_win **win);
void				mlx_put_pixel_to_image(t_win **win, int x, int y, int i);
int					deal_key(int keycode, t_win **win);
void				ft_move_pos(t_win **win);
void				ft_rotate(t_win **win, int i, float a, float b);
void				ft_rotate_2(t_win **win, int i, float a, float b);
void				ft_get_color(t_win **win);
void				ft_free_struct(t_win **win);
int					ft_draw_para(t_win **win);
int					ft_draw_iso(t_win **win);
void				ft_refresh_img(t_win **win);
void				ft_new_imgs(t_win **win);
void				ft_init_start(t_win **win, char *av1);
void				ft_init_refresh(t_win **win);
int					ft_altitude_color(t_win **win, int i);
void				ft_altitude(t_win **win, int a);
void				ft_display_menu(t_win **win);
char				*ft_get_file_name(char *av1);
void				ft_anim_background(t_win **win);
void				ft_free_n_exit(t_win **win, int error);
void				ft_free_n_exit_map(char **map, t_win **win, int error);
void				ft_exit(int code);
void				ft_get_z(t_win **win);
void				ft_draw_line(t_win **win, int i);
int					ft_free_n_exit_win(t_win **win);

#endif
