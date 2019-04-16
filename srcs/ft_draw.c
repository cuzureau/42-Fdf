/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:25:05 by cuzureau          #+#    #+#             */
/*   Updated: 2017/04/25 20:33:18 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void				put_pxl_to_image(t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x < 0 || y < 0 || x >= e->x_img || y >= e->y_img)
		return ;
	r = ((e->color & 0xFF0000) >> 16);
	g = ((e->color & 0xFF00) >> 8);
	b = (e->color & 0xFF);
	e->data[(x * 4) + (y * e->size_l)] = b;
	e->data[(x * 4) + (y * e->size_l) + 1] = g;
	e->data[(x * 4) + (y * e->size_l) + 2] = r;
}

static void				ft_draw_first(t_env *e)
{
	int					i;

	i = 1;
	e->cumul = e->dx / 2.0;
	while (i <= e->dx + 1)
	{
		put_pxl_to_image(e, e->x_p, e->y_p);
		e->x_p += e->xinc;
		e->cumul += e->dy;
		if (e->cumul >= e->dx + 1)
		{
			e->cumul -= e->dx;
			e->y_p += e->yinc;
		}
		i++;
	}
}

static void				ft_draw_second(t_env *e)
{
	int					i;

	i = 1;
	e->cumul = e->dy / 2.0;
	while (i <= e->dy + 1)
	{
		put_pxl_to_image(e, e->x_p, e->y_p);
		e->y_p += e->yinc;
		e->cumul += e->dx;
		if (e->cumul >= e->dy + 1)
		{
			e->cumul -= e->dy;
			e->x_p += e->xinc;
		}
		i++;
	}
}

static void				ft_draw_line(t_env *e)
{
	e->x_p = e->x0;
	e->y_p = e->y0;
	e->dx = e->x1 - e->x0;
	e->dy = e->y1 - e->y0;
	e->xinc = (e->dx > 0 ? 1 : -1);
	e->yinc = (e->dy > 0 ? 1 : -1);
	e->dx = fabs(e->dx);
	e->dy = fabs(e->dy);
	if (e->dx > e->dy)
		ft_draw_first(e);
	else
		ft_draw_second(e);
}

void					ft_draw(t_env *e)
{
	ft_bzero(e->data, e->size_l * e->y_img);
	e->y = 0;
	while (e->y < e->y_max)
	{
		e->x = 0;
		while (e->x < e->x_max)
		{
			e->x0 = e->tab[e->y][e->x].x;
			e->y0 = e->tab[e->y][e->x].y;
			if (e->x < e->x_max - 1)
			{
				e->x1 = e->tab[e->y][e->x + 1].x;
				e->y1 = e->tab[e->y][e->x + 1].y;
				ft_draw_line(e);
			}
			if (e->y < e->y_max - 1)
			{
				e->x1 = e->tab[e->y + 1][e->x].x;
				e->y1 = e->tab[e->y + 1][e->x].y;
				ft_draw_line(e);
			}
			e->x++;
		}
		e->y++;
	}
}
