/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:44:58 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 21:15:32 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_render(t_game *g, int frame)
{
	if (!g->sprites.exit.opening)
	{
		g->sprites.exit.closed = 0;
		g->sprites.exit.opening = 1;
		ft_play_sound_effect(g, g->sounds.opening);
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

void	ft_saiyan_render(t_game *g)
{
	g->last_saiyan = g->collected;
	g->sprites.player.saiyan = 1;
	if (open(TMP, O_CREAT | O_WRONLY | O_TRUNC, 0644) < 0)
		ft_exit_error(g, "Error while creating temporary file.");
	ft_stop_sound_track(g);
	unlink(TMP);
	ft_play_sound_track(g, 1);
}

void	ft_stop_attack_render(t_game *g)
{
	g->sprites.attack.duration++;
	if (g->sprites.attack.duration == FPS)
	{
		g->sprites.attack.attacking = 0;
		g->sprites.attack.duration = 0;
		g->sprites.player.saiyan = 0;
		g->sprites.player.deg -= 5;
		g->freezed = 0;
		if (open(TMP, O_CREAT | O_WRONLY | O_TRUNC, 0644) < 0)
			ft_exit_error(g, "Error while creating temporary file.");
		ft_stop_sound_track(g);
		unlink(TMP);
		ft_play_sound_track(g, 0);
	}
}

int	ft_game_over_render(t_game *g)
{
	g->tip.message = ESC_MESSAGE;
	if (g->tip.display)
		if (ft_new_tip(g, COLOR))
			return (1);
	if (ft_new_centered(g, "assets/game_over.xpm"))
		return (1);
	if (ft_new_centered(g, "assets/game_over_text.xpm"))
		return (1);
	return (0);
}

int	ft_attack_render(t_game *g)
{
	if (g->sprites.attack.duration <= 5)
	{
		if (g->sprites.player.deg < 5)
			g->sprites.player.deg += 5;
		g->sprites.player.frame = 0;
	}
	else if (g->sprites.attack.duration > 5)
		g->sprites.player.frame = 1;
	if (g->sprites.attack.duration > 6)
		if (ft_draw_attack(g))
			return (1);
	if (g->sprites.attack.duration == 7)
		ft_attack_player(g);
	return (0);
}
