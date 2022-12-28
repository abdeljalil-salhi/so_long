/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:25:53 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 17:53:11 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_key_hook(int keycode, t_game *g)
{
	if (keycode == ESC)
		ft_free_exit(g);
	else if (keycode == ARROW_LEFT || keycode == KEY_A)
		ft_move_player_left(g);
	else if (keycode == ARROW_RIGHT || keycode == KEY_D)
		ft_move_player_right(g);
	else if (keycode == ARROW_UP || keycode == KEY_W)
		ft_move_player_up(g);
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		ft_move_player_down(g);
	else if (keycode == KEY_P && !g->game_over)
		ft_game_paused(g);
	else if (keycode == KEY_SPACE && !g->paused && g->sprites.player.saiyan)
		ft_attack_player(g);
	return (0);
}

void	ft_game_paused(t_game *g)
{
	g->paused = !g->paused;
	g->freezed = !g->freezed;
}

void	ft_game_over(t_game *g)
{
	ft_printf("GAME OVER\n");
	g->paused = 1;
	g->freezed = 1;
	g->game_over = 1;
	if (open(TMP, O_CREAT | O_WRONLY | O_TRUNC, 0644) < 0)
		ft_exit_error(g, "Error while creating temporary file.");
	if (g->allocated.sound_track)
		ft_stop_sound_track(g);
	g->allocated.sound_track = 0;
	if (g->won)
		ft_play_sound_effect(g, g->sounds.won);
	else
		ft_play_sound_effect(g, g->sounds.lost);
}

int	ft_free_exit(t_game *g)
{
	ft_free_double_int(g->map.arr, (size_t) g->win.height);
	ft_free_double_int(g->quickfill.dc, (size_t) g->win.height);
	free(g->collectibles);
	free(g->enemies);
	if (open(TMP, O_CREAT | O_WRONLY | O_TRUNC, 0644) < 0)
		ft_exit_error(g, "Error while creating temporary file.");
	ft_stop_sound_track(g);
	unlink(TMP);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	ft_bzero(&g.allocated, sizeof(t_alloc));
	if (argc != 2)
		ft_exit_error(&g, "Usage: ./so_long [filename].ber");
	if (ft_check_and_init(&g, argv[1]))
		ft_exit_error(&g, g.exit_message);
	g.mlx = mlx_init();
	g.win.ref = mlx_new_window(g.mlx, g.win.width * PX + NPX,
			g.win.height * PX + NPX + 10, "My so_long :)");
	g.allocated.sound_track = 1;
	ft_play_sound_track(&g);
	mlx_hook(g.win.ref, ON_DESTROY, 0L, ft_free_exit, &g);
	mlx_key_hook(g.win.ref, ft_key_hook, &g);
	mlx_loop_hook(g.mlx, ft_render, &g);
	mlx_loop(g.mlx);
}
