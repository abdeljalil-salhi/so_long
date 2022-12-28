/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:30:00 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 19:42:55 by absalhi          ###   ########.fr       */
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
	g->sprites.enemy.path[1][0][0] = "assets/enemy/down_1.xpm";
	g->sprites.enemy.path[1][0][1] = "assets/enemy/down_2.xpm";
	g->sprites.enemy.path[1][0][2] = "assets/enemy/down_3.xpm";
	g->sprites.enemy.path[1][0][3] = "assets/enemy/down_4.xpm";
	g->sprites.enemy.path[1][2][0] = "assets/enemy/up_1.xpm";
	g->sprites.enemy.path[1][2][1] = "assets/enemy/up_2.xpm";
	g->sprites.enemy.path[1][2][2] = "assets/enemy/up_3.xpm";
	g->sprites.enemy.path[1][2][3] = "assets/enemy/up_4.xpm";
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

int	ft_init_saiyan(t_game *g)
{
	g->sprites.saiyan.path[0] = "assets/saiyan/saiyan_1.xpm";
	g->sprites.saiyan.path[1] = "assets/saiyan/saiyan_2.xpm";
	g->sprites.saiyan.path[2] = "assets/saiyan/saiyan_3.xpm";
	g->sprites.saiyan.frame = 0;
	return (0);
}

int	ft_init_attack(t_game *g)
{
	g->sprites.attack.path[0][0] = "assets/attack/attack_0_1.xpm";
	g->sprites.attack.path[0][1] = "assets/attack/attack_0_2.xpm";
	g->sprites.attack.path[0][2] = "assets/attack/attack_0_3.xpm";
	g->sprites.attack.path[1][0] = "assets/attack/attack_1_1.xpm";
	g->sprites.attack.path[1][1] = "assets/attack/attack_1_2.xpm";
	g->sprites.attack.path[1][2] = "assets/attack/attack_1_3.xpm";
	g->sprites.attack.path[2][0] = "assets/attack/attack_2_1.xpm";
	g->sprites.attack.path[2][1] = "assets/attack/attack_2_2.xpm";
	g->sprites.attack.path[2][2] = "assets/attack/attack_2_3.xpm";
	g->sprites.attack.path[3][0] = "assets/attack/attack_3_1.xpm";
	g->sprites.attack.path[3][1] = "assets/attack/attack_3_2.xpm";
	g->sprites.attack.path[3][2] = "assets/attack/attack_3_3.xpm";
	g->sprites.attack.attacking = 0;
	g->sprites.attack.duration = 0;
	return (0);
}
