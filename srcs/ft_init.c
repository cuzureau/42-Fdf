/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:09:43 by cuzureau          #+#    #+#             */
/*   Updated: 2017/04/26 11:56:53 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_init(t_env *e)
{
	e->zoom = 10;
	e->y_win = (e->y_max * e->zoom * 4);
	e->x_win = (e->x_max * e->zoom * 3);
	e->x_img = (e->x_max * e->zoom * 3);
	e->y_img = (e->y_max * e->zoom * 4);
	e->color = mlx_get_color_value(e->mlx, 0xFFFFFF);
	e->rotx = 0;
	e->roty = 0;
	e->rotz = 0;
	e->moove_z = 1.0;
	e->moove_x = 0;
	e->moove_y = 0;
	if (!(e->mlx = mlx_init()) || \
		!(e->win = mlx_new_window(e->mlx, e->x_win, e->y_win, "fdf")) || \
		!(e->img = mlx_new_image(e->mlx, e->x_img, e->y_img)) || \
		!(e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_l), \
				&(e->endian))))
		exit(-1);
	return (1);
}
