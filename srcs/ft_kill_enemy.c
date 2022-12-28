/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:28:32 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 18:24:33 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_kill_enemy_left(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r;
	j = g->sprites.player.pos.c + 1;
	while (--j > 0)
	{
		if (g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i][j] == 5 || g->map.arr[i][j] == 6)
		{
			g->enemies[ft_find_enemy(g, i, j).id].dead = 1;
			g->map.arr[i][j] = 0;
		}
	}
	return (0);
}

int	ft_kill_enemy_right(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r;
	j = g->sprites.player.pos.c - 1;
	while (++j < g->win.width)
	{
		if (g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i][j] == 5 || g->map.arr[i][j] == 6)
		{
			g->enemies[ft_find_enemy(g, i, j).id].dead = 1;
			g->map.arr[i][j] = 0;
		}
	}
	return (0);
}

int	ft_kill_enemy_up(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r + 1;
	j = g->sprites.player.pos.c;
	while (--i > 0)
	{
		if (g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i][j] == 5 || g->map.arr[i][j] == 6)
		{
			g->enemies[ft_find_enemy(g, i, j).id].dead = 1;
			g->map.arr[i][j] = 0;
		}
	}
	return (0);
}

int	ft_kill_enemy_down(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r - 1;
	j = g->sprites.player.pos.c;
	while (++i < g->win.height)
	{
		if (g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i][j] == 5 || g->map.arr[i][j] == 6)
		{
			g->enemies[ft_find_enemy(g, i, j).id].dead = 1;
			g->map.arr[i][j] = 0;
		}
	}
	return (0);
}
