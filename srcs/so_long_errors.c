/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:45:48 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/26 13:21:37 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_error(t_game *g, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	if (g->allocated.map)
		ft_free_double_int(g->map.arr, (size_t) g->win.height);
	if (g->allocated.collectibles)
		free(g->collectibles);
	if (g->allocated.enemies)
		free(g->enemies);
	ft_stop_sound_track(g);
	if (!access(TMP, R_OK))
		unlink(TMP);
	exit(1);
}

int	ft_error(t_game *g, char *str)
{
	g->exit_message = str;
	return (1);
}
