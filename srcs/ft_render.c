/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:18:32 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/25 18:10:43 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_components(t_game *g, int frame)
{
	if (!g->n_collectibles && !g->sprites.exit.open)
	{
		if (!g->sprites.exit.opening)
		{
			g->sprites.exit.closed = 0;
			g->sprites.exit.opening = 1;
		}
		if (frame == FPS / 2 || frame == FPS
			|| frame == FPS / 4 || frame == FPS / 4 + FPS / 2)
			g->sprites.exit.frame++;
		if (g->sprites.exit.frame == 5)
		{
			g->sprites.exit.opening = 0;
			g->sprites.exit.open = 1;
		}
	}
	return (0);
}

int	ft_draw_upper_layer(t_game *g)
{
	if (g->paused && g->game_over)
	{
		g->tip.message = ESC_MESSAGE;
		if (g->tip.display)
			if (ft_new_tip(g, COLOR))
				return (1);
		if (ft_new_centered(g, "assets/game_over.xpm"))
			return (1);
		if (ft_new_centered(g, "assets/game_over_text.xpm"))
			return (1);
	}
	else if (g->paused)
	{
		g->tip.message = P_MESSAGE;
		if (g->tip.display)
			if (ft_new_tip(g, COLOR))
				return (1);
		if (ft_new_centered(g, "assets/game_over.xpm"))
			return (1);
	}
	return (0);
}

int	ft_draw_borders(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->win.height + 2)
	{
		j = -1;
		while (++j < g->win.width + 2)
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
			if (((i == 0 || i == g->win.height + 1)
					&& (j == 0 || j == g->win.width + 1)))
				if (ft_new_border(g, i, j, g->sprites.wall.path[0]))
					return (1);
		}
	}
	return (0);
}

int	ft_draw(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
		{
			if (g->map.arr[i][j] == 0 || g->map.arr[i][j] == 2
					|| (4 <= g->map.arr[i][j] && g->map.arr[i][j] <= 6)
					|| (g->map.arr[i][j] == 1 && i != 0))
				if (ft_new_ground(g, i, j))
					return (1);
			if (g->map.arr[i][j] == 1 || g->map.arr[i][j] == 3)
				if (ft_new_wall(g, i, j))
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
		}
	}
	return (0);
}

int	ft_render(t_game *g)
{
	static int	frame;
	char		*moves;

	frame++;
	if (frame == FPS / 4 || frame == FPS / 4 + FPS / 2)
		if (ft_animate_collectibles(g))
			ft_exit_error(g, g->exit_message);
	if (frame == FPS / 2 || frame == FPS)
	{
		if (g->paused && g->tip.display)
			g->tip.display = 0;
		else if (g->paused && !g->tip.display)
			g->tip.display = 1;
		if (g->sprites.player.frame == 1)
			g->sprites.player.frame = 0;
		else if (g->sprites.player.frame == 0)
			g->sprites.player.frame = 1;
		if (ft_move_enemies(g))
			ft_exit_error(g, g->exit_message);
		if (ft_animate_enemies(g))
			ft_exit_error(g, g->exit_message);
		if (ft_animate_collectibles(g))
			ft_exit_error(g, g->exit_message);
	}
	if (frame >= FPS)
		frame = 0;
	if (ft_check_components(g, frame))
		ft_exit_error(g, g->exit_message);
	mlx_clear_window(g->mlx, g->win.ref);
	moves = ft_itoa(g->moves);
	mlx_string_put(g->mlx, g->win.ref, 10, 5, COLOR, moves);
	free(moves);
	if (ft_draw(g))
		ft_exit_error(g, g->exit_message);
	if (ft_draw_upper_layer(g))
		ft_exit_error(g, g->exit_message);
	return (0);
}
