/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_attack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:57:15 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 12:08:28 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_attack_player(t_game *g)
{
	t_coords	pos;

	g->paused = 1;
	pos = g->sprites.player.pos;
	if (g->sprites.player.deg == 0)
	{
		ft_new_attack(g, pos.r - 1, pos.c, 0);
		ft_new_attack(g, pos.r - 2, pos.c, 1);
		ft_new_attack(g, pos.r - 3, pos.c, 2);
		ft_kill_enemy_up(g);
	}
	else if (g->sprites.player.deg == 1)
	{
		ft_kill_enemy_right(g);
	}
	else if (g->sprites.player.deg == 2)
	{
		ft_kill_enemy_down(g);
	}
	else if (g->sprites.player.deg == 3)
	{
		ft_kill_enemy_left(g);
	}
	g->paused = 0;
	g->sprites.player.saiyan = 0;
	return (0);
}
