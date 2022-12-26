/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:09:41 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/26 12:26:30 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_move(t_game *g, int r, int c)
{
	if (g->map.arr[r][c] == 4)
	{
		ft_play_sound_effect(g, g->sounds.collected);
		g->n_collectibles--;
	}
	if (g->map.arr[r][c] == 3 && g->sprites.exit.open == 1)
	{
		g->won = 1;
		ft_game_over(g);
	}
	if (g->map.arr[r][c] == 5 || g->map.arr[r][c] == 6)
	{
		ft_game_over(g);
		return (1);
	}
	if (g->map.arr[r][c] == 3)
		return (1);
	return (0);
}

int	ft_move_player_left(t_game *g)
{
	int	r;
	int	c;

	if (g->paused)
		return (0);
	r = g->sprites.player.pos.r;
	c = g->sprites.player.pos.c;
	g->sprites.player.deg = 3;
	if (c - 1 > 0 && g->map.arr[r][c - 1] != 1)
	{
		if (ft_check_move(g, r, c - 1))
			return (0);
		g->map.arr[r][c] = 0;
		g->map.arr[r][c - 1] = 2;
		g->sprites.player.pos.c--;
		g->moves++;
	}
	return (0);
}

int	ft_move_player_right(t_game *g)
{
	int	r;
	int	c;

	if (g->paused)
		return (0);
	r = g->sprites.player.pos.r;
	c = g->sprites.player.pos.c;
	g->sprites.player.deg = 1;
	if (c + 1 < g->win.width && g->map.arr[r][c + 1] != 1)
	{
		if (ft_check_move(g, r, c + 1))
			return (0);
		g->map.arr[r][c] = 0;
		g->map.arr[r][c + 1] = 2;
		g->sprites.player.pos.c++;
		g->moves++;
	}
	return (0);
}

int	ft_move_player_up(t_game *g)
{
	int	r;
	int	c;

	if (g->paused)
		return (0);
	r = g->sprites.player.pos.r;
	c = g->sprites.player.pos.c;
	g->sprites.player.deg = 0;
	if (r - 1 > 0 && g->map.arr[r - 1][c] != 1)
	{
		if (ft_check_move(g, r - 1, c))
			return (0);
		g->map.arr[r][c] = 0;
		g->map.arr[r - 1][c] = 2;
		g->sprites.player.pos.r--;
		g->moves++;
	}
	return (0);
}

int	ft_move_player_down(t_game *g)
{
	int	r;
	int	c;

	if (g->paused)
		return (0);
	r = g->sprites.player.pos.r;
	c = g->sprites.player.pos.c;
	g->sprites.player.deg = 2;
	if (r + 1 < g->win.height && g->map.arr[r + 1][c] != 1)
	{
		if (ft_check_move(g, r + 1, c))
			return (0);
		g->map.arr[r][c] = 0;
		g->map.arr[r + 1][c] = 2;
		g->sprites.player.pos.r++;
		g->moves++;
	}
	return (0);
}
