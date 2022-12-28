/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_attack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:38:01 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 18:23:41 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_draw_attack_left(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r;
	j = g->sprites.player.pos.c;
	while (--j >= 0)
	{
		if (j == 0 || g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i][j - 1] == 1)
		{
			if (ft_new_attack(g, i, j, 2))
				return (1);
			break ;
		}
		else if (j == g->sprites.player.pos.c - 1)
		{
			if (ft_new_attack(g, i, j, 0))
				return (1);
		}
		else
			if (ft_new_attack(g, i, j, 1))
				return (1);
	}
	return (0);
}

int	ft_draw_attack_right(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r;
	j = g->sprites.player.pos.c;
	while (++j < g->win.width)
	{
		if (j == g->win.width - 1 || g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i][j + 1] == 1)
		{
			if (ft_new_attack(g, i, j, 2))
				return (1);
			break ;
		}
		else if (j == g->sprites.player.pos.c + 1)
		{
			if (ft_new_attack(g, i, j, 0))
				return (1);
		}
		else
			if (ft_new_attack(g, i, j, 1))
				return (1);
	}
	return (0);
}

int	ft_draw_attack_up(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r;
	j = g->sprites.player.pos.c;
	while (--i >= 0)
	{
		if (i == 0 || g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i - 1][j] == 1)
		{
			if (ft_new_attack(g, i, j, 2))
				return (1);
			break ;
		}
		else if (i == g->sprites.player.pos.r - 1)
		{
			if (ft_new_attack(g, i, j, 0))
				return (1);
		}
		else
			if (ft_new_attack(g, i, j, 1))
				return (1);
	}
	return (0);
}

int	ft_draw_attack_down(t_game *g)
{
	int	i;
	int	j;

	i = g->sprites.player.pos.r;
	j = g->sprites.player.pos.c;
	while (++i < g->win.height)
	{
		if (i == g->win.height - 1 || g->map.arr[i][j] == 1)
			return (0);
		if (g->map.arr[i + 1][j] == 1)
		{
			if (ft_new_attack(g, i, j, 2))
				return (1);
			break ;
		}
		else if (i == g->sprites.player.pos.r + 1)
		{
			if (ft_new_attack(g, i, j, 0))
				return (1);
		}
		else
			if (ft_new_attack(g, i, j, 1))
				return (1);
	}
	return (0);
}
