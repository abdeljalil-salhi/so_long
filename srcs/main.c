/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:25:53 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/21 21:51:55 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_close_window(void)
{
	exit(0);
}

static int	ft_key_hook(int keycode, t_game *g)
{
	if (keycode == ESC)
		ft_close_window();
	else if (keycode == ARROW_LEFT || keycode == KEY_A)
		ft_move_player_left(g);
	else if (keycode == ARROW_RIGHT || keycode == KEY_D)
		ft_move_player_right(g);
	else if (keycode == ARROW_UP || keycode == KEY_W)
		ft_move_player_up(g);
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		ft_move_player_down(g);
	return (0);
}

int	ft_game_over(t_game *g)
{
	ft_printf("GAME OVER\n");
	ft_free_tab((void **)g->map.arr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		ft_exit_error("Usage: ./so_long [filename].ber");
	if (ft_check_and_init(&g, argv[1]))
		ft_exit_error(g.exit_message);
	g.mlx = mlx_init();
	g.win.ref = mlx_new_window(g.mlx, g.win.width * PX + 32,
			g.win.height * PX + 32, "My so_long :)");
	mlx_hook(g.win.ref, ON_DESTROY, 0L, ft_close_window, 0);
	mlx_key_hook(g.win.ref, ft_key_hook, &g);
	mlx_loop_hook(g.mlx, ft_render, &g);
	mlx_loop(g.mlx);
}
