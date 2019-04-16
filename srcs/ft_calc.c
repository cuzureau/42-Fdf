/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 20:02:13 by cuzureau          #+#    #+#             */
/*   Updated: 2017/04/25 20:33:03 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_matrix		ft_fill_matx(t_env *e)
{
	t_matrix		dst;

	dst.a = 1;
	dst.b = 0;
	dst.c = 0;
	dst.d = 0;
	dst.e = cos(e->rotx);
	dst.f = sin(e->rotx);
	dst.g = 0;
	dst.h = -sin(e->rotx);
	dst.i = cos(e->rotx);
	return (dst);
}

static t_matrix		ft_fill_maty(t_env *e)
{
	t_matrix		dst;

	dst.a = cos(e->roty);
	dst.b = 0;
	dst.c = -sin(e->roty);
	dst.d = 0;
	dst.e = 1;
	dst.f = 0;
	dst.g = sin(e->roty);
	dst.h = 0;
	dst.i = cos(e->roty);
	return (dst);
}

static t_matrix		ft_fill_matz(t_env *e)
{
	t_matrix		dst;

	dst.a = cos(e->rotz);
	dst.b = sin(e->rotz);
	dst.c = 0;
	dst.d = -sin(e->rotz);
	dst.e = cos(e->rotz);
	dst.f = 0;
	dst.g = 0;
	dst.h = 0;
	dst.i = 1;
	return (dst);
}

static t_matrix		ft_calc_mat(t_matrix mat1, t_matrix mat2)
{
	t_matrix		dst;

	dst.a = (mat1.a * mat2.a) + (mat1.b * mat2.d) + (mat1.c * mat2.g);
	dst.b = (mat1.a * mat2.b) + (mat1.b * mat2.e) + (mat1.c * mat2.h);
	dst.c = (mat1.a * mat2.c) + (mat1.b * mat2.f) + (mat1.c * mat2.i);
	dst.d = (mat1.d * mat2.a) + (mat1.e * mat2.d) + (mat1.f * mat2.g);
	dst.e = (mat1.d * mat2.b) + (mat1.e * mat2.e) + (mat1.f * mat2.h);
	dst.f = (mat1.d * mat2.c) + (mat1.e * mat2.f) + (mat1.f * mat2.i);
	dst.g = (mat1.g * mat2.a) + (mat1.h * mat2.d) + (mat1.i * mat2.g);
	dst.h = (mat1.g * mat2.b) + (mat1.h * mat2.e) + (mat1.i * mat2.h);
	dst.i = (mat1.g * mat2.c) + (mat1.h * mat2.f) + (mat1.i * mat2.i);
	return (dst);
}

void				ft_calc(t_env *e)
{
	e->y = 0;
	e->matx = ft_fill_matx(e);
	e->maty = ft_fill_maty(e);
	e->matz = ft_fill_matz(e);
	e->mat = ft_calc_mat(e->matx, e->maty);
	e->mat = ft_calc_mat(e->mat, e->matz);
	while (e->y < e->y_max)
	{
		e->x = 0;
		while (e->x < e->x_max)
		{
			e->z = e->tab[e->y][e->x].z * e->moove_z * -1;
			e->tmpx = e->x * e->mat.a + e->y * e->mat.b + e->z * e->mat.c;
			e->tmpy = e->x * e->mat.d + e->y * e->mat.e + e->z * e->mat.f;
			e->tmpz = e->x * e->mat.g + e->y * e->mat.h + e->z * e->mat.i;
			e->tab[e->y][e->x].x = \
			((1.0 * e->tmpx) - (1.0 * e->tmpy)) * e->zoom;
			e->tab[e->y][e->x].y = \
			(e->tmpz + ((1.0 / 2) * e->tmpx) + ((1.0 / 2) * e->tmpy)) * e->zoom;
			e->tab[e->y][e->x].x += e->moove_x;
			e->tab[e->y][e->x].y += e->moove_y;
			e->x++;
		}
		e->y++;
	}
}
