/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:18:32 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 22:02:15 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_components(t_game *g, int frame)
{
	if (g->collected == g->n_collectibles && !g->sprites.exit.open)
		ft_exit_render(g, frame);
	if (g->energy && !(g->energy % 3)
		&& !g->sprites.player.saiyan && g->collected != g->last_saiyan)
		ft_saiyan_render(g);
	if (g->sprites.player.saiyan)
	{
		if (frame == FPS / 2 || frame == FPS
			|| frame == FPS / 4 || frame == FPS / 4 + FPS / 2)
			g->sprites.saiyan.frame++;
		if (g->sprites.saiyan.frame >= 3)
			g->sprites.saiyan.frame = 0;
	}
	if (g->sprites.attack.attacking)
		ft_stop_attack_render(g);
	return (0);
}

int	ft_draw_upper_layer(t_game *g)
{
	if (g->paused && g->game_over)
	{
		if (ft_game_over_render(g))
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
	if (g->sprites.attack.attacking)
		if (ft_attack_render(g))
			return (1);
	if (ft_infos_manager(g))
		return (1);
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
			if (ft_borders_render(g, i, j))
				return (1);
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
			if (ft_draw_render(g, i, j))
				return (1);
	}
	return (0);
}

int	ft_render(t_game *g)
{
	static int	frame;
	char		*moves;

	frame++;
	if (frame > FPS)
		frame = 0;
	if (frame == FPS / 4 || frame == FPS / 4 + FPS / 2)
		if (ft_animate_collectibles(g))
			ft_exit_error(g, g->exit_message);
	if (frame == FPS / 2 || frame == FPS)
		ft_render_manager(g);
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
