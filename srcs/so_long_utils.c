/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:18:57 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/26 12:26:57 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
static void	ft_print_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
			ft_printf("%d", g->map.arr[i][j]);
		ft_printf("\n");
	}
}
*/

static int	ft_init_sprites(t_game *g)
{
	if (ft_init_player(g))
		return (1);
	if (ft_init_exit(g))
		return (1);
	if (ft_init_collectibles(g))
		return (1);
	if (ft_init_wall(g))
		return (1);
	if (ft_init_ground(g))
		return (1);
	if (ft_init_enemy(g))
		return (1);
	if (ft_init_border(g))
		return (1);
	return (0);
}

int	ft_player_pos(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
		{
			if (g->map.arr[i][j] == 2)
			{
				g->sprites.player.pos.r = i;
				g->sprites.player.pos.c = j;
			}
		}
	}
	return (0);
}

int	ft_check_and_init(t_game *g, char *map)
{
	g->map.file.name = map;
	g->paused = 0;
	g->game_over = 0;
	g->won = 0;
	g->moves = 0;
	if (ft_check_extension(g))
		return (1);
	if (ft_read_file(g))
		return (1);
	if (ft_init_map(g))
		return (1);
	if (ft_check_map(g))
		return (1);
	if (ft_init_sprites(g))
		return (1);
	if (ft_init_sounds(g))
		return (1);
	if (ft_player_pos(g))
		return (1);
	if (ft_launch_collectibles(g))
		return (1);
	if (ft_launch_enemies(g))
		return (1);
	return (0);
}
