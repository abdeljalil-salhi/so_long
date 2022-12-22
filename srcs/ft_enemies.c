/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:51:23 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/21 22:01:56 by absalhi          ###   ########.fr       */
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
	g->enemies[*id].deg = 0;
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
	g->enemies = (t_enemies *) ft_calloc(g->n_enemies + 1, sizeof(t_enemies));
	if (!g->enemies)
		return (ft_error(g, "ft_enemies.c: (t_enemies *) ft_calloc failed."));
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
	while (++i < g->n_enemies && !g->paused)
	{
		p.r = g->enemies[i].pos.r;
		p.c = g->enemies[i].pos.c;
		if (g->enemies[i].type == 0 && !g->enemies[i].dead)
		{
			if (g->enemies[i].next)
			{
				if (p.c + 1 < g->win.width && g->map.arr[p.r][p.c + 1] != 0)
					g->enemies[i].next = 0;
				else if (p.c + 1 < g->win.width && g->map.arr[p.r][p.c + 1] != 1)
				{
					g->map.arr[p.r][p.c] = 0;
					g->map.arr[p.r][p.c + 1] = 5;
					g->enemies[i].deg = 1;
					g->enemies[i].pos.c++;
				}
				else if (p.c + 1 < g->win.width && g->map.arr[p.r][p.c + 1] == 2)
					ft_game_over(g);
			}
			else
			{
				if (p.c - 1 > 0 && g->map.arr[p.r][p.c - 1] == 1)
					g->enemies[i].next = 1;
				else if (p.c - 1 > 0 && g->map.arr[p.r][p.c - 1] != 1)
				{
					g->map.arr[p.r][p.c] = 0;
					g->map.arr[p.r][p.c - 1] = 5;
					g->enemies[i].deg = 3;
					g->enemies[i].pos.c--;
				}
				else if (p.c - 1 > 0 && g->map.arr[p.r][p.c - 1] == 2)
					ft_game_over(g);
			}
		}
		if (g->enemies[i].type == 1 && !g->enemies[i].dead)
		{
			if (g->enemies[i].next)
			{
				if (p.r + 1 < g->win.height && g->map.arr[p.r + 1][p.c] != 0)
					g->enemies[i].next = 0;
				else if (p.r + 1 < g->win.height && g->map.arr[p.r + 1][p.c] != 1)
				{
					g->map.arr[p.r][p.c] = 0;
					g->map.arr[p.r + 1][p.c] = 6;
					g->enemies[i].deg = 0;
					g->enemies[i].pos.r++;
				}
				else if (p.r + 1 < g->win.height && g->map.arr[p.r + 1][p.c] == 2)
					ft_game_over(g);
			}
			else
			{
				if (p.r - 1 > 0 && g->map.arr[p.r - 1][p.c] != 0)
					g->enemies[i].next = 1;
				else if (p.r - 1 > 0 && g->map.arr[p.r - 1][p.c] != 1)
				{
					g->map.arr[p.r][p.c] = 0;
					g->map.arr[p.r - 1][p.c] = 6;
					g->enemies[i].deg = 2;
					g->enemies[i].pos.r--;
				}
				else if (p.r - 1 > 0 && g->map.arr[p.r - 1][p.c] == 2)
					ft_game_over(g);
			}
		}
	}
	return (0);
}

int	ft_animate_enemies(t_game *g)
{
	g->sprites.enemy.frame++;
	if (g->sprites.enemy.frame >= 4)
		g->sprites.enemy.frame = 0;
	return (0);
}
