/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:51:23 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 19:21:25 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_fill_enemy(t_game *g, t_coords p, int type, int *id)
{
	g->enemies[*id].id = *id;
	g->enemies[*id].type = type - 5;
	g->enemies[*id].pos = p;
	g->enemies[*id].dead = 0;
	g->enemies[*id].next = 1;
	g->enemies[*id].deg = 1 - g->enemies[*id].type;
	(*id)++;
	return (0);
}

int	ft_launch_enemies(t_game *g)
{
	int			i;
	int			j;
	int			id;
	t_coords	p;

	id = 0;
	g->enemies = (t_enemies *) ft_calloc(g->n_enemies, sizeof(t_enemies));
	if (!g->enemies)
		return (ft_error(g, "ft_enemies.c: (t_enemies *) ft_calloc failed."));
	g->allocated.enemies = 1;
	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
		{
			if (g->map.arr[i][j] == 5 || g->map.arr[i][j] == 6)
			{
				p.r = i;
				p.c = j;
				ft_fill_enemy(g, p, g->map.arr[i][j], &id);
			}
		}
	}
	return (0);
}

/*
 * TYPE 0 (number 5)
 * Horizontal enemy goes to the left and the right
 * ---
 * TYPE 1 (number 6)
 * Vertical enemy goes to the top and the bottom
 */
int	ft_move_enemies(t_game *g)
{
	t_coords	p;
	int			i;

	i = -1;
	while (++i < g->n_enemies && !g->paused && !g->freezed)
	{
		p.r = g->enemies[i].pos.r;
		p.c = g->enemies[i].pos.c;
		if (g->enemies[i].type == 0 && !g->enemies[i].dead)
		{
			if (g->enemies[i].next)
				ft_move_enemy_right(g, p, i);
			else
				ft_move_enemy_left(g, p, i);
		}
		if (g->enemies[i].type == 1 && !g->enemies[i].dead)
		{
			if (g->enemies[i].next)
				ft_move_enemy_up(g, p, i);
			else
				ft_move_enemy_down(g, p, i);
		}
	}
	return (0);
}

t_enemies	ft_find_enemy(t_game *g, int r, int c)
{
	int			i;
	t_enemies	empty;

	ft_bzero(&empty, sizeof(t_enemies));
	i = -1;
	while (++i < g->n_enemies)
		if (g->enemies[i].pos.r == r && g->enemies[i].pos.c == c)
			return (g->enemies[i]);
	return (empty);
}
