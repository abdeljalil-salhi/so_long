/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:25:53 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/17 04:00:21 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		ft_exit_error("Usage: ./so_long [filename].ber");
	if (ft_check_and_init(&g, argv[1]))
		ft_exit_error(g.exit_message);
	g.mlx = mlx_init();
	g.win.ref = mlx_new_window(g.mlx, g.win.width, g.win.height,
			"This is a test!");
	mlx_loop(g.mlx);
}
