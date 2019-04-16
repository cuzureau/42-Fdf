/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:58:55 by cuzureau          #+#    #+#             */
/*   Updated: 2017/04/26 11:29:32 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_check(t_env *e, char *src)
{
	int			i;
	char		*line;

	i = 0;
	if (!ft_strcmp(src, "/dev/random") || !ft_strcmp(src, "/dev/null"))
		exit(-1);
	(e->fd = open(src, O_RDONLY, S_IWUSR)) == -1 ? exit(-1) : 0;
	if (get_next_line(e->fd, &line) == -1)
		exit(-1);
	(close(e->fd) == -1) ? exit(-1) : 0;
}

static int		ft_count_x(char *line)
{
	int			i;
	int			nb_x;

	i = 0;
	nb_x = 0;
	(!line || line == NULL) ? exit(-1) : 0;
	while (line[i] != '\0')
	{
		(line[i] != ' ' && line[i + 1] == ' ') ? nb_x++ : 0;
		i++;
	}
	return (line[i - 1] == ' ') ? nb_x : nb_x + 1;
}

static void		ft_create_tab(t_env *e, char *src)
{
	char		*line;

	e->x = 0;
	e->y = 0;
	(e->fd = open(src, O_RDONLY, S_IWUSR)) == -1 ? exit(-1) : 0;
	while (get_next_line(e->fd, &line))
	{
		(e->y == 0) ? e->x = ft_count_x(line) : 0;
		e->y++;
	}
	e->x_max = e->x;
	e->y_max = e->y;
	if (e->x_max < 2 || e->y_max < 2)
		exit(-1);
	!(e->tab = malloc(sizeof(t_pt *) * e->y)) ? exit(-1) : 0;
	while (e->y >= 0)
	{
		!(e->tab[e->y] = malloc(sizeof(t_pt) * e->x)) ? exit(-1) : 0;
		e->y--;
	}
	(close(e->fd) == -1) ? exit(-1) : 0;
}

static void		ft_fill_tab(t_env *e, char *src)
{
	int			i;
	char		*line;
	char		**tmp;

	e->y = 0;
	(e->fd = open(src, O_RDONLY, S_IWUSR)) == -1 ? exit(-1) : 0;
	!(tmp = (char **)malloc(sizeof(char *) * e->y + 1)) ? exit(-1) : 0;
	while (e->y < e->y_max)
	{
		e->x = 0;
		get_next_line(e->fd, &line);
		tmp = ft_strsplit(line, ' ');
		while (tmp[e->x] != '\0')
		{
			i = 0;
			e->tab[e->y][e->x].z = ft_atoi(tmp[e->x]);
			while (tmp[e->x][i++])
				if (tmp[e->x][i] == ',')
					e->tab[e->y][e->x].color = ft_atoi_b(&tmp[e->x][i + 3], 16);
			e->x++;
		}
		e->y++;
	}
	(close(e->fd) == -1) ? exit(-1) : 0;
}

int				ft_parse(t_env *e, char *src)
{
	(!e || !src || src == NULL) ? exit(-1) : 0;
	ft_check(e, src);
	ft_create_tab(e, src);
	ft_fill_tab(e, src);
	return (1);
}
