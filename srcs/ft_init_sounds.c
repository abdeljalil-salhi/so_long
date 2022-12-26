/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:32:03 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/26 15:53:07 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_afplay(t_game *g, char *path)
{
	char	*cmd;

	cmd = ft_strjoin("afplay ", path);
	if (!cmd)
		return(ft_error(g, "ft_strjoin failed in ft_afplay."));
	system(cmd);
	free(cmd);
	return (0);
}

int	ft_init_sounds(t_game *g)
{
	g->sounds.soundtrack = "sounds/theme.mp3";
	g->sounds.saiyan = "sounds/saiyan.mp3";
	g->sounds.collected = "sounds/collected.wav";
	g->sounds.won = "sounds/won.wav";
	g->sounds.lost = "sounds/lost.wav";
	g->sounds.opening = "sounds/opening.mp3";
	g->pid.effect_playing = 0;
	return (0);
}

void	ft_play_sound_track(t_game *g)
{
	g->pid.sound_track = fork();
	if (g->pid.sound_track == -1)
		ft_exit_error(g, "Failed creating the fork for the sound track.");
	if (!g->pid.sound_track)
	{
		while (access(TMP, R_OK) == -1)
			if (ft_afplay(g, g->sounds.soundtrack))
				ft_exit_error(g, g->exit_message);
		exit(0);
	}
}

void	ft_play_sound_effect(t_game *g, char *sound)
{
	if (g->pid.effect_playing)
		return ;
	g->pid.sound_effect = fork();
	if (g->pid.sound_effect == -1)
		ft_exit_error(g, "Failed creating the fork for the sound effect.");
	if (!g->pid.sound_effect)
	{
		g->pid.effect_playing = 1;
		if (ft_afplay(g, sound))
			ft_exit_error(g, g->exit_message);
		g->pid.effect_playing = 0;
		exit(0);
	}
}

void	ft_stop_sound_track(t_game *g)
{
	system("killall afplay");
	kill(g->pid.sound_track, SIGKILL);
}
