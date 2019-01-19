/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <auguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:11:08 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/17 11:52:47 by auguyon          ###   ########.fr       */
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

typedef struct		s_gnl
{
	char			*tab;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		z;
	struct s_win	*next;
}					t_win;

typedef struct		s_map
{
	char	**map;
	int		**tab;
	int		x_max;
	int		y_max;
}					t_map;

int		get_next_line(const int fd, char **line);

#endif
