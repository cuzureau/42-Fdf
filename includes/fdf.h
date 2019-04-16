/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:24:45 by cuzureau          #+#    #+#             */
/*   Updated: 2017/04/26 11:06:34 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_pt
{
	float			y;
	float			x;
	float			z;
	int				color;
}					t_pt;

typedef struct		s_matrix
{
	float			a;
	float			b;
	float			c;
	float			d;
	float			e;
	float			f;
	float			g;
	float			h;
	float			i;
}					t_matrix;

typedef struct		s_env
{
	char			*av1;
	int				fd;
	int				x;
	int				y;

	float			z;
	t_matrix		matx;
	t_matrix		maty;
	t_matrix		matz;
	t_matrix		mat;
	float			tmpx;
	float			tmpy;
	float			tmpz;

	float			i;
	float			x0;
	float			y0;
	float			x1;
	float			y1;

	float			zoom;
	float			rotx;
	float			roty;
	float			rotz;
	float			moove_z;
	float			moove_x;
	float			moove_y;

	float			dx;
	float			dy;
	float			xinc;
	float			yinc;
	float			cumul;
	float			x_p;
	float			y_p;

	float			x_max;
	float			y_max;
	float			x_win;
	float			y_win;
	float			x_img;
	float			y_img;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	unsigned long	color;
	t_pt			**tab;
}					t_env;

int					main(int ac, char **av);
int					ft_parse(t_env *e, char *src);
int					ft_init(t_env *e);
void				ft_calc(t_env *e);
void				ft_draw(t_env *e);
int					ft_events(t_env *e);

#endif
