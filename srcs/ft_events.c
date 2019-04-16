/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 09:11:03 by cuzureau          #+#    #+#             */
/*   Updated: 2017/04/26 11:59:19 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_moove(int keycode, t_env *e)
{
	if (keycode == 126)
		e->moove_y -= 20;
	if (keycode == 124)
		e->moove_x += 20;
	if (keycode == 123)
		e->moove_x -= 20;
	if (keycode == 125)
		e->moove_y += 20;
	if (keycode == 67)
		e->moove_z += 1;
	if (keycode == 75)
		e->moove_z -= 1;
}

static void		ft_rotate(int keycode, t_env *e)
{
	if (keycode == 91)
		e->rotx += 0.2;
	if (keycode == 84)
		e->rotx -= 0.2;
	if (keycode == 88)
		e->roty -= 0.2;
	if (keycode == 86)
		e->roty += 0.2;
	if (keycode == 92)
		e->rotz -= 0.2;
	if (keycode == 83)
		e->rotz += 0.2;
}

static void		ft_zoom(int keycode, t_env *e)
{
	if (keycode == 78 && e->zoom >= 2)
		e->zoom = e->zoom - 2;
	if (keycode == 69)
		e->zoom = e->zoom + 2;
}

static int		my_key_ft(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 53)
		exit(1);
	ft_zoom(keycode, e);
	ft_moove(keycode, e);
	ft_rotate(keycode, e);
	if (keycode == 15)
	{
		ft_parse(e, e->av1);
		ft_init(e);
		ft_calc(e);
		ft_draw(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		ft_events(e);
		mlx_loop(e->mlx);
	}
	ft_calc(e);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (1);
}

int				ft_events(t_env *e)
{
	mlx_key_hook(e->win, my_key_ft, e);
	return (1);
}
