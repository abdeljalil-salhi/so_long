/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:02:51 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/25 01:10:26 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_animate_enemies(t_game *g)
{
	g->sprites.enemy.frame++;
	if (g->sprites.enemy.frame >= 4)
		g->sprites.enemy.frame = 0;
	return (0);
}

int	ft_animate_collectibles(t_game *g)
{
	if (g->sprites.collec.next)
	{
		if (g->sprites.collec.y == 1)
			g->sprites.collec.next = 0;
		g->sprites.collec.y++;
	}
	else
	{
		if (g->sprites.collec.y == 1)
			g->sprites.collec.next = 1;
		g->sprites.collec.y--;
	}
	return (0);
}
