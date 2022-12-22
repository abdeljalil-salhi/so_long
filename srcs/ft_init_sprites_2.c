/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:30:00 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/21 21:20:17 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_enemy(t_game *g)
{
	g->sprites.enemy.path[0][1][0] = "assets/enemy/right_1.xpm";
	g->sprites.enemy.path[0][1][1] = "assets/enemy/right_2.xpm";
	g->sprites.enemy.path[0][1][2] = "assets/enemy/right_3.xpm";
	g->sprites.enemy.path[0][1][3] = "assets/enemy/right_4.xpm";
	g->sprites.enemy.path[0][3][0] = "assets/enemy/left_1.xpm";
	g->sprites.enemy.path[0][3][1] = "assets/enemy/left_2.xpm";
	g->sprites.enemy.path[0][3][2] = "assets/enemy/left_3.xpm";
	g->sprites.enemy.path[0][3][3] = "assets/enemy/left_4.xpm";
	g->sprites.enemy.path[1][0][0] = "assets/enemy/right_1.xpm";
	g->sprites.enemy.path[1][0][1] = "assets/enemy/right_2.xpm";
	g->sprites.enemy.path[1][0][2] = "assets/enemy/right_3.xpm";
	g->sprites.enemy.path[1][0][3] = "assets/enemy/right_4.xpm";
	g->sprites.enemy.path[1][2][0] = "assets/enemy/left_1.xpm";
	g->sprites.enemy.path[1][2][1] = "assets/enemy/left_2.xpm";
	g->sprites.enemy.path[1][2][2] = "assets/enemy/left_3.xpm";
	g->sprites.enemy.path[1][2][3] = "assets/enemy/left_4.xpm";
	g->sprites.enemy.frame = 0;
	return (0);
}

int	ft_init_border(t_game *g)
{
	g->sprites.border[0] = "assets/border/top.xpm";
	g->sprites.border[1] = "assets/border/right.xpm";
	g->sprites.border[2] = "assets/border/bottom.xpm";
	g->sprites.border[3] = "assets/border/left.xpm";
	return (0);
}