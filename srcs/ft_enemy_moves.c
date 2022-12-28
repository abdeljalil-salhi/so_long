/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:12:54 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 19:22:35 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_enemy_left(t_game *g, t_coords p, int i)
{
	g->enemies[i].deg = 3;
	if (p.c - 1 >= 0 && g->map.arr[p.r][p.c - 1] != 0)
		g->enemies[i].next = 1;
	else if (p.c - 1 > 0 && g->map.arr[p.r][p.c - 1] == 0)
	{
		g->map.arr[p.r][p.c] = 0;
		g->map.arr[p.r][p.c - 1] = 5;
		g->enemies[i].pos.c--;
	}
	if (p.c - 1 == g->sprites.player.pos.c && p.r == g->sprites.player.pos.r)
		ft_game_over(g);
}

void	ft_move_enemy_right(t_game *g, t_coords p, int i)
{
	g->enemies[i].deg = 1;
	if (p.c + 1 <= g->win.width && g->map.arr[p.r][p.c + 1] != 0)
		g->enemies[i].next = 0;
	else if (p.c + 1 < g->win.width && g->map.arr[p.r][p.c + 1] == 0)
	{
		g->map.arr[p.r][p.c] = 0;
		g->map.arr[p.r][p.c + 1] = 5;
		g->enemies[i].pos.c++;
	}
	if (p.c + 1 == g->sprites.player.pos.c && p.r == g->sprites.player.pos.r)
		ft_game_over(g);
}

void	ft_move_enemy_up(t_game *g, t_coords p, int i)
{
	g->enemies[i].deg = 0;
	if (p.r + 1 <= g->win.height && g->map.arr[p.r + 1][p.c] != 0)
		g->enemies[i].next = 0;
	else if (p.r + 1 < g->win.height && g->map.arr[p.r + 1][p.c] == 0)
	{
		g->map.arr[p.r][p.c] = 0;
		g->map.arr[p.r + 1][p.c] = 6;
		g->enemies[i].pos.r++;
	}
	if (p.r + 1 == g->sprites.player.pos.r && p.c == g->sprites.player.pos.c)
		ft_game_over(g);
}

void	ft_move_enemy_down(t_game *g, t_coords p, int i)
{
	g->enemies[i].deg = 2;
	if (p.r - 1 >= 0 && g->map.arr[p.r - 1][p.c] != 0)
		g->enemies[i].next = 1;
	else if (p.r - 1 > 0 && g->map.arr[p.r - 1][p.c] == 0)
	{
		g->map.arr[p.r][p.c] = 0;
		g->map.arr[p.r - 1][p.c] = 6;
		g->enemies[i].pos.r--;
	}
	if (p.r - 1 == g->sprites.player.pos.r && p.c == g->sprites.player.pos.c)
		ft_game_over(g);
}
