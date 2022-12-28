/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectibles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:38:16 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 19:07:27 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

struct s_lc
{
	int			i;
	int			j;
	t_coords	p;
};

static int	ft_check_if_type_already_exists(t_game *g, int type)
{
	int	i;

	i = -1;
	while (++i < g->n_collectibles && g->collectibles[i].init)
		if (g->collectibles[i].type == type)
			return (1);
	return (0);
}

int	ft_fill_collectible(t_game *g, t_coords p, int *id)
{
	int	r;

	g->collectibles[*id].id = *id;
	while (1)
	{
		r = rand() % COLLEC_TYPES;
		if (*id < COLLEC_TYPES)
		{
			if (!ft_check_if_type_already_exists(g, r))
				break ;
		}
		else
			break ;
	}
	g->collectibles[*id].type = r;
	g->collectibles[*id].pos = p;
	g->collectibles[*id].init = 1;
	(*id)++;
	return (0);
}

int	ft_launch_collectibles(t_game *g)
{
	struct s_lc	s;
	int			id;

	id = 0;
	srand((unsigned int) time(NULL));
	g->collectibles = (t_collecs *) ft_calloc(g->n_collectibles,
			sizeof(t_collecs));
	if (!g->collectibles)
		return (ft_error(g, "ft_collectibles.c: ft_calloc failed."));
	g->allocated.collectibles = 1;
	s.i = -1;
	while (++s.i < g->win.height)
	{
		s.j = -1;
		while (++s.j < g->win.width)
		{
			if (g->map.arr[s.i][s.j] == 4)
			{
				s.p.r = s.i;
				s.p.c = s.j;
				ft_fill_collectible(g, s.p, &id);
			}
		}
	}
	return (0);
}

t_collecs	ft_find_collectible(t_game *g, int r, int c)
{
	int			i;
	t_collecs	empty;

	ft_bzero(&empty, sizeof(t_collecs));
	i = -1;
	while (++i < g->n_collectibles)
		if (g->collectibles[i].pos.r == r && g->collectibles[i].pos.c == c)
			return (g->collectibles[i]);
	return (empty);
}
