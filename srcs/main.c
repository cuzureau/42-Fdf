/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:47:21 by cuzureau          #+#    #+#             */
/*   Updated: 2017/04/26 11:48:40 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2 || !av[1] || av[1] == NULL)
		exit(-1);
	e.av1 = av[1];
	ft_parse(&e, av[1]);
	ft_init(&e);
	ft_calc(&e);
	ft_draw(&e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	ft_events(&e);
	mlx_loop(e.mlx);
	return (0);
}
