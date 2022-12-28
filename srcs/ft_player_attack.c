/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_attack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:57:15 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 18:06:31 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_attack_player(t_game *g)
{
	g->freezed = 1;
	g->sprites.attack.attacking = 1;
	if (g->sprites.attack.duration == 7)
	{
		if (g->sprites.player.deg == 5)
			ft_kill_enemy_up(g);
		else if (g->sprites.player.deg == 6)
			ft_kill_enemy_right(g);
		else if (g->sprites.player.deg == 7)
			ft_kill_enemy_down(g);
		else if (g->sprites.player.deg == 8)
			ft_kill_enemy_left(g);
	}
	return (0);
}

int	ft_draw_attack(t_game *g)
{
	if (g->sprites.player.deg == 5)
	{
		if (ft_draw_attack_up(g))
			return (1);
	}
	else if (g->sprites.player.deg == 6)
	{
		if (ft_draw_attack_right(g))
			return (1);
	}
	else if (g->sprites.player.deg == 7)
	{
		if (ft_draw_attack_down(g))
			return (1);
	}
	else if (g->sprites.player.deg == 8)
	{
		if (ft_draw_attack_left(g))
			return (1);
	}
	return (0);
}
