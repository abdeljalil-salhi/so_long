/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectibles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:38:16 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/25 18:04:56 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	int			i;
	int			j;
	int			id;
	t_coords	p;

	id = 0;
	srand((unsigned int) time(NULL));
	g->collectibles = (t_collecs *) ft_calloc(g->n_collectibles, sizeof(t_collecs));
	if (!g->collectibles)
		return (ft_error(g, "ft_collectibles.c: ft_calloc failed."));
	g->allocated.collectibles = 1;
	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
		{
			if (g->map.arr[i][j] == 4)
			{
				p.r = i;
				p.c = j;
				ft_fill_collectible(g, p, &id);
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
