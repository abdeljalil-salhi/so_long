/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_norm_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:55:12 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 22:34:57 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_borders_render(t_game *g, int i, int j)
{
	if (i == 0)
		if (ft_new_border(g, i, j, g->sprites.border[0]))
			return (1);
	if (j == 0)
		if (ft_new_border(g, i, j, g->sprites.border[3]))
			return (1);
	if (i == g->win.height + 1)
		if (ft_new_border(g, i, j, g->sprites.border[2]))
			return (1);
	if (j == g->win.width + 1)
		if (ft_new_border(g, i, j, g->sprites.border[1]))
			return (1);
	if ((i == 0 || i == g->win.height + 1)
		&& (j == 0 || j == g->win.width + 1))
		if (ft_new_border(g, i, j, g->sprites.wall.path[0]))
			return (1);
	return (0);
}

static int	ft_draw_ground_condition(t_game *g, int i, int j)
{
	return (g->map.arr[i][j] == 0 || g->map.arr[i][j] == 2
			|| (4 <= g->map.arr[i][j] && g->map.arr[i][j] <= 6)
			|| (g->map.arr[i][j] == 1 && i != 0));
}

int	ft_draw_render(t_game *g, int i, int j)
{
	if (ft_draw_ground_condition(g, i, j))
		if (ft_new_ground(g, i, j))
			return (1);
	if (g->map.arr[i][j] == 1 || g->map.arr[i][j] == 3)
		if (ft_new_wall(g, i, j))
			return (1);
	if (g->map.arr[i][j] == 2 && g->sprites.player.saiyan)
		if (ft_new_saiyan(g, i, j))
			return (1);
	if (g->map.arr[i][j] == 2)
		if (ft_new_player(g, i, j))
			return (1);
	if (g->map.arr[i][j] == 3)
		if (ft_new_exit(g, i, j))
			return (1);
	if (g->map.arr[i][j] == 4)
		if (ft_new_collectible(g, i, j))
			return (1);
	if (g->map.arr[i][j] == 5)
		if (ft_new_enemy(g, i, j, 0))
			return (1);
	if (g->map.arr[i][j] == 6)
		if (ft_new_enemy(g, i, j, 1))
			return (1);
	return (0);
}

void	ft_render_manager(t_game *g)
{
	if (g->paused && g->tip.display)
		g->tip.display = 0;
	else if (g->paused && !g->tip.display)
		g->tip.display = 1;
	if (g->sprites.player.frame == 1 && !g->freezed)
		g->sprites.player.frame = 0;
	else if (g->sprites.player.frame == 0 && !g->freezed)
		g->sprites.player.frame = 1;
	if (ft_move_enemies(g))
		ft_exit_error(g, g->exit_message);
	if (ft_animate_enemies(g))
		ft_exit_error(g, g->exit_message);
	if (ft_animate_collectibles(g))
		ft_exit_error(g, g->exit_message);
}

int	ft_infos_manager(t_game *g)
{
	if (ft_new_avatar(g))
		return (1);
	if (ft_new_energy(g))
		return (1);
	return (0);
}
