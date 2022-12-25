/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:41:40 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/25 01:08:26 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_player(t_game *g)
{
	g->sprites.player.path[0][0] = "assets/player/top.xpm";
	g->sprites.player.path[0][1] = "assets/player/top.xpm";
	g->sprites.player.path[1][0] = "assets/player/right_1.xpm";
	g->sprites.player.path[1][1] = "assets/player/right_2.xpm";
	g->sprites.player.path[2][0] = "assets/player/bottom_1.xpm";
	g->sprites.player.path[2][1] = "assets/player/bottom_2.xpm";
	g->sprites.player.path[3][0] = "assets/player/left_1.xpm";
	g->sprites.player.path[3][1] = "assets/player/left_2.xpm";
	g->sprites.player.path[4][0] = "assets/player/dying.xpm";
	g->sprites.player.path[4][1] = "assets/player/dead.xpm";
	g->sprites.player.frame = 0;
	g->sprites.player.standing = 1;
	g->sprites.player.energy = 0;
	g->sprites.player.dying = 0;
	g->sprites.player.dead = 0;
	g->sprites.player.deg = 2;
	return (0);
}

int	ft_init_exit(t_game *g)
{
	g->sprites.exit.path[0] = "assets/exit/closed.xpm";
	g->sprites.exit.path[1] = "assets/exit/opening_1.xpm";
	g->sprites.exit.path[2] = "assets/exit/opening_2.xpm";
	g->sprites.exit.path[3] = "assets/exit/opening_3.xpm";
	g->sprites.exit.path[4] = "assets/exit/opening_4.xpm";
	g->sprites.exit.path[5] = "assets/exit/open.xpm";
	g->sprites.exit.frame = 0;
	g->sprites.exit.closed = 1;
	g->sprites.exit.opening = 0;
	g->sprites.exit.open = 0;
	return (0);
}

int	ft_init_collectibles(t_game *g)
{
	g->sprites.collec.path[0] = "assets/collectibles/ball_1.xpm";
	g->sprites.collec.path[1] = "assets/collectibles/ball_2.xpm";
	g->sprites.collec.path[2] = "assets/collectibles/ball_3.xpm";
	g->sprites.collec.path[3] = "assets/collectibles/ball_4.xpm";
	g->sprites.collec.path[4] = "assets/collectibles/ball_5.xpm";
	g->sprites.collec.path[5] = "assets/collectibles/ball_6.xpm";
	g->sprites.collec.path[6] = "assets/collectibles/ball_7.xpm";
	g->sprites.collec.frame = 0;
	g->sprites.collec.next = 1;
	g->sprites.collec.y = 0;
	return (0);
}

int	ft_init_wall(t_game *g)
{
	g->sprites.wall.path[0] = "assets/wall/wall_3.xpm";
	g->sprites.wall.path[1] = "assets/wall/wall_2.xpm";
	g->sprites.wall.path[2] = "assets/wall/wall_3.xpm";
	g->sprites.wall.frame = 0;
	return (0);
}

int	ft_init_ground(t_game *g)
{
	g->sprites.ground.path[0] = "assets/ground/ground_1.xpm";
	g->sprites.ground.path[1] = "assets/ground/ground_2.xpm";
	g->sprites.ground.path[2] = "assets/ground/ground_3.xpm";
	g->sprites.ground.frame = 0;
	return (0);
}
